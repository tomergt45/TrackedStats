#pragma once

struct TrackedStat
{
	std::string name_;
	std::function<int()> getter_;
};

