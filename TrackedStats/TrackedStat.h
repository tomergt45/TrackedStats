#pragma once

struct TrackedStat
{
	std::string name_;
	std::function<int(const GameWrapper& gameWrapper)> getter_;
};

