#ifndef SOURCE_VALIDITY_CHECKS
#define SOURCE_VALIDITY_CHECKS

#include "Source/Parameters.hpp"
#include <optional>

namespace ValidityChecks
{
	/// @brief Checks whether the input is valid.
	/// @param input The algorithm's arguments.
	/// @return `std::nullopt` if the input is valid, or a relevant `SolutionStatus` otherwise.
	auto check_input(const Params::Input& input) -> std::optional<Params::SolutionError>;
}

#endif // SOURCE_VALIDITY_CHECKS
