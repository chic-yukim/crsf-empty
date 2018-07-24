#pragma once

#include <crsf/CRAPI/TDynamicModuleInterface.h>

class EmptyModule: public crsf::TDynamicModuleInterface
{
public:
    EmptyModule();

    void OnLoad() override;
    void OnStart() override;
    void OnExit() override;
};
