#pragma once

#include "TrackedObject.h"

namespace trackers
{
	extern std::shared_ptr<TrackedObject> boost_tracker;
	extern std::vector<std::shared_ptr<TrackedObject>> trackers;
}
