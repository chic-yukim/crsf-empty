#pragma once

#include <render_pipeline/rppanda/showbase/direct_object.hpp>

#include <crsf/CRAPI/TDynamicModuleInterface.h>

namespace rpcore {
class RenderPipeline;
}

namespace crsf {
class TGraphicRenderEngine;
}

class MainApp : public crsf::TDynamicModuleInterface, public rppanda::DirectObject
{
public:
    MainApp();
    ~MainApp() override;

    void OnLoad() override;
    void OnStart() override;
    void OnExit() override;

private:
    friend class MainGUI;

    void setup_application();
    void update_per_frame();

    crsf::TGraphicRenderEngine* rendering_engine_;
    rpcore::RenderPipeline* pipeline_;
    std::unique_ptr<MainGUI> main_gui_;
};
