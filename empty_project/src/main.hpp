#pragma once

#include <crsf/CRAPI/TDynamicModuleInterface.h>

namespace rpcore {
class RenderPipeline;
}

namespace crsf {
class TGraphicRenderEngine;
}

class EmptyProject : public crsf::TDynamicModuleInterface
{
public:
    EmptyProject();

    void OnLoad() override;
    void OnStart() override;
    void OnExit() override;

private:
    void setup_scene();
    void update();

    crsf::TGraphicRenderEngine* rendering_engine_;
    rpcore::RenderPipeline* pipeline_;
};
