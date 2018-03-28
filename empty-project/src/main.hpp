#pragma once

#include <crsf/CRAPI/TDynamicModuleInterface.h>

class World;

class EmptyModule : public crsf::TDynamicModuleInterface
{
public:
    EmptyModule(void);

    void OnLoad(void) override;
    void OnStart(void) override;
    void OnExit(void) override;

private:
    std::unique_ptr<World> world_;
};
