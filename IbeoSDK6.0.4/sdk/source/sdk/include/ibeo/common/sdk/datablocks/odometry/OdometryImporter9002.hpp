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
//!\date Jan 29th, 2019
//------------------------------------------------------------------------------

//==============================================================================

#pragma once

//==============================================================================

#include <ibeo/common/sdk/misc/WinCompatibility.hpp>

#include <ibeo/common/sdk/datablocks/RegisteredImporter.hpp>
#include <ibeo/common/sdk/datablocks/odometry/Odometry.hpp>

//==============================================================================
namespace ibeo {
namespace common {
namespace sdk {
//==============================================================================

template<>
class Importer<Odometry, DataTypeId::DataType_Odometry9002>
  : public RegisteredImporter<Odometry, DataTypeId::DataType_Odometry9002>
{
public:
    Importer() : RegisteredImporter() {}

public:
    std::streamsize getSerializedSize(const DataContainerBase& c) const override;

    //========================================
    //!\brief convert data from source to target type (deserialization)
    //!\param[in, out] is      Input data stream
    //!\param[out]     c       Output container.
    //!\param[in]      header  Ibeo DataHeader
    //!\return \c true if serialization succeed, else: false
    //!\note This method is to be called from outside for deserialization.
    //----------------------------------------
    bool deserialize(std::istream& is, DataContainerBase& c, const IbeoDataHeader& header) const override;
}; //OdometryImporter9002

//==============================================================================

using OdometryImporter9002 = Importer<Odometry, DataTypeId::DataType_Odometry9002>;

//==============================================================================
} // namespace sdk
} // namespace common
} // namespace ibeo
//==============================================================================
