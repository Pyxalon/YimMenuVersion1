#include "views/view.hpp"

namespace big
{
    void view::recovery()
    {
        ImGui::SeparatorText("GENERAL");
        ImGui::BeginGroup();

        components::command_button<"goodbehaviorbonus">();

        ImGui::EndGroup();
        ImGui::SeparatorText("UNLOCKS");
        ImGui::BeginGroup();

        components::command_button<"unlockachievements">();

        ImGui::EndGroup();
    }
}
