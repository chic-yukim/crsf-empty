#include "main_gui/main_gui.hpp"

#include <imgui.h>

#include <fmt/format.h>
#include <spdlog/logger.h>

#include <render_pipeline/rppanda/showbase/showbase.hpp>
#include <render_pipeline/rpcore/render_pipeline.hpp>
#include <render_pipeline/rpcore/util/primitives.hpp>
#include <render_pipeline/rpcore/globals.hpp>

#include "main.hpp"

MainGUI::MainGUI(MainApp& app) : app_(app)
{
    rppanda::Messenger::get_global_instance()->send(
        "imgui-setup-context",
        EventParameter(new rppanda::FunctionalTask([this](rppanda::FunctionalTask* task) {
            ImGui::SetCurrentContext(std::static_pointer_cast<ImGuiContext>(task->get_user_data()).get());
            accept("imgui-new-frame", [this](const Event*) { on_imgui_new_frame(); });
            return AsyncTask::DS_done;
        }, "MainApp::setup-imgui"))
    );
}

MainGUI::~MainGUI() = default;

void MainGUI::on_imgui_new_frame()
{
    static bool window = true;

    ImGui::Begin(app_.GetModuleInfo().name.c_str(), &window);

    ImGui::Text("This is empty project");

    if (ImGui::Button("Empty Button"))
    {
        app_.m_logger->info("Empty Button is clicked!");
    }

    ImGui::End();
}
