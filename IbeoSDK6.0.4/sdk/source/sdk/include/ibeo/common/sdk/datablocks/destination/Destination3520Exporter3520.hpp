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
//!\date Sept 05, 2018
//------------------------------------------------------------------------------

#pragma once

//==============================================================================

#include <ibeo/common/sdk/misc/WinCompatibility.hpp>

#include <ibeo/common/sdk/datablocks/ExporterBase.hpp>
#include "Destination3520.hpp"

//==============================================================================
namespace ibeo {
namespace common {
namespace sdk {
//==============================================================================

template<>
class Exporter<Destination3520, DataTypeId::DataType_Destination3520>
  : public TypedExporter<Destination3520, DataTypeId::DataType_Destination3520>
{
public:
    std::streamsize getSerializedSize(const DataContainerBase& c) const override;

public:
    bool serialize(std::ostream& os, const DataContainerBase& c) const override;
}; //Destination3520

//==============================================================================

using Destination3520Exporter3520 = Exporter<Destination3520, DataTypeId::DataType_Destination3520>;

//==============================================================================
} // namespace sdk
} // namespace common
} // namespace ibeo
//==============================================================================
