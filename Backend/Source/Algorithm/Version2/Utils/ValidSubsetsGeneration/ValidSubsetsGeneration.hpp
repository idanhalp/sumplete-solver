#ifndef VALID_SUBSETS_GENERATION_HPP
#define VALID_SUBSETS_GENERATION_HPP

#include <span>
#include <vector>
 
namespace Algorithm::Version2::Utils
{
	// Returns all the boolean sequences that represent the subsets of `elements` whose sum is `target_sum`.
	auto generate_valid_subsets(std::span<const int> elements, const int target_sum) -> std::vector<std::vector<bool>>;
}

#endif // VALID_SUBSETS_GENERATION_HPP
