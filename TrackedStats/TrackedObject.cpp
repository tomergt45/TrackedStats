#include "pch.h"
#include "TrackedObject.h"
#include "TrackedStats.h"

TrackedObject::TrackedObject(const std::string& name_, bool active) :
	name_{ name_ },
	active_{ active },
	stats_{},
	data_{}
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

void TrackedObject::Hook(std::shared_ptr<GameWrapper> game_wrapper,
	const std::string& event_name,
	const std::function<int()>& callback)
{
	game_wrapper->HookEvent(event_name,
		std::bind(&TrackedObject::Hook_Func,
			std::ref(*this),
			std::placeholders::_1,
			callback));
}

void TrackedObject::Hook_Func(std::string event_name, const std::function<int()>& callback)
{
	const auto val = callback();
	if (val == NULL)
	{
		return;
	}

	if (data_.size() > 5000)
	{
		data_.pop_front();
	}

	data_.push_back(val);
}