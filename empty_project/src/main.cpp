#include "main.hpp"

#include <render_pipeline/rppanda/showbase/showbase.hpp>
#include <render_pipeline/rpcore/render_pipeline.hpp>

#include <crsf/RenderingEngine/TGraphicRenderEngine.h>

CRSEEDLIB_MODULE_CREATOR(EmptyProject);

// ************************************************************************************************
EmptyProject::EmptyProject(): crsf::TDynamicModuleInterface(CRMODULE_ID_STRING)
{
    rendering_engine_ = crsf::TGraphicRenderEngine::GetInstance();
    pipeline_ = rendering_engine_->GetRenderPipeline();
}

void EmptyProject::OnLoad()
{
    rendering_engine_->SetWindowTitle(CRMODULE_ID_STRING);
}

void EmptyProject::OnStart()
{
    // setup (mouse) controller
    rendering_engine_->EnableControl();
    rendering_engine_->SetControllerInitialPosHpr(
        LVecBase3(0, 0, 0),
        LVecBase3(0, 0, 0));
    rendering_engine_->ResetControllerInitial();

    setup_scene();

    pipeline_->get_showbase()->add_task([this](const rppanda::FunctionalTask* task) {
        update();
        return AsyncTask::DoneStatus::DS_cont;
    }, "EmptyProject::update");
}

void EmptyProject::OnExit()
{
}

void EmptyProject::setup_scene()
{
}

void EmptyProject::update()
{
}
