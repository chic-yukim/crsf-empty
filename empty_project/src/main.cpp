#include "main.hpp"

#include <render_pipeline/rppanda/showbase/showbase.hpp>
#include <render_pipeline/rpcore/render_pipeline.hpp>

#include <crsf/RenderingEngine/TGraphicRenderEngine.h>

#include "main_gui/main_gui.hpp"

CRSEEDLIB_MODULE_CREATOR(MainApp);

// ************************************************************************************************
MainApp::MainApp(): crsf::TDynamicModuleInterface(CRMODULE_ID_STRING)
{
    rendering_engine_ = crsf::TGraphicRenderEngine::GetInstance();
    pipeline_ = rendering_engine_->GetRenderPipeline();
}

MainApp::~MainApp()
{
}

void MainApp::OnLoad()
{
    rendering_engine_->SetWindowTitle(CRMODULE_ID_STRING);
}

void MainApp::OnStart()
{
    // setup (mouse) controller
    rendering_engine_->EnableControl();
    rendering_engine_->SetControllerInitialPosHpr(
        LVecBase3(0, 0, 0),
        LVecBase3f(0, 0, 0));
    rendering_engine_->ResetControllerInitial();

    setup_application();

    main_gui_ = std::make_unique<MainGUI>(*this);

    add_task([this](const rppanda::FunctionalTask* task) {
        update_per_frame();
        return AsyncTask::DoneStatus::DS_cont;
    }, "MainApp::update_per_frame");
}

void MainApp::OnExit()
{
    remove_all_tasks();
    ignore_all();

    main_gui_.reset();
}

void MainApp::setup_application()
{
}

void MainApp::update_per_frame()
{
}
