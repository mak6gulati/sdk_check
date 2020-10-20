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

#include <ibeo/common/sdk/datablocks/missionresponse/MissionResponse3540Importer3540.hpp>
#include <ibeo/common/sdk/ContainerBufferAndImporterProvider.hpp>

//==============================================================================

namespace {
using C  = ibeo::common::sdk::MissionResponse3540;
using R  = ibeo::common::sdk::RegisteredImporter<C, ibeo::common::sdk::DataTypeId::DataType_MissionResponse3540>;
using Id = ibeo::common::sdk::ImporterBase::ImporterRegisterId;
} // namespace

//==============================================================================
namespace ibeo {
namespace common {
namespace sdk {
//==============================================================================

template<>
const Id R::registeredImporterInitial
    = Id(std::make_pair(R::getDataTypeStatic(), C::getClassIdHashStatic()), R::create);

class IdcFile;
class IbeoEcu;

template<>
const Id R::registeredImporter = ContainerBufferAndImporterProviderGlobal<IdcFile>::getInstance().registerImporter(
    ContainerBufferAndImporterProviderGlobal<IbeoEcu>::getInstance().registerImporter(registeredImporterInitial));

//==============================================================================

std::streamsize
Importer<C, DataTypeId::DataType_MissionResponse3540>::getSerializedSize(const DataContainerBase& c) const
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

    std::streamsize result = std::streamsize(sizeof(uint64_t)) // m_timestamp
                             + std::streamsize(sizeof(uint8_t)) // m_response
                             + std::streamsize(sizeof(uint32_t)) // m_missionId
                             + std::streamsize(sizeof(uint32_t) * container->nbOfReserved); // reserved space

    return result;
}

//==============================================================================

bool Importer<C, DataTypeId::DataType_MissionResponse3540>::deserialize(std::istream& is,
                                                                        DataContainerBase& c,
                                                                        const IbeoDataHeader& dh) const
{
    C* container{nullptr};

    try
    {
        container = &dynamic_cast<C&>(c);
    }
    catch (const std::bad_cast&)
    {
        throw ContainerMismatch();
    }

    const int64_t startPos = streamposToInt64(is.tellg());
    readBE(is, container->m_timestamp);
    readBE<MissionResponse3540::Response, uint8_t>(is, container->m_response);
    readBE(is, container->m_missionId);

    for (auto& reserved : container->m_reserved)
    {
        readBE(is, reserved);
    }

    return !is.fail() && ((streamposToInt64(is.tellg()) - startPos) == this->getSerializedSize(c))
           && this->getSerializedSize(c) == dh.getMessageSize();
}

//==============================================================================
} // namespace sdk
} // namespace common
} // namespace ibeo
//==============================================================================
