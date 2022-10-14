#pragma once

#include <string>
#include <vector>

#include "TrackedStat.h"

using namespace std::chrono;

class TrackedObject
{
public:
	TrackedObject(const std::string& name_, bool active = true);

public:
	void Render() const;
	void Track(const TrackedStat& tracked_stat);
	void Track(const std::string& name, const std::function<int()>& func);

public:
	bool active_;
	std::string name_;
	std::vector<TrackedStat> stats_;
	std::vector<int> samples_;
};

