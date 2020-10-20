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
//!\date Feb 19, 2018
//------------------------------------------------------------------------------

#pragma once

//==============================================================================

#include <ibeo/common/sdk/misc/WinCompatibility.hpp>

#include <ibeo/common/sdk/datablocks/commands/Command2010.hpp>

//==============================================================================
namespace ibeo {
namespace common {
namespace sdk {
//==============================================================================

//==============================================================================
//!\brief Base class for LUX commands
//!\date Feb 14, 2018
//------------------------------------------------------------------------------
class MiniLuxCommandCBase : public CommandCBase
{
public:
    MiniLuxCommandCBase(const CommandId commandId) : CommandCBase(commandId) {}
}; // MiniLuxCommandBase

//==============================================================================
//!\brief Template base class for LUX commands with given command id.
//!\date Feb 14, 2018
//!\tparam cId  Command id of the LUX command.
//------------------------------------------------------------------------------
template<CommandId::Id cId>
class MiniLuxCommandC : public MiniLuxCommandCBase
{
public:
    MiniLuxCommandC() : MiniLuxCommandCBase(cId) {}
}; // MiniLuxCommand<cId>

//==============================================================================
} // namespace sdk
} // namespace common
} // namespace ibeo
//==============================================================================
