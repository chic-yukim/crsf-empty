#include "main.hpp"
#include "world.hpp"

CRSEEDLIB_MODULE_CREATOR(EmptyModule);

// ************************************************************************************************
EmptyModule::EmptyModule(): crsf::TDynamicModuleInterface(CRMODULE_ID_STRING)
{
}

void EmptyModule::OnLoad()
{
}

void EmptyModule::OnStart()
{
    world_ = std::make_unique<World>();
}

void EmptyModule::OnExit()
{
    world_.reset();
}
