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
//!\date 02.November 2018
//------------------------------------------------------------------------------

#pragma once

//==============================================================================

#include <ibeo/common/sdk/misc/WinCompatibility.hpp>

#include <ibeo/common/sdk/datablocks/RegisteredImporter.hpp>

#include <ibeo/common/sdk/datablocks/missionhandling/MissionHandlingStatus3530.hpp>
#include <ibeo/common/sdk/DataTypeId.hpp>

//==============================================================================
namespace ibeo {
namespace common {
namespace sdk {
//==============================================================================

template<>
class Importer<MissionHandlingStatus3530, DataTypeId::DataType_MissionHandlingStatus3530>
  : public RegisteredImporter<MissionHandlingStatus3530, DataTypeId::DataType_MissionHandlingStatus3530>
{
public:
    Importer()                = default;
    Importer(const Importer&) = delete;
    Importer& operator=(const Importer&) = delete;

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
}; //MissionHandlingStatus3530Importer3530

//==============================================================================

using MissionHandlingStatus3530Importer3530
    = Importer<ibeo::common::sdk::MissionHandlingStatus3530, DataTypeId::DataType_MissionHandlingStatus3530>;

//==============================================================================
} // namespace sdk
} // namespace common
} // namespace ibeo
//==============================================================================
