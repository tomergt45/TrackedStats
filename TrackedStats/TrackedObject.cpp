#include "pch.h"
#include "TrackedObject.h"

TrackedObject::TrackedObject(const std::string& name_, bool active) :
	name_{ name_ },
	active_{ active },
	stats_{}
{
}

void TrackedObject::Render() const
{
	for (const auto& stat : stats_)
	{
		const auto statVal = stat.getter_();

		ImGui::Text(stat.name_.c_str());
		ImGui::SameLine();
		ImGui::Text(std::to_string(statVal).c_str());
	}
}

void TrackedObject::Track(const TrackedStat& tracked_stat)
{
	stats_.push_back(tracked_stat);
}

void TrackedObject::Track(const std::string& name,
	const std::function<int()>& func)
{
	Track({ name, func });
}

