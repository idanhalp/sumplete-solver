#include "Source/Algorithm/Version1/Algorithm.hpp"
#include "Source/Algorithm/Version2/Algorithm.hpp"
#include "Source/Parameters.hpp"
#include "Tests/Algorithm/Algorithm.hpp"
#include <cassert>
#include <vector>

namespace Tests::Auxiliary
{
	// Returns true iff `output` is a valid solution to `input`.
	auto check_output_validity(const Params::Input& input, const Params::output_t& output) -> bool;

	auto get_actual_row_and_col_sums(const Params::Input& input, const Params::output_grid_t& solution) -> std::pair<std::vector<int>, std::vector<int>>;
}

auto Tests::Auxiliary::check_output_validity(const Params::Input& input, const Params::output_t& output) -> bool
{
	const bool solution_exists = output.has_value();

	if (!solution_exists)
	{
		return false;
	}

	const Params::output_grid_t solution = output.value();
	const auto [actual_row_sums, actual_col_sums] = Auxiliary::get_actual_row_and_col_sums(input, solution);
	const bool row_sums_match = input.row_sums == actual_row_sums;
	const bool col_sums_match = input.col_sums == actual_col_sums;

	return row_sums_match && col_sums_match;
}

auto Tests::Auxiliary::get_actual_row_and_col_sums(const Params::Input& input, const Params::output_grid_t& solution) -> std::pair<std::vector<int>, std::vector<int>>
{
	std::vector<int> row_sums(solution.size());
	std::vector<int> col_sums(solution.size());

	for (size_t row = 0; row < solution.size(); ++row)
	{
		for (size_t col = 0; col < solution.size(); ++col)
		{
			const bool cell_is_kept = solution[row][col] == Params::CellStatus::KEEP;
			
			if (cell_is_kept)
			{
				row_sums[row] += input.grid[row][col];
				col_sums[col] += input.grid[row][col];
			}
		}
	}

	return {row_sums, col_sums};
}

auto Tests::run_algorithm_tests() -> void
{
	const std::vector row_sums_1{5, 11, 8};
	const std::vector col_sums_1{9, 3, 12};
	const Params::input_grid_t grid_1
	{
		{2, 3, 5},
		{7, 2, 4},
		{4, 1, 8}
	};

	const Params::Input input_1 = {row_sums_1, col_sums_1, grid_1};
	const Params::output_t version_1_output_1 = Algorithm::Version1::solve(input_1);
	const Params::output_t version_2_output_1 = Algorithm::Version2::solve(input_1);
	const bool version_1_output_is_valid_1 = Auxiliary::check_output_validity(input_1, version_1_output_1);
	const bool version_2_output_is_valid_1 = Auxiliary::check_output_validity(input_1, version_2_output_1);

	assert(version_1_output_is_valid_1);
	assert(version_2_output_is_valid_1);

	// ---------------------------------------------------------------------------------

	const std::vector row_sums_2{0, 12, 1, 14};
	const std::vector col_sums_2{0, 12, 5, 10};
	const Params::input_grid_t grid_2
	{
		{7, 3, 3, 2},
		{1, 3, 4, 5},
		{3, 6, 1, 2},
		{1, 9, 2, 5}
	};
	
	const Params::Input input_2 = {row_sums_2, col_sums_2, grid_2};
	const Params::output_t version_1_output_2 = Algorithm::Version1::solve(input_2);
	const Params::output_t version_2_output_2 = Algorithm::Version2::solve(input_2);
	const bool version_1_output_is_valid_2 = Auxiliary::check_output_validity(input_2, version_1_output_2);
	const bool version_2_output_is_valid_2 = Auxiliary::check_output_validity(input_2, version_2_output_2);

	assert(version_1_output_is_valid_2);
	assert(version_2_output_is_valid_2);

	// ---------------------------------------------------------------------------------

	const std::vector row_sums_3{20, 19, 14, 8, 15};
	const std::vector col_sums_3{10, 15, 24, 6, 21};
	const Params::input_grid_t grid_3
	{
		{4, 3, 9, 1, 6},
		{2, 7, 2, 2, 8},
		{1, 5, 5, 3, 2},
		{3, 3, 1, 2, 2},
		{8, 3, 8, 9, 7}
	};

	const Params::Input input_3 = {row_sums_3, col_sums_3, grid_3};
	const Params::output_t version_1_output_3 = Algorithm::Version1::solve(input_3);
	const Params::output_t version_2_output_3 = Algorithm::Version2::solve(input_3);
	const bool version_1_output_is_valid_3 = Auxiliary::check_output_validity(input_3, version_1_output_3);
	const bool version_2_output_is_valid_3 = Auxiliary::check_output_validity(input_3, version_2_output_3);

	assert(version_1_output_is_valid_3);
	assert(version_2_output_is_valid_3);

	// ---------------------------------------------------------------------------------

	const std::vector row_sums_4{13, 9, 14, 2, 17, 8};
	const std::vector col_sums_4{3, 8, 14, 22, 12, 4};
	const Params::input_grid_t grid_4
	{
		{6, 2, 3, 8, 3, 2},
		{3, 6, 7, 2, 3, 1},
		{4, 5, 1, 8, 1, 6},
		{7, 5, 6, 2, 9, 2},
		{3, 5, 6, 7, 8, 3},
		{2, 3, 4, 4, 1, 1}
	};

	const Params::Input input_4 = {row_sums_4, col_sums_4, grid_4};
	const Params::output_t version_1_output_4 = Algorithm::Version1::solve(input_4);
	const Params::output_t version_2_output_4 = Algorithm::Version2::solve(input_4);
	const bool version_1_output_is_valid_4 = Auxiliary::check_output_validity(input_4, version_1_output_4);
	const bool version_2_output_is_valid_4 = Auxiliary::check_output_validity(input_4, version_2_output_4);

	assert(version_1_output_is_valid_4);
	assert(version_2_output_is_valid_4);

	// ---------------------------------------------------------------------------------

	const std::vector row_sums_5{8, 17, 18, 18, 26, 19, 22};
	const std::vector col_sums_5{14, 28, 16, 20, 19, 15, 16};
	const Params::input_grid_t grid_5
	{
		{3, 1, 2, 8, 5, 9, 5},
		{2, 7, 3, 7, 1, 5, 6},
		{2, 7, 3, 3, 3, 8, 4},
		{2, 3, 7, 5, 7, 2, 4},
		{8, 7, 9, 9, 9, 7, 2},
		{4, 7, 8, 4, 8, 1, 9},
		{4, 6, 1, 8, 2, 6, 1}
	};

	const Params::Input input_5 = {row_sums_5, col_sums_5, grid_5};
	const Params::output_t version_1_output_5 = Algorithm::Version1::solve(input_5);
	const Params::output_t version_2_output_5 = Algorithm::Version2::solve(input_5);
	const bool version_1_output_is_valid_5 = Auxiliary::check_output_validity(input_5, version_1_output_5);
	const bool version_2_output_is_valid_5 = Auxiliary::check_output_validity(input_5, version_2_output_5);

	assert(version_1_output_is_valid_5);
	assert(version_2_output_is_valid_5);

	// -------------------------- HARD TEST CASE ------------------------------------

	const std::vector row_sums_6{-19, -18, -8, -19, -17, 31, -56, 2, 12};
	const std::vector col_sums_6{-26, -4, -32, -23, 27, 2, 23, -54, -5};
	const Params::input_grid_t grid_6
	{
		{ -1,   5,  -8,  -4,  -2,  -4,   5,  -1,  -5},
		{ 11,  -3,   6,  -6, -10, -10, -17,   6, -18},
		{-10,  10,   4,  -5, -12,  -2,  15, -19, -16},
		{-10,  -5,  -6,   6,  14,  15,  19, -13,  -9},
		{ -6,   4,  15, -14,  13,  -4,   3, -11, -18},
		{ -7,  -8,  -8,   3,  11,  14,  -5, -15,  19},
		{-16,  12, -18,  -2,  15,  -5,  19, -15,  14},
		{  6, -11,   2,  -4,  11,  11, -14,  -7,   8},
		{-14, -10,  -3,  14,  19,   3,   1,  19,  -6}
	};

	const Params::Input input_6 = {row_sums_6, col_sums_6, grid_6};
	const Params::output_t output_6 = Algorithm::Version2::solve(input_6);
	const bool output_is_valid_6 = Auxiliary::check_output_validity(input_6, output_6);

	assert(output_is_valid_6);

	// -------------------------- EXTREME TEST CASE ------------------------------------
	
	const std::vector row_sums_7{-31, -29, -18, 25, 3, -17, -23, -11, 0};
	const std::vector col_sums_7{-6, -28, -40, -4, -28, 12, -19, 15, -3};
	const Params::input_grid_t grid_7
	{
		{  1, -10, -13, -10,  -9,  -3,  -4,  15,  12},
		{  7,   2,  14,  -7,  -7, -17,  -7, -18, -18},
		{-15, -14, -18, -17,   9,  17,  -5, -12,  17},
		{  1,  12,  12,  17,   1,  16, -12,  14,  -8},
		{  2,  12, -13,  -1,   5, -19,  -3,  -2,  14},
		{  9,   1, -13, -15,  10, -10,   6, -14,  -6},
		{-17,  -9,   6, -16, -12,   9, -17,  19,  -3},
		{ -3, -19,  -3,   7, -16,  -1,  16,   8,   9},
		{ 15,  -8, -10,  18,   8, -13,   3, -13,  -7}
	};

	const Params::Input input_7 = {row_sums_7, col_sums_7, grid_7};
	const Params::output_t output_7 = Algorithm::Version2::solve(input_7);
	const bool output_is_valid_7 = Auxiliary::check_output_validity(input_7, output_7);

	assert(output_is_valid_7);
}
