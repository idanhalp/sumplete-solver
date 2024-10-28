#ifndef VALID_SUBSETS_GENERATION_HPP
#define VALID_SUBSETS_GENERATION_HPP

#include <span>
#include <vector>
 
namespace Algorithm::Version2::Utils
{
	auto generate_valid_subsets(std::span<const int> elements, const int target_sum) -> std::vector<std::vector<bool>>;
}

#endif // VALID_SUBSETS_GENERATION_HPP
