#pragma once

#include <crsf/CRAPI/TDynamicModuleInterface.h>

class World;

class EmptyModule : public crsf::TDynamicModuleInterface
{
public:
    EmptyModule();

    void OnLoad() override;
    void OnStart() override;
    void OnExit() override;

private:
    std::unique_ptr<World> world_;
};
