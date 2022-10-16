#pragma once
#include "pch.h"

#include <numeric>

namespace helpers
{
	static int64_t Average(const std::deque<int>& vec)
	{
		if (vec.size() <= 0)
		{
			return int64_t{};
		}

		return 1.0 * std::reduce(vec.begin(), vec.end()) / vec.size();
	}

	static int Min(const std::deque<int>& vec)
	{
		if (vec.size() <= 0)
		{
			return int64_t{};
		}

		return *std::min_element(vec.begin(), vec.end());
	}

	static int Max(const std::deque<int>& vec)
	{
		if (vec.size() <= 0)
		{
			return int64_t{};
		}

		return *std::max_element(vec.begin(), vec.end());
	}
}