#pragma once

struct TrackedStat
{
	std::string name_;
	std::function<int64_t()> getter_;
};

