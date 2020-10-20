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
//!\date Jan 25, 2018
//------------------------------------------------------------------------------

#pragma once

//==============================================================================

#include <ibeo/common/sdk/misc/WinCompatibility.hpp>

#include "common/TestSupport.hpp"

#include <ibeo/common/sdk/datablocks/devicestatus/special/DeviceStatus6303.hpp>

#include <boost/iostreams/stream.hpp>

//==============================================================================
namespace ibeo {
namespace common {
namespace sdk {
namespace unittests {
//==============================================================================

class UserDefinedStructDummy1 : public DeviceStatus6303::UserDefinedStructBase
{
public:
    UserDefinedStructDummy1()
      : DeviceStatus6303::UserDefinedStructBase{DeviceStatus6303::ContentId::Dummy1},
        m_u{TestSupport::getRandValue<uint8_t>()}
    {}

    virtual ~UserDefinedStructDummy1() {}

public:
    //========================================
    virtual bool deserialize(const DeviceStatus6303::ContentDescr& cd)
    {
        if (cd.getContentId() != DeviceStatus6303::ContentId::Dummy1)
        {
            return false;
        }

        boost::iostreams::stream<boost::iostreams::array_source> is(cd.getContentBuffer(), cd.getSerializedSize());
        readBE(is, m_u);
        return true;
    }

    //========================================
    virtual bool serialize(char*& buf) const
    {
        boost::iostreams::stream<boost::iostreams::array> strm((char*)(buf), getSerializedSize());
        std::ostream& os = (std::ostream&)strm;

        writeBE(os, m_u);
        buf += getSerializedSize();

        return true;
    }

    //========================================
    virtual uint8_t getSerializedSize() const { return sizeof(uint8_t); }

protected:
    uint8_t m_u;
}; // UserDefinedStructDummy1

//==============================================================================
} // namespace unittests
} // namespace sdk
} // namespace common
} // namespace ibeo
//==============================================================================
