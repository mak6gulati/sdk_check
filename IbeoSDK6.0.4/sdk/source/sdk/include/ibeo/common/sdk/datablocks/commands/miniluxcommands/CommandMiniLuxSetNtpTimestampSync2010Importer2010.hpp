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
//!\date Feb 19, 2018
//------------------------------------------------------------------------------

#pragma once

//==============================================================================

#include <ibeo/common/sdk/misc/WinCompatibility.hpp>

#include <ibeo/common/sdk/datablocks/SpecialRegisteredImporter.hpp>
#include <ibeo/common/sdk/datablocks/commands/miniluxcommands/CommandMiniLuxSetNtpTimestampSyncC.hpp>

//==============================================================================
namespace ibeo {
namespace common {
namespace sdk {
//==============================================================================

template<>
class SpecialImporter<Command2010, DataTypeId::DataType_Command2010, CommandMiniLuxSetNtpTimestampSyncC>
  : public SpecialRegisteredImporter<Command2010, DataTypeId::DataType_Command2010, CommandMiniLuxSetNtpTimestampSyncC>
{
public:
    static constexpr int commandSize{14};

public:
    SpecialImporter()
      : SpecialRegisteredImporter<Command2010, DataTypeId::DataType_Command2010, CommandMiniLuxSetNtpTimestampSyncC>()
    {}
    SpecialImporter(const SpecialImporter&) = delete;
    SpecialImporter& operator=(const SpecialImporter&) = delete;

public:
    virtual std::streamsize getSerializedSize(const CommandCBase& s) const override;

    //========================================
    //!\brief convert data from source to target type (deserialization)
    //!\param[in, out] is      Input data stream
    //!\param[out]     c       Output container.
    //!\param[in]      header  Ibeo DataHeader
    //!\return \c true if serialization succeed, else: false
    //!\note This method is to be called from outside for deserialization.
    //----------------------------------------
    virtual bool deserialize(std::istream& is, CommandCBase& s, const IbeoDataHeader& header) const override;
}; // CommandMiniLuxSetNtpTimestampSync2010Importer2010

//==============================================================================

using CommandMiniLuxSetNtpTimestampSync2010Importer2010
    = SpecialImporter<Command2010, DataTypeId::DataType_Command2010, CommandMiniLuxSetNtpTimestampSyncC>;

//==============================================================================
} // namespace sdk
} // namespace common
} // namespace ibeo
//==============================================================================
