#include "Source/Algorithm/Version2/Utils/ValidSubsetsGeneration/ValidSubsetsGeneration.hpp"
#include <algorithm>
#include <ranges>
#include <span>
#include <vector>

auto check_if_subset_is_valid(std::span<const int> elements, const int target_sum, const unsigned int subset_mask) -> bool
{
	int subset_sum = 0;

	for (const auto [index, element] : std::views::enumerate(elements))
	{
		const bool element_is_included_in_subset = (subset_mask & (1U << index)) != 0;

		if (element_is_included_in_subset)
		{
			subset_sum += element;
		}
	}

	return subset_sum == target_sum;
}

auto convert_mask_to_sequence(const unsigned int mask, const size_t set_size) -> std::vector<bool>
{
	const auto indices = std::views::iota(0U, set_size);
	const auto included_in_subset = [=] (const unsigned int index) -> bool { return (mask & (1U << index)) != 0; };
	
	const std::vector sequence = indices
		| std::views::transform(included_in_subset)
		| std::ranges::to<std::vector>();

	return sequence;
}

/// @brief   Generates all the boolean sequences that represent the subsets of `elements` whose sum is `target_sum`.
/// @return  std::vector of boolean sequences.
/// @note    No guarantee is made about the order of the output.
/// @example `generate_valid_subsets({1, 2, 3, 4}, 3)` => `{{true, true, false, false}, {false, false, true, false}}`.
auto Algorithm::Version2::Utils::generate_valid_subsets(std::span<const int> elements, const int target_sum) -> std::vector<std::vector<bool>>
{
	const auto masks = std::views::iota(0U, 1U << elements.size());
	const auto subset_is_valid = [&] (const unsigned int subset_mask) { return check_if_subset_is_valid(elements, target_sum, subset_mask); };
	const auto mask_to_sequence = [&] (const unsigned int subset_mask) { return convert_mask_to_sequence(subset_mask, elements.size()); };
	
	const std::vector valid_subsets = masks
		| std::views::filter(subset_is_valid)
		| std::views::transform(mask_to_sequence) 
		| std::ranges::to<std::vector>();

	return valid_subsets;
}
