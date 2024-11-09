#include "Source/Backend/Parameters.hpp"
#include "Source/Backend/ValidityChecks/ValidityChecks.hpp"
#include "Tests/ValidityChecks/ValidityChecks.hpp"
#include <cassert>
#include <optional>
#include <vector>

auto Tests::run_validity_checks_tests() -> void
{
	const std::vector row_sums_1{1, 2, 3};
	const std::vector col_sums_1{1, 2, 3, 4};
	const Params::input_grid_t grid_1
	{
		{1, 2, 3, 4},
		{1, 2, 3, 4},
		{1, 2, 3, 4},
		{1, 2, 3, 4}
	};

	const Params::Input input_1 = {row_sums_1, col_sums_1, grid_1};
	const std::optional<Params::SolutionError> result_1 = ValidityChecks::check_input(input_1);
	const bool check_is_correct_1 = result_1.has_value() && result_1.value() == Params::SolutionError::INCORRECT_NUMBER_OF_ROWS;

	assert(check_is_correct_1);

	// -------------------------------------------------------------------------------------------------------------------------------------------

	const std::vector row_sums_2{1, 2, 3, 4};
	const std::vector col_sums_2{1, 2, 3};
	const Params::input_grid_t grid_2
	{
		{1, 2, 3, 4},
		{1, 2, 3, 4},
		{1, 2, 3, 4},
		{1, 2, 3, 4}
	};

	const Params::Input input_2 = {row_sums_2, col_sums_2, grid_2};
	const std::optional<Params::SolutionError> result_2 = ValidityChecks::check_input(input_2);
	const bool check_is_correct_2 = result_2.has_value() && result_2.value() == Params::SolutionError::INCORRECT_NUMBER_OF_COLUMNS;

	assert(check_is_correct_2);

	// -------------------------------------------------------------------------------------------------------------------------------------------

	const std::vector row_sums_3{1, 2, 3, 4};
	const std::vector col_sums_3{1, 2, 3, 4};
	const Params::input_grid_t grid_3
	{
		{1, 2, 3, 4},
		{1, 2, 3, 4},
		{1, 2, 3},
		{1, 2, 3, 4}
	};

	const Params::Input input_3 = {row_sums_3, col_sums_3, grid_3};
	const std::optional<Params::SolutionError> result_3 = ValidityChecks::check_input(input_3);
	const bool check_is_correct_3 = result_3.has_value() && result_3.value() == Params::SolutionError::GRID_NOT_SQUARED;

	assert(check_is_correct_3);

	// -------------------------------------------------------------------------------------------------------------------------------------------

	const std::vector row_sums_4{1, 2, 3, 4};
	const std::vector col_sums_4{1, 2, 3, 4};
	const Params::input_grid_t grid_4
	{
		{1, 2, 3, 4},
		{1, 2, 3, 4},
		{1, 2, 3, 4}
	};

	const Params::Input input_4 = {row_sums_4, col_sums_4, grid_4};
	const std::optional<Params::SolutionError> result_4 = ValidityChecks::check_input(input_4);
	const bool check_is_correct_4 = result_4.has_value() && result_4.value() == Params::SolutionError::GRID_NOT_SQUARED;

	assert(check_is_correct_4);


	// -------------------------------------------------------------------------------------------------------------------------------------------

	const std::vector row_sums_5{1, 2, 3, 4};
	const std::vector col_sums_5{1, 2, 3, 4};
	const Params::input_grid_t grid_5
	{
		{1, 2, 3, 4},
		{1, 2, 3, 4},
		{1, 2, 3, 4},
		{1, 2, 3, 4}
	};

	const Params::Input input_5 = {row_sums_5, col_sums_5, grid_5};
	const std::optional<Params::SolutionError> result_5 = ValidityChecks::check_input(input_5);
	const bool check_is_correct_5 = !result_5.has_value();

	assert(check_is_correct_5);
}
