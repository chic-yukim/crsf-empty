/**
 * Coexistence Reality Software Framework (CRSF)
 * Copyright (c) Center of Human-centered Interaction for Coexistence. All rights reserved.
 * See the LICENSE.md file for more details.
 */

#include "empty_module/empty_module.h"

#include <boost/dll/alias.hpp>

#include <spdlog/spdlog.h>

CRSEEDLIB_MODULE_CREATOR(EmptyModule)

// ************************************************************************************************
EmptyModule::EmptyModule(): crsf::TDynamicModuleInterface(CRMODULE_ID_STRING)
{
}

void EmptyModule::OnLoad()
{
    m_logger->trace("Module ({}) is loading.", GetModuleInfo().name);
}

void EmptyModule::OnStart()
{
    m_logger->trace("Module ({}) is starting.", GetModuleInfo().name);
}

void EmptyModule::OnExit()
{
    m_logger->trace("Module ({}) is exiting.", GetModuleInfo().name);
}
