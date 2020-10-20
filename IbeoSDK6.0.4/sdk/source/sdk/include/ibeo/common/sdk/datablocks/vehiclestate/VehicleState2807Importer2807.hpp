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
//!\date Jan 19, 2018
//------------------------------------------------------------------------------

#pragma once

//==============================================================================

#include <ibeo/common/sdk/misc/WinCompatibility.hpp>

#include <ibeo/common/sdk/datablocks/RegisteredImporter.hpp>
#include <ibeo/common/sdk/datablocks/vehiclestate/VehicleState2807.hpp>

//==============================================================================
namespace ibeo {
namespace common {
namespace sdk {
//==============================================================================

template<>
class Importer<VehicleState2807, DataTypeId::DataType_VehicleStateBasic2807>
  : public RegisteredImporter<VehicleState2807, DataTypeId::DataType_VehicleStateBasic2807>
{
public:
    constexpr static std::streamsize serializedSize{90};

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
}; // VehicleState2807Importer2807

//==============================================================================

using VehicleState2807Importer2807 = Importer<VehicleState2807, DataTypeId::DataType_VehicleStateBasic2807>;

//==============================================================================
} // namespace sdk
} // namespace common
} // namespace ibeo
//==============================================================================
