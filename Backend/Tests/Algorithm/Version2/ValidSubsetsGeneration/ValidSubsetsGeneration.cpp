#include "Backend/Source/Algorithm/Version2/Utils/ValidSubsetsGeneration/ValidSubsetsGeneration.hpp"
#include "Backend/Tests/Algorithm/Version2/ValidSubsetsGeneration/ValidSubsetsGeneration.hpp"
#include <algorithm>
#include <cassert>
#include <vector>

namespace Tests::Version2::Auxiliary
{
	// Behaves like Python's "sorted(iterable)".
	template <typename T>
	auto sorted(std::vector<T> elements) -> std::vector<T>;
}

template <typename T>
auto Tests::Version2::Auxiliary::sorted(std::vector<T> elements) -> std::vector<T>
{
	std::ranges::sort(elements);

	return elements;
}

auto Tests::Version2::run_valid_subsets_generation_tests() -> void
{
	const std::vector elements_1{2, 3, 5};
	const int target_sum_1 = 5;
	const std::vector<std::vector<bool>> expected_valid_subsets_1
	{
		{true, true, false},
		{false, false, true}
	};

	const std::vector valid_subsets_1 = Algorithm::Version2::Utils::generate_valid_subsets(elements_1, target_sum_1);
	assert(Auxiliary::sorted(valid_subsets_1) == Auxiliary::sorted(expected_valid_subsets_1));

	// -------------------------------------------------------------------------------------------------------------

	const std::vector elements_2{7, 3, 3, 2};
	const int target_sum_2 = 12;
	const std::vector<std::vector<bool>> expected_valid_subsets_2
	{
		{true, true, false, true},
		{true, false, true, true},
	};

	const std::vector valid_subsets_2 = Algorithm::Version2::Utils::generate_valid_subsets(elements_2, target_sum_2);
	assert(Auxiliary::sorted(valid_subsets_2) == Auxiliary::sorted(expected_valid_subsets_2));

	// -------------------------------------------------------------------------------------------------------------

	const std::vector elements_3{7, 3, 3, 2};
	const int target_sum_3 = 14;
	const std::vector<std::vector<bool>> expected_valid_subsets_3
	{
	};

	const std::vector valid_subsets_3 = Algorithm::Version2::Utils::generate_valid_subsets(elements_3, target_sum_3);
	assert(Auxiliary::sorted(valid_subsets_3) == Auxiliary::sorted(expected_valid_subsets_3));
}
