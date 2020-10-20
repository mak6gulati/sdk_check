//==============================================================================
//!\file
//!
//!$$IBEO_LICENSE_BEGIN$$
//!Copyright (c) Ibeo Automotive Systems GmbH 2010-2019
//!All Rights Reserved.
//!
//!For more details, please refer to the accompanying file
//!IbeoLicense.txt.
//!$$IBEO_LICENSE_END$$
//!
//!\date Jun 2, 2016
//!
//!\example IbeoSdkScalaSimDemo.cpp Demo project for simulating a Scala device.
//------------------------------------------------------------------------------

#include <ibeo/common/sdk/lux.hpp>
#include <ibeo/common/sdk/ecu.hpp>
#include <ibeo/common/sdk/minilux.hpp>
#include <ibeo/common/sdk/scala.hpp>

#include <ibeo/common/sdk/devices/IdcFile.hpp>
#include <ibeo/common/sdk/devices/IbeoTcpIpAcceptorScala.hpp>

#include <iostream>
#include <cstdlib>

//==============================================================================

using namespace ibeo::common::sdk;

//==============================================================================

const std::string appName = "IbeoSdkScalaSimDemo";
IbeoSdk ibeoSdk;
ibeo::common::logging::LoggerSPtr appLogger = ibeo::common::logging::LogManager::getInstance().createLogger(appName);

//==============================================================================

TimeConversion tc;

//==============================================================================

class ScalaSim
{
public:
    ScalaSim(const std::string filename,
             const boost::asio::deadline_timer::duration_type writeExpirationTime,
             const unsigned short port = 12004);

public:
    void run();

protected:
    ibeo::common::sdk::IbeoTcpIpAcceptorScala m_acceptor;
    std::string m_idcFileName;
    IdcFile m_idcFile;
}; // ScalaSim

//==============================================================================

ScalaSim::ScalaSim(const std::string filename,
                   const boost::asio::deadline_timer::duration_type writeExpirationTime,
                   const unsigned short port)
  : m_acceptor(writeExpirationTime, port), m_idcFileName(filename), m_idcFile()
{
    m_acceptor.init();
}

//==============================================================================

void ScalaSim::run()
{
    m_idcFile.open(m_idcFileName);
    if (!m_idcFile.isOpen())
    {
        LOGERROR(appLogger, "Cannot open IDC file '" << m_idcFileName << "'");
        return;
    }

    while (!m_acceptor.hasSessions())
    {
#ifdef _WIN32
        ::Sleep(1);
#else // _WIN32
        sleep(1);
#endif // _WIN32
    }

    LOGINFO(appLogger, "Start sending");

    while (m_idcFile.isGood())
    {
        IbeoDataHeader dh;
        const auto body = m_idcFile.getNextDataBlockRaw(dh);

        if (body)
        {
            LOGTRACE(appLogger, "Send data block: " << toHex(dh.getDataType()) << "  Size: " << dh.getMessageSize());
            m_acceptor.sendRawDataBlock(dh, body.get());
        }
    } // while

    LOGINFO(appLogger, "Finished sending");
}

//==============================================================================
//==============================================================================
//==============================================================================

int checkArguments(const int argc, const char** argv, bool& hasLogFile)
{
    const int minNbOfNeededArguments = 2;
    const int maxNbOfNeededArguments = 3;

    bool wrongNbOfArguments = false;
    if (argc < minNbOfNeededArguments)
    {
        std::cerr << "Missing argument" << std::endl;
        wrongNbOfArguments = true;
    }
    else if (argc > maxNbOfNeededArguments)
    {
        std::cerr << "Too many argument" << std::endl;
        wrongNbOfArguments = true;
    }

    if (wrongNbOfArguments)
    {
        std::cerr << argv[0] << " "
                  << " INPUTFILENAME [LOGFILE]" << std::endl;
        std::cerr << "\tINPUTFILENAME Name of the file to use as input." << std::endl;
        std::cerr << "\tLOGFILE name of the log file (optional)." << std::endl;
        return 1;
    }

    hasLogFile = (argc == maxNbOfNeededArguments);
    return 0;
}

//==============================================================================

int main(const int argc, const char** argv)
{
    std::cerr << argv[0] << " (" << appName << ")"
              << " using IbeoSDK " << ibeoSdk.getVersion().toString() << std::endl;

    bool hasLogFile;
    const int checkResult = checkArguments(argc, argv, hasLogFile);
    if (checkResult != 0)
    {
        exit(checkResult);
    }
    int currArg = 1;

    std::string filename = argv[currArg++];

    if (hasLogFile)
    {
        ibeo::common::logging::FileLoggerBackendSPtr fileLoggerBackend
            = std::dynamic_pointer_cast<ibeo::common::logging::FileLoggerBackend>(
                ibeo::common::logging::LogManager::getInstance().getBackendById(
                    ibeo::common::logging::FileLoggerBackend::getBackendId()));
        fileLoggerBackend->setFilePath(argv[currArg++]);
    }

    ibeo::common::logging::LogManager::getInstance().setDefaultLogLevel("Debug");

    if (hasLogFile)
    {
        LOGINFO(appLogger,
                argv[0] << " (" << appName << ")"
                        << " using IbeoSDK " << ibeoSdk.getVersion().toString());
    }

    boost::asio::deadline_timer::duration_type writeExpirationTime(boost::posix_time::seconds(10));
    ScalaSim sim(filename, writeExpirationTime, 12004);
    sim.run();

    exit(0);
}

//==============================================================================
