#ifndef SOURCE_ALGORITHM_VERSION_2_HPP
#define SOURCE_ALGORITHM_VERSION_2_HPP

#include "Source/Parameters.hpp"

/// @brief Optimized algorithm for finding a solution.
///
/// The main difference from the first version lays 
/// in the pruning of dead end paths.
///
/// Every possible subset of each row and column is checked,
/// and the subsets that sum to the target are inserted to a trie.
/// 
/// Thus after every substitution we are able to check if we have
/// reached a dead end, and continue or backtrack accordingly.
///
/// This version is much superior to the first one, and is capable
/// of solving master-level 9x9 grids immediately.
namespace Algorithm::Version2
{
	/// @brief Finds a solution to the input.
	/// @param input The algorithm's arguments.
	/// @return A solution if exists, or a relevant `SolutionError` otherwise.
	/// @note Does not assume for valid input.
	auto solve(const Params::Input& input) -> Params::output_t;
};

#endif // SOURCE_ALGORITHM_VERSION_2_HPP
