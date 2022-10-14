#include "pch.h"
#include "TrackedStats.h"

//Plugin Settings Window code here
std::string TrackedStats::GetPluginName() {
	return "TrackedStats";
}

void TrackedStats::SetImGuiContext(uintptr_t ctx) {
	ImGui::SetCurrentContext(reinterpret_cast<ImGuiContext*>(ctx));
}

// Render the plugin settings here
// This will show up in bakkesmod when the plugin is loaded at
//  f2 -> plugins -> TrackedStats
void TrackedStats::RenderSettings() {
	ImGui::TextUnformatted("TrackedStats plugin settings");
	ImGui::TextUnformatted("Configure which stats you want to track.");

	for (auto& tracker : trackers)
	{
		if (ImGui::CollapsingHeader(tracker.name_.c_str()))
		{
			ImGui::Checkbox("Activated", &tracker.active_);
		}
	}
}

// Do ImGui rendering here
void TrackedStats::Render()
{
	for (auto& tracker : trackers)
	{
		if (ImGui::Begin(tracker.name_.c_str(), &tracker.active_,
			ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_AlwaysAutoResize))
		{
			tracker.Render(*gameWrapper);
		}
		ImGui::End();
	}
}

// Name of the menu that is used to toggle the window.
std::string TrackedStats::GetMenuName()
{
	return "TrackedStats";
}

// Title to give the menu
std::string TrackedStats::GetMenuTitle()
{
	return "Tracked Stats";
}

// Should events such as mouse clicks/key inputs be blocked so they won't reach the game
bool TrackedStats::ShouldBlockInput()
{
	return ImGui::GetIO().WantCaptureMouse || ImGui::GetIO().WantCaptureKeyboard;
}

// Return true if window should be interactive
bool TrackedStats::IsActiveOverlay()
{
	return false;
}

// Called when window is opened
void TrackedStats::OnOpen()
{
}

// Called when window is closed
void TrackedStats::OnClose()
{
}

