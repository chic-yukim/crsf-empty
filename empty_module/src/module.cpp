#include "empty_module/module.h"

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
