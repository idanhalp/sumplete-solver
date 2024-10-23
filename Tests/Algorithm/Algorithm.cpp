#include "../../Source/Algorithm/Algorithm.hpp"
#include "../../Source/Parameters.hpp"
#include "Algorithm.hpp"
#include <cassert>
#include <vector>

namespace Tests::Auxiliary
{
	// Returns true iff `output` is a valid solution to `input`.
	// Assumes a solution exists.
	auto check_output_validity(const Params::Input& input, const Params::output_t& output) -> bool;
}

auto Tests::run_algorithm_tests() -> void
{
	const std::vector<int> row_sums_1{5, 11, 8};
	const std::vector<int> col_sums_1{9, 3, 12};
	const Params::input_grid_t grid_1
	{
		{2, 3, 5},
		{7, 2, 4},
		{4, 1, 8}
	};

	const Params::Input input_1 = {row_sums_1, col_sums_1, grid_1};
	const Params::output_t output_1 = Algorithm::solve(input_1);
	const bool output_is_valid_1 = Auxiliary::check_output_validity(input_1, output_1);

	assert(output_is_valid_1);

	// ---------------------------------------------------------------------------------

	const std::vector<int> row_sums_2{0, 12, 1, 14};
	const std::vector<int> col_sums_2{0, 12, 5, 10};
	const Params::input_grid_t grid_2
	{
		{7, 3, 3, 2},
		{1, 3, 4, 5},
		{3, 6, 1, 2},
		{1, 9, 2, 5}
	};

	const Params::Input input_2 = {row_sums_2, col_sums_2, grid_2};
	const Params::output_t output_2 = Algorithm::solve(input_2);
	const bool output_is_valid_2 = Auxiliary::check_output_validity(input_2, output_2);

	assert(output_is_valid_2);
}
