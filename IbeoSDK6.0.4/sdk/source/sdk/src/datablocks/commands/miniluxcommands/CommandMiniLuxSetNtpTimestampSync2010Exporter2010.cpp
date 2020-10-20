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
//!\date Mar 1, 2018
//------------------------------------------------------------------------------

//==============================================================================

#include <ibeo/common/sdk/datablocks/commands/miniluxcommands/CommandMiniLuxSetNtpTimestampSync2010Exporter2010.hpp>

//==============================================================================
namespace {
//==============================================================================
using S  = ibeo::common::sdk::CommandMiniLuxSetNtpTimestampSyncC;
using B  = S::CommonBase;
using KT = B::KeyType;
//==============================================================================
} // namespace
//==============================================================================

//==============================================================================
namespace ibeo {
namespace common {
namespace sdk {
//==============================================================================

//==============================================================================

std::streamsize SpecialExporter<S>::getSerializedSize(const B& s) const
{
    try
    {
        (void)dynamic_cast<const S&>(s);
    }
    catch (const std::bad_cast&)
    {
        throw ContainerMismatch();
    }

    return commandSize;
}

//==============================================================================

bool SpecialExporter<S>::serialize(std::ostream& os, const B& s) const
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

    const int64_t startPos = streamposToInt64(os.tellp());

    writeLE(os, specialType->m_commandId);
    writeLE(os, specialType->m_reserved0);
    writeLE(os, specialType->m_reserved1);
    // cannot use writeLE or writeBE here since the long words
    // are in BE order and the seconds and fracs are in LE order
    // internally.
    writeLE(os, specialType->m_timestamp.getSeconds());
    writeLE(os, specialType->m_timestamp.getFracSeconds());

    return !os.fail() && ((streamposToInt64(os.tellp()) - startPos) == this->getSerializedSize(*specialType));
}

//==============================================================================
} // namespace sdk
} // namespace common
} // namespace ibeo
//==============================================================================
