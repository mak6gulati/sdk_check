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

#include <ibeo/common/sdk/ContainerBufferAndImporterProvider.hpp>

#include <ibeo/common/sdk/datablocks/odometry/special/Odometry9002Importer9002.hpp>
#include <ibeo/common/sdk/datablocks/odometry/OdometryImporter9002.hpp>

//==============================================================================
namespace {
using C  = ibeo::common::sdk::Odometry;
using R  = ibeo::common::sdk::RegisteredImporter<C, ibeo::common::sdk::DataTypeId::DataType_Odometry9002>;
using Id = ibeo::common::sdk::ImporterBase::ImporterRegisterId;
} // namespace
//==============================================================================

//==============================================================================
namespace ibeo {
namespace common {
namespace sdk {
//==============================================================================
// Specializations for RegisteredImporter
//==============================================================================

//generate link between data-type-id/importer and importer create function <dtid, ImpHash> ==> Imp::create

template<>
const Id R::registeredImporterInitial
    = Id(std::make_pair(R::getDataTypeStatic(), C::getClassIdHashStatic()), R::create);

//registering ... (create map)
//add all device that can receive any datatype that can be imported to GeneralDataTypeContainer
class IdcFile;
class IbeoEcu;

// basically R::registeredImporter = R::registeredImporterInitial
// but on its way it will be added to all mentioned RegisteredImporterGlobal maps
// through which registerImporter method it has been piped through.
// RegisteredImporterGlobal is a singleton for each device.
template<>
const Id R::registeredImporter = ContainerBufferAndImporterProviderGlobal<IdcFile>::getInstance().registerImporter(
    ContainerBufferAndImporterProviderGlobal<IbeoEcu>::getInstance().registerImporter(registeredImporterInitial));

//==============================================================================

//==============================================================================

std::streamsize Importer<C, DataTypeId::DataType_Odometry9002>::getSerializedSize(const DataContainerBase& c) const
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

    const Odometry9002Importer9002 delegate;
    return delegate.getSerializedSize(container->m_delegate);
}

//==============================================================================

bool Importer<C, DataTypeId::DataType_Odometry9002>::deserialize(std::istream& is,
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

    const Odometry9002Importer9002 delegate;
    return delegate.deserialize(is, container->m_delegate, dh);
}

//==============================================================================
} // namespace sdk
} // namespace common
} // namespace ibeo
//==============================================================================
