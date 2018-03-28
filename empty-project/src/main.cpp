#include "main.hpp"
#include "world.hpp"

CRSEEDLIB_MODULE_CREATOR(EmptyModule);

// ************************************************************************************************
EmptyModule::EmptyModule(void): crsf::TDynamicModuleInterface(CRMODULE_ID_STRING)
{
}

void EmptyModule::OnLoad(void)
{
}

void EmptyModule::OnStart(void)
{
    world_ = std::make_unique<World>();
}

void EmptyModule::OnExit(void)
{
}
