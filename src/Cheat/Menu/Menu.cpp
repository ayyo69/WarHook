#include "Menu.h"
#include "../Utils/Memory.h"
#include "../Config/Config.h"

bool menu::agree = false;
bool menu::open = true;
bool menu::tab_esp = false;
bool menu::tab_misc = false;
bool menu::tab_support = false;
bool menu::def_tab = true;
bool menu::def_choice = false;
ImVec2 menu::sizeScr = ImVec2(0, 0);
ImFont* menu::def_main = nullptr;
ImFont* menu::med_main = nullptr;
ImFont* menu::big_main = nullptr;
ImFont* menu::icons = nullptr;

void menu::SetupImGuiStyle()
{
	ImGui::GetStyle().FrameRounding = 6.f;
	ImGui::GetStyle().WindowBorderSize = 0.f;
	ImGui::GetStyle().ChildBorderSize = 0.f;
	ImGui::GetStyle().WindowTitleAlign.x = 0.5f;
	ImGui::GetStyle().WindowTitleAlign.y = 0.4f;
	ImGui::GetStyle().TabRounding = 0.f;
	ImGui::GetStyle().WindowPadding.x = 0.f;


	ImVec4* colors = ImGui::GetStyle().Colors;
	colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
	colors[ImGuiCol_WindowBg] = ImVec4(0.09f, 0.07f, 0.11f, 1.00f);
	colors[ImGuiCol_ChildBg] = ImVec4(0.09f, 0.07f, 0.11f, 1.00f);
	colors[ImGuiCol_PopupBg] = ImVec4(0.09f, 0.07f, 0.11f, 1.00f);
	colors[ImGuiCol_Border] = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
	colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_FrameBg] = ImVec4(0.17f, 0.14f, 0.22f, 0.00f);
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.17f, 0.14f, 0.22f, 0.72f);
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.17f, 0.14f, 0.22f, 1.00f);
	colors[ImGuiCol_TitleBg] = ImVec4(0.31f, 0.15f, 0.31f, 1.00f);
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.31f, 0.15f, 0.31f, 1.00f);
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.31f, 0.15f, 0.31f, 1.00f);
	colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
	colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
	colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
	colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
	colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
	colors[ImGuiCol_CheckMark] = ImVec4(0.49f, 0.10f, 0.51f, 1.00f);
	colors[ImGuiCol_SliderGrab] = ImVec4(0.49f, 0.10f, 0.51f, 1.00f);
	colors[ImGuiCol_SliderGrabActive] = ImVec4(0.79f, 0.15f, 0.81f, 1.00f);
	colors[ImGuiCol_Button] = ImVec4(0.49f, 0.10f, 0.51f, 1.00f);
	colors[ImGuiCol_ButtonHovered] = ImVec4(0.79f, 0.15f, 0.81f, 0.79f);
	colors[ImGuiCol_ButtonActive] = ImVec4(0.79f, 0.15f, 0.81f, 1.00f);
	colors[ImGuiCol_Header] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	colors[ImGuiCol_HeaderHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.00f);
	colors[ImGuiCol_HeaderActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.02f);
	colors[ImGuiCol_Separator] = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
	colors[ImGuiCol_SeparatorHovered] = ImVec4(0.10f, 0.40f, 0.75f, 0.00f);
	colors[ImGuiCol_SeparatorActive] = ImVec4(0.10f, 0.40f, 0.75f, 0.00f);
	colors[ImGuiCol_ResizeGrip] = ImVec4(0.26f, 0.59f, 0.98f, 0.25f);
	colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
	colors[ImGuiCol_ResizeGripActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
	colors[ImGuiCol_Tab] = ImVec4(0.49f, 0.10f, 0.51f, 1.00f);
	colors[ImGuiCol_TabHovered] = ImVec4(0.79f, 0.15f, 0.81f, 0.78f);
	colors[ImGuiCol_TabActive] = ImVec4(0.79f, 0.15f, 0.81f, 1.00f);
	colors[ImGuiCol_TabUnfocused] = ImVec4(0.07f, 0.10f, 0.15f, 0.97f);
	colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.14f, 0.26f, 0.42f, 1.00f);
	colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
	colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
	colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
	colors[ImGuiCol_TableHeaderBg] = ImVec4(0.19f, 0.19f, 0.20f, 1.00f);
	colors[ImGuiCol_TableBorderStrong] = ImVec4(0.31f, 0.31f, 0.35f, 1.00f);
	colors[ImGuiCol_TableBorderLight] = ImVec4(0.23f, 0.23f, 0.25f, 1.00f);
	colors[ImGuiCol_TableRowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.00f, 1.00f, 1.00f, 0.06f);
	colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
	colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
	colors[ImGuiCol_NavHighlight] = ImVec4(0.26f, 0.59f, 0.98f, 0.00f);
	colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
	colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
	colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);

}

void menu::showWarningwindow()
{
	auto text1 = "THIS SOFTWARE DISTRIBUTED FOR FREE.";
	auto text2 = "IF YOU PAID FOR THIS SOFTWARE - YOU GOT SCAMMED.";
	auto text3 = "Change click handle in \"Other\" tab (Block user input)";
	ImGui::SetNextWindowSize({ memory::scrsize.x, memory::scrsize.y });
	ImGui::SetNextWindowPos({ 0, 0 });
	auto flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar;
	ImGui::Begin("WARNING", nullptr, flags);
	ImGui::PushFont(big_main);
	auto textWidth1 = ImGui::CalcTextSize(text1).x;
	ImGui::SetCursorPos(ImVec2((memory::scrsize.x - textWidth1) * 0.5f, 100));
	ImGui::Text(text1);
	auto textWidth2 = ImGui::CalcTextSize(text2).x;
	ImGui::SetCursorPosX((memory::scrsize.x - textWidth2) * 0.5f);
	ImGui::Text(text2);
	ImGui::SetCursorPosX((memory::scrsize.x - 225) * 0.5f);
	auto textWidth3 = ImGui::CalcTextSize(text3).x;
	ImGui::SetCursorPosX((memory::scrsize.x - textWidth3) * 0.5f);
	ImGui::Text(text3);
	ImGui::SetCursorPosX((memory::scrsize.x - 225) * 0.5f);
	ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 1.f);
	ImGui::Checkbox("I understood that", &agree);
	ImGui::PopStyleVar();
	ImGui::PopFont();
	ImGui::End();
}

void menu::showMenu() {
	
	ImGui::PushFont(med_main);
	ImGui::SetNextWindowSize({ 550,350 });
	ImGui::SetNextWindowPos({ (memory::scrsize.x - 550) * 0.5f, (memory::scrsize.y - 350) * 0.5f }, ImGuiCond_FirstUseEver);
	ImGui::Begin("WarHook Modified", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize);

	ImGui::BeginTabBar("main");
	ImGui::SetNextItemWidth(180.f);
	if (ImGui::BeginTabItem("\t\t\t\tESP", &tab_esp, ImGuiTabItemFlags_NoCloseButton))
	{

		ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 1.f);
		ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, { 4,5 });
		ImGui::SetCursorPosX(5.f);
		ImGui::Checkbox("Enabled", &cfg::esp_status);
		ImGui::SetCursorPosX(5.f);
		ImGui::Checkbox("Show reload bar", &cfg::show_reload);
		ImGui::SetCursorPosX(5.f);
		ImGui::Checkbox("Show bots", &cfg::show_bots);
		ImGui::SetCursorPosX(5.f);
		ImGui::Checkbox("Show planes", &cfg::show_planes);
		ImGui::SetCursorPosX(5.f);
		ImGui::Checkbox("Show bombs", &cfg::show_bombs);
		if (cfg::show_bombs) {
			ImGui::SameLine();
			ImGui::RadioButton("Icon##0", &cfg::Bout_type, 0);
			ImGui::SameLine();
			ImGui::RadioButton("Text##0", &cfg::Bout_type, 1);
		}
		ImGui::SetCursorPosX(5.f);
		ImGui::Checkbox("Show rockets", &cfg::show_rockets);
		if (cfg::show_rockets) {
			ImGui::SameLine();
			ImGui::RadioButton("Icon##1", &cfg::Mout_type, 0);
			ImGui::SameLine();
			ImGui::RadioButton("Text##1", &cfg::Mout_type, 1);
		}
		ImGui::SetCursorPosX(5.f);
		ImGui::Checkbox("Remove smokes", &cfg::remove_smokes);
		ImGui::SetCursorPosX(5.f);
		ImGui::Checkbox("Show offscreen arrows", &cfg::show_offscreen);
		if (cfg::show_offscreen)
		{
			ImGui::SameLine();
			ImGui::ColorEdit3("Arrow color", cfg::off_color, ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_NoOptions | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
			ImGui::Indent();
			ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 1.f);
			ImGui::SliderFloat("Arrow size", &cfg::off_arrow_size, 0.0f, 3.f);
			ImGui::SliderFloat("Radius", &cfg::off_radius, 0.0f, 1000.0f);
			ImGui::PopStyleVar();
		}
		ImGui::PopStyleVar(2);
		ImGui::EndTabItem();
	}

	ImGui::SetNextItemWidth(180.f);
	if (ImGui::BeginTabItem("\t\t\t\tMisc", &tab_misc, ImGuiTabItemFlags_NoCloseButton))
	{
		ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 1.f);
		ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, { 4,5 });
		ImGui::SetCursorPosX(5.f);
		ImGui::Checkbox("Zoom modification", &cfg::zoom_mod);
		ImGui::SetCursorPosX(5.f);
		ImGui::Text("Zoom multiplayer");
		ImGui::SetCursorPosX(5.f);
		ImGui::SliderFloat("##zoom", &cfg::zoom_mult, 1.0f, 100.0f);
		ImGui::SetCursorPosX(5.f);
		ImGui::Text("Alternate multiplayer");
		ImGui::SetCursorPosX(5.f);
		ImGui::SliderFloat("##alt", &cfg::alt_mult, 1.0f, 100.0f);
		ImGui::SetCursorPosX(5.f);
		ImGui::Text("Shadow zoom multiplayer");
		ImGui::SetCursorPosX(5.f);
		ImGui::SliderFloat("##shadow", &cfg::shadow_mult, 20.0f, 250.0f);
		ImGui::SetCursorPosX(5.f);
		ImGui::Checkbox("Change HUD", &cfg::change_hud);
		/*if (change_hud)
		{
			ImGui::SetCursorPosX(5.f);
			ImGui::Checkbox("Enable bomb crosshair", &force_bombsight);
			ImGui::SetCursorPosX(5.f);
			ImGui::Checkbox("Enable Air-To_air indicator", &force_air_to_air);
			ImGui::SetCursorPosX(5.f);
			ImGui::Checkbox("Enable enemy outline (when hovered)", &force_outline);
			ImGui::SetCursorPosX(5.f);
			ImGui::Checkbox("Show distance in scope", &force_distance);
			ImGui::SetCursorPosX(5.f);
			ImGui::Checkbox("Show penetrarion indicator", &force_crosshair);
		}
		*/
		
		ImGui::PopStyleVar(2);
		ImGui::EndTabItem();

	}
	ImGui::SetNextItemWidth(180.f);
	if (ImGui::BeginTabItem("\t\t\tOther", &tab_support, ImGuiTabItemFlags_NoCloseButton))
	{
		ImGui::SetCursorPosX(5.f);
		ImGui::Text("Current version: 1.7(Fix)");
		ImGui::SetCursorPosX(5.f);
		ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 1.f);
		ImGui::Checkbox("Block user input when menu opened", &cfg::block_input);
		ImGui::PopStyleVar();
		ImGui::SetCursorPosX(5.f);
		ImGui::Text("Support author:");
		std::vector<std::pair<std::string, std::string>> support{
			{"Ko-Fi (PayPal)","https:\/\/ko-fi.com\/monkrel"},
			{"BuyMeACoffee (CC)","https:\/\/www.buymeacoffee.com\/monkrel"},
			{"Bitcoin","bc1qstz3rpazwm70f95mmj53360rqxqz5qzn2vlm8r"},
			{"Ethereum","0xf15357E8ABDB25f303D5D0610aBF803A162b8a03"},
			{"Tron (TRX)","TNHZFDcT8JVmPRqtWg3s11TK6rCQ5eYhwW"}
		};
		int i = 0;
		ImGui::Indent();
		for (auto& [key, value] : support) {
			ImGui::Text("%s", key.c_str());
			ImGui::SameLine();
			ImGui::PushID(i++);
			if (ImGui::Button("Copy")) {
				ImGui::SetClipboardText(value.c_str());
			}
			ImGui::PopID();
		}

		ImGui::EndTabItem();
	}
	ImGui::EndTabBar();
	if (!tab_esp && !tab_misc && !tab_support)
	{
		if (def_tab)
		{
			auto text1 = "This mod is made by monkrel ";
			auto text2 = "with love <3";
			auto windowWidth = ImGui::GetWindowSize().x;
			auto textWidth = ImGui::CalcTextSize(text1).x;

			ImGui::SetCursorPosX((windowWidth - textWidth) * 0.5f);
			ImGui::Text(text1);

			textWidth = ImGui::CalcTextSize(text2).x;
			ImGui::SetCursorPosX((windowWidth - textWidth) * 0.5f);
			ImGui::Text(text2);


			ImGui::SetCursorPos({ (windowWidth - 100) * 0.5f ,150 });
			ImGui::Button("Start", { 100,30 });


			if (ImGui::IsItemClicked())
			{
				tab_esp = true;
				tab_support = true;
				tab_misc = true;
				def_tab = false;
			}
		}
	}
	ImGui::PopFont();

	ImGui::End();
}