#ifndef SOURCE_ALGORITHM_VERSION_1_HPP
#define SOURCE_ALGORITHM_VERSION_1_HPP

#include "Source/Backend/Parameters.hpp"

namespace Algorithm::Version1
{
	/// @brief Finds a solution to the input.
	/// @param input The algorithm's arguments.
	/// @return A solution if exists, or a relevant `SolutionStatus` otherwise.
	/// @note Does not assume for valid input.
	[[deprecated("Use version 2.")]]
	auto solve(const Params::Input& input) -> Params::output_t;
};

#endif // SOURCE_ALGORITHM_VERSION_1_HPP
