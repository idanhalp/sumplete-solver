#include "Source/Backend/Algorithm/Version2/Algorithm.hpp"
#include "Source/Backend/Parameters.hpp"
#include "Tests/Backend/Algorithm/Algorithm.hpp"
#include <vector>

auto AlgorithmTests::check_output_validity(const Params::Input& input, const Params::output_t& output) -> bool
{
	const bool solution_exists = output.has_value();

	if (!solution_exists)
	{
		return false;
	}

	const Params::output_grid_t solution = output.value();
	const auto [actual_row_sums, actual_col_sums] = get_actual_row_and_col_sums(input, solution);
	const bool row_sums_match = input.row_sums == actual_row_sums;
	const bool col_sums_match = input.col_sums == actual_col_sums;

	return row_sums_match && col_sums_match;
}

auto AlgorithmTests::get_actual_row_and_col_sums(const Params::Input& input, const Params::output_grid_t& solution) -> std::pair<std::vector<int>, std::vector<int>>
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

auto AlgorithmTests::test_1() -> void
{
	const std::vector row_sums{5, 11, 8};
	const std::vector col_sums{9, 3, 12};
	const Params::input_grid_t grid
	{
		{2, 3, 5},
		{7, 2, 4},
		{4, 1, 8}
	};

	const Params::Input input = {row_sums, col_sums, grid};
	const Params::output_t output = Algorithm::Version2::solve(input);
	const bool output_is_valid = check_output_validity(input, output);

	QVERIFY(output_is_valid);
}

auto AlgorithmTests::test_2() -> void
{
	const std::vector row_sums{0, 12, 1, 14};
	const std::vector col_sums{0, 12, 5, 10};
	const Params::input_grid_t grid
	{
		{7, 3, 3, 2},
		{1, 3, 4, 5},
		{3, 6, 1, 2},
		{1, 9, 2, 5}
	};

	const Params::Input input = {row_sums, col_sums, grid};
	const Params::output_t output = Algorithm::Version2::solve(input);
	const bool output_is_valid = check_output_validity(input, output);

	QVERIFY(output_is_valid);
}

auto AlgorithmTests::test_3() -> void
{
	const std::vector row_sums{20, 19, 14, 8, 15};
	const std::vector col_sums{10, 15, 24, 6, 21};
	const Params::input_grid_t grid
	{
		{4, 3, 9, 1, 6},
		{2, 7, 2, 2, 8},
		{1, 5, 5, 3, 2},
		{3, 3, 1, 2, 2},
		{8, 3, 8, 9, 7}
	};

	const Params::Input input = {row_sums, col_sums, grid};
	const Params::output_t output = Algorithm::Version2::solve(input);
	const bool output_is_valid = check_output_validity(input, output);

	QVERIFY(output_is_valid);
}

auto AlgorithmTests::test_4() -> void
{
	const std::vector row_sums{13, 9, 14, 2, 17, 8};
	const std::vector col_sums{3, 8, 14, 22, 12, 4};
	const Params::input_grid_t grid
	{
		{6, 2, 3, 8, 3, 2},
		{3, 6, 7, 2, 3, 1},
		{4, 5, 1, 8, 1, 6},
		{7, 5, 6, 2, 9, 2},
		{3, 5, 6, 7, 8, 3},
		{2, 3, 4, 4, 1, 1}
	};

	const Params::Input input = {row_sums, col_sums, grid};
	const Params::output_t output = Algorithm::Version2::solve(input);
	const bool output_is_valid = check_output_validity(input, output);

	QVERIFY(output_is_valid);
}

auto AlgorithmTests::test_5() -> void
{
	const std::vector row_sums{8, 17, 18, 18, 26, 19, 22};
	const std::vector col_sums{14, 28, 16, 20, 19, 15, 16};
	const Params::input_grid_t grid
	{
		{3, 1, 2, 8, 5, 9, 5},
		{2, 7, 3, 7, 1, 5, 6},
		{2, 7, 3, 3, 3, 8, 4},
		{2, 3, 7, 5, 7, 2, 4},
		{8, 7, 9, 9, 9, 7, 2},
		{4, 7, 8, 4, 8, 1, 9},
		{4, 6, 1, 8, 2, 6, 1}
	};

	const Params::Input input = {row_sums, col_sums, grid};
	const Params::output_t output = Algorithm::Version2::solve(input);
	const bool output_is_valid = check_output_validity(input, output);

	QVERIFY(output_is_valid);
}

// More challenging, takes version 1 about 20 seconds to solve.
auto AlgorithmTests::test_6() -> void
{
	const std::vector row_sums{-19, -18, -8, -19, -17, 31, -56, 2, 12};
	const std::vector col_sums{-26, -4, -32, -23, 27, 2, 23, -54, -5};
	const Params::input_grid_t grid
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

	const Params::Input input = {row_sums, col_sums, grid};
	const Params::output_t output = Algorithm::Version2::solve(input);
	const bool output_is_valid = check_output_validity(input, output);

	assert(output_is_valid);
}

// Extreme difficulty, causes version 1 to SEGFAULT.
auto AlgorithmTests::test_7() -> void
{
	const std::vector row_sums{-31, -29, -18, 25, 3, -17, -23, -11, 0};
	const std::vector col_sums{-6, -28, -40, -4, -28, 12, -19, 15, -3};
	const Params::input_grid_t grid
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

	const Params::Input input = {row_sums, col_sums, grid};
	const Params::output_t output = Algorithm::Version2::solve(input);
	const bool output_is_valid = check_output_validity(input, output);

	QVERIFY(output_is_valid);
}

auto AlgorithmTests::test_8() -> void
{
	const std::vector row_sums{0, 12, 1, 14};
	const std::vector col_sums{0, 12, 5, 11};
	const Params::input_grid_t grid
	{
		{7, 3, 3, 2},
		{1, 3, 4, 5},
		{3, 6, 1, 2},
		{1, 9, 2, 5}
	};

	const Params::Input input = {row_sums, col_sums, grid};
	const Params::output_t output = Algorithm::Version2::solve(input);
	const bool output_is_valid = !output.has_value() && output.error() == Params::SolutionError::NO_SOLUTION;;

	QVERIFY(output_is_valid);
}
