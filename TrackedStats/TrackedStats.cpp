#include "pch.h"
#include "TrackedStats.h"


BAKKESMOD_PLUGIN(TrackedStats, "Tracked Stats", plugin_version, PLUGINTYPE_FREEPLAY)

void TrackedStats::onLoad()
{
	loadTrackers();

	gameWrapper->SetTimeout([this](GameWrapper* gameWrapper) {
		cvarManager->executeCommand("togglemenu " + GetMenuName());
		}, 1);
}

void TrackedStats::onUnload()
{
	// if (isWindowOpen_) {
	cvarManager->executeCommand("togglemenu " + GetMenuName());
	// }
}