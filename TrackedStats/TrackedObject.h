#pragma once

#include <string>
#include <vector>

#include "TrackedStat.h"

class TrackedObject
{
public:
	TrackedObject(const std::string& name_, bool active = true);

public:
	void Render(const GameWrapper& gameWrapper) const;
	void Track(const TrackedStat& tracked_stat);
	void Track(const std::string& name,
		const std::function<int(const GameWrapper& gameWrapper)>& getter);

public:
	bool active_;
	std::string name_;
	std::vector<TrackedStat> stats_;
};

