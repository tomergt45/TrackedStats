#include "pch.h"
#include "TrackedStats.h"

#include <numeric>

void TrackedStats::loadTrackers()
{
	TrackedObject boost_tracker{ "Boost" };
	boost_tracker.Track("Average Boost", [boost_tracker]()
		{
			const auto& samples = boost_tracker.samples_;
			return std::reduce(samples.begin(), samples.end()) / samples.size();
		}
	);
	trackers.push_back(boost_tracker);

	TrackedObject powerslide_tracker{ "Powerslide" };
	trackers.push_back(powerslide_tracker);
}
