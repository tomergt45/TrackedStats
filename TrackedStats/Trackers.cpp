#include "pch.h"

#include "Trackers.h"
#include "TrackedStats.h"
#include "Helpers.h"

std::shared_ptr<TrackedObject> trackers::boost_tracker = std::make_shared<TrackedObject>();
std::vector<std::shared_ptr<TrackedObject>> trackers::trackers
{
	trackers::boost_tracker
};

using namespace trackers;

void TrackedStats::loadTrackers()
{
	boost_tracker->Hook(gameWrapper, "Function Engine.GameViewportClient.Tick",
		[&]()
		{
			if (!gameWrapper->IsInGame())
			{
				return NULL;
			}

			auto car = gameWrapper->GetLocalCar();
			auto boost = car.GetBoostComponent();
			auto boost_amount = boost.GetCurrentBoostAmount() * 100;

			return (int)(boost_amount);
		});

	boost_tracker->Track({
			"Average Boost",
			std::bind(helpers::Average, std::ref(boost_tracker->data_))
		}
	);
	boost_tracker->Track({
			"Min Boost",
			std::bind(helpers::Min, std::ref(boost_tracker->data_))
		}
	);
	boost_tracker->Track({
			"Max Boost",
			std::bind(helpers::Max, std::ref(boost_tracker->data_))
		}
	);
}
