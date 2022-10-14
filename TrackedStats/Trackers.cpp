#include "pch.h"
#include "TrackedStats.h"

void TrackedStats::loadTrackers()
{
	TrackedObject boost_tracker{ "Boost" };
	boost_tracker.Track("Average Boost", [this](const GameWrapper& gameWrapper) {
		return std::time(0);
		});
	trackers.push_back(boost_tracker);

	TrackedObject powerslide_tracker{ "Powerslide" };
	trackers.push_back(powerslide_tracker);
}

