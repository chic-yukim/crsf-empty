#pragma once

namespace rpcore {
class RenderPipeline;
}

namespace crsf {
class TGraphicRenderEngine;
}

class World
{
public:
    World();

    void setup_scene();
    void update();

private:
    crsf::TGraphicRenderEngine* rendering_engine_;
    rpcore::RenderPipeline* pipeline_;
};
