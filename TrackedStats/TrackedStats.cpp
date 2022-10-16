#include "pch.h"
#include "TrackedStats.h"

BAKKESMOD_PLUGIN(TrackedStats, "Tracked Stats", plugin_version, PLUGINTYPE_FREEPLAY)

std::shared_ptr<CVarManagerWrapper> _globalCvarManager;

void TrackedStats::onLoad()
{
	_globalCvarManager = cvarManager;

	loadTrackers();

	gameWrapper->SetTimeout([this](GameWrapper* gameWrapper)
		{
			cvarManager->executeCommand("togglemenu " + GetMenuName());
		},
		1);
}

void TrackedStats::onUnload()
{
	// if (isWindowOpen_)
	cvarManager->executeCommand("togglemenu " + GetMenuName());
}

