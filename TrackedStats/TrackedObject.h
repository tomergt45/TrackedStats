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
	void Render();
	void Track(const TrackedStat& tracked_stat);
	void Hook(std::shared_ptr<GameWrapper> game_wrapper, const std::string& event_name, const std::function<int()>& callback);

private:
	void Hook_Func(std::string event_name, const std::function<int()>& callback);

public:
	bool active_;
	std::string name_;
	std::vector<TrackedStat> stats_;
	std::deque<int> data_;
	int data_size_ = 500;
};

