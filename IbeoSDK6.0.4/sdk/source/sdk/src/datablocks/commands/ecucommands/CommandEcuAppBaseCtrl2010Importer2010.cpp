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
//!\date Feb 13, 2018
//------------------------------------------------------------------------------

#include <ibeo/common/sdk/datablocks/commands/ecucommands/CommandEcuAppBaseCtrl2010Importer2010.hpp>

#include <ibeo/common/sdk/BufferAndImporterProvider.hpp>

//==============================================================================
namespace {
//==============================================================================
using C  = ibeo::common::sdk::Command2010;
using S  = ibeo::common::sdk::CommandEcuAppBaseCtrlC;
using R  = ibeo::common::sdk::SpecialRegisteredImporter<C, ibeo::common::sdk::DataTypeId::DataType_Command2010, S>;
using Id = ibeo::common::sdk::SpecialImporterBase<S::CommonBase>::ImporterRegisterId;
using KT = S::CommonBase::KeyType;
//==============================================================================
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
const Id R::registeredImporterInitial(std::make_pair(KT{S::key}, S::getClassIdHashStatic()), R::create);

//registering ... (create map)
//

//register listener types
template<>
const Id R::registeredImporter
    = BufferAndImporterProviderGlobal<S::CommonBase>::getInstance().registerImporter(registeredImporterInitial);

//==============================================================================
//==============================================================================
//==============================================================================

static void readBE(std::istream& is, S::AppBaseCtrlId& ctrId)
{
    uint16_t tmp{0};
    readBE(is, tmp);
    ctrId = S::AppBaseCtrlId(tmp);
}

//==============================================================================
//==============================================================================
//==============================================================================

std::streamsize SpecialImporter<C, DataTypeId::DataType_Command2010, S>::getSerializedSize(const CommandCBase& s) const
{
    const S* specialType{nullptr};

    try
    {
        specialType = &dynamic_cast<const S&>(s);
    }
    catch (const std::bad_cast&)
    {
        throw ContainerMismatch();
    }

    return static_cast<std::streamsize>(commandBaseSize + specialType->getData().size());
}

//==============================================================================

bool SpecialImporter<C, DataTypeId::DataType_Command2010, S>::deserialize(std::istream& is,
                                                                          CommandCBase& s,
                                                                          const IbeoDataHeader& dh) const
{
    S* specialType{nullptr};

    try
    {
        specialType = &dynamic_cast<S&>(s);
    }
    catch (const std::bad_cast&)
    {
        throw ContainerMismatch();
    }

    const int64_t startPos = streamposToInt64(is.tellg());

    readBE(is, specialType->m_commandId);
    if (S::key != specialType->m_commandId)
    {
        return false;
    }

    readBE(is, specialType->m_ctrlId);

    is.unsetf(std::ios::skipws);
    std::istreambuf_iterator<char> eos;
    std::string str(std::istreambuf_iterator<char>(is), eos);
    is.setf(std::ios::skipws);
    specialType->m_data = str;

    return !is.fail() && ((streamposToInt64(is.tellg()) - startPos) == this->getSerializedSize(*specialType))
           && this->getSerializedSize(*specialType) == dh.getMessageSize();
}

//==============================================================================
} // namespace sdk
} // namespace common
} // namespace ibeo
//==============================================================================
