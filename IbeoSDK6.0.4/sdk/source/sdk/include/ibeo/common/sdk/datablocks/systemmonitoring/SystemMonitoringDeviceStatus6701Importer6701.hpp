//==============================================================================
//! \file
//!
//!$$IBEO_LICENSE_BEGIN$$
//!Copyright (c) Ibeo Automotive Systems GmbH 2010-2019
//!All Rights Reserved.
//!
//!For more details, please refer to the accompanying file
//!IbeoLicense.txt.
//!$$IBEO_LICENSE_END$$
//!
//!\date Jan 16, 2018
//------------------------------------------------------------------------------

#pragma once

//==============================================================================

#include <ibeo/common/sdk/misc/WinCompatibility.hpp>

#include <ibeo/common/sdk/datablocks/RegisteredImporter.hpp>
#include <ibeo/common/sdk/datablocks/systemmonitoring/SystemMonitoringDeviceStatus6701.hpp>

//==============================================================================
namespace ibeo {
namespace common {
namespace sdk {
//==============================================================================

template<>
class Importer<SystemMonitoringDeviceStatus6701, DataTypeId::DataType_SystemMonitoringDeviceStatus6701>
  : public RegisteredImporter<SystemMonitoringDeviceStatus6701, DataTypeId::DataType_SystemMonitoringDeviceStatus6701>
{
public:
    constexpr static const std::streamsize serializedSize{std::streamsize(
        sizeof(uint8_t) + sizeof(uint8_t) + sizeof(uint8_t) + sizeof(uint8_t) + sizeof(uint8_t) + sizeof(uint64_t))};

public:
    Importer() : RegisteredImporter() {}
    Importer(const Importer&) = delete;
    Importer& operator=(const Importer&) = delete;

public:
    virtual std::streamsize getSerializedSize(const DataContainerBase& c) const override;

    //========================================
    //!\brief convert data from source to target type (deserialization)
    //!\param[in, out] is      Input data stream
    //!\param[out]     c       Output container.
    //!\param[in]      header  Ibeo DataHeader
    //!\return \c true if serialization succeed, else: false
    //!\note This method is to be called from outside for deserialization.
    //----------------------------------------
    virtual bool deserialize(std::istream& is, DataContainerBase& c, const IbeoDataHeader& header) const override;
}; //SystemMonitoringDeviceStatus6701Importer6701

//==============================================================================

using SystemMonitoringDeviceStatus6701Importer6701 = Importer<ibeo::common::sdk::SystemMonitoringDeviceStatus6701,
                                                              DataTypeId::DataType_SystemMonitoringDeviceStatus6701>;

//==============================================================================
} // namespace sdk
} // namespace common
} // namespace ibeo
//==============================================================================
