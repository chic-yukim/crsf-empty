/**
 * Coexistence Reality Software Framework (CRSF)
 * Copyright (c) Center of Human-centered Interaction for Coexistence. All rights reserved.
 * See the LICENSE.md file for more details.
 */

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
