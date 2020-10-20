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
//!\date Mar 14, 2018
//------------------------------------------------------------------------------

//==============================================================================

#include <ibeo/common/sdk/datablocks/logmessages/LogMessageNote6420Exporter6420.hpp>

//==============================================================================
namespace {
using C = ibeo::common::sdk::LogMessageNote6420;
} // namespace
//==============================================================================

//==============================================================================
namespace ibeo {
namespace common {
namespace sdk {
//==============================================================================

std::streamsize Exporter<C, DataTypeId::DataType_LogNote6420>::getSerializedSize(const DataContainerBase& c) const
{
    const C* container{nullptr};
    try
    {
        container = &dynamic_cast<const C&>(c); // ignore the return value
    }
    catch (const std::bad_cast&)
    {
        throw ContainerMismatch();
    }

    return LogMessage64x0Exporter64x0Base<C>::getSerializedSize(container);
}

//==============================================================================

bool Exporter<C, DataTypeId::DataType_LogNote6420>::serialize(std::ostream& os, const DataContainerBase& c) const
{
    const C* container{nullptr};
    try
    {
        container = &dynamic_cast<const C&>(c);
    }
    catch (const std::bad_cast&)
    {
        throw ContainerMismatch();
    }

    return LogMessage64x0Exporter64x0Base<C>::serialize(os, container);
}

//==============================================================================
} // namespace sdk
} // namespace common
} // namespace ibeo
//==============================================================================
