#ifndef SOURCE_ALGORITHM_VERSION_1_HPP
#define SOURCE_ALGORITHM_VERSION_1_HPP

#include "Source/Parameters.hpp"

/// @brief Simple algorithm for finding a solution.
///
/// Iterates over each cell and tries to keep or
/// delete it.
///
/// When an entire row or column is filled, it checks 
/// whether the sum is correct, and continues or backtracks
/// accordingly.
///
/// This implementation is sufficient for solving simple grids.
/// However it struggles with larger grids, taking more than
/// 20 seconds to solve an easy 9x9 grid, and unable to solve
/// a master-level grid of such size.
///
/// The main drawback of the implementation is that its pruning
/// is very lax: only when an end of a row or column is reached;
/// an issue which is solved in version 2.
namespace Algorithm::Version1
{
	/// @brief Finds a solution to the input.
	/// @param input The algorithm's arguments.
	/// @return A solution if exists, or a relevant `SolutionError` otherwise.
	/// @note Does not assume for valid input.
	auto solve(const Params::Input& input) -> Params::output_t;
};

#endif // SOURCE_ALGORITHM_VERSION_1_HPP
