#include "Source/Backend/Parameters.hpp"
#include "Source/Backend/ValidityChecks/ValidityChecks.hpp"
#include "Tests/Backend/ValidityChecks/ValidityChecks.hpp"
#include <optional>
#include <vector>

auto ValidityChecksTests::test_1() -> void
{
	const std::vector row_sums{1, 2, 3};
	const std::vector col_sums{1, 2, 3, 4};
	const Params::input_grid_t grid
	{
		{1, 2, 3, 4},
		{1, 2, 3, 4},
		{1, 2, 3, 4},
		{1, 2, 3, 4}
	};

	const Params::Input input = {row_sums, col_sums, grid};
	const std::optional<Params::SolutionError> result = ValidityChecks::check_input(input);
	const bool check_is_correct = result.has_value() && result.value() == Params::SolutionError::INCORRECT_NUMBER_OF_ROWS;

	QVERIFY(check_is_correct);
}

auto ValidityChecksTests::test_2() -> void
{
	const std::vector row_sums{1, 2, 3, 4};
	const std::vector col_sums{1, 2, 3};
	const Params::input_grid_t grid
	{
		{1, 2, 3, 4},
		{1, 2, 3, 4},
		{1, 2, 3, 4},
		{1, 2, 3, 4}
	};

	const Params::Input input = {row_sums, col_sums, grid};
	const std::optional<Params::SolutionError> result = ValidityChecks::check_input(input);
	const bool check_is_correct = result.has_value() && result.value() == Params::SolutionError::INCORRECT_NUMBER_OF_COLUMNS;

	QVERIFY(check_is_correct);
}

auto ValidityChecksTests::test_3() -> void
{
	const std::vector row_sums{1, 2, 3, 4};
	const std::vector col_sums{1, 2, 3, 4};
	const Params::input_grid_t grid
	{
		{1, 2, 3, 4},
		{1, 2, 3, 4},
		{1, 2, 3},
		{1, 2, 3, 4}
	};

	const Params::Input input = {row_sums, col_sums, grid};
	const std::optional<Params::SolutionError> result = ValidityChecks::check_input(input);
	const bool check_is_correct = result.has_value() && result.value() == Params::SolutionError::GRID_NOT_SQUARED;

	QVERIFY(check_is_correct);
}

auto ValidityChecksTests::test_4() -> void
{
	const std::vector row_sums{1, 2, 3, 4};
	const std::vector col_sums{1, 2, 3, 4};
	const Params::input_grid_t grid
	{
		{1, 2, 3, 4},
		{1, 2, 3, 4},
		{1, 2, 3, 4}
	};

	const Params::Input input = {row_sums, col_sums, grid};
	const std::optional<Params::SolutionError> result = ValidityChecks::check_input(input);
	const bool check_is_correct = result.has_value() && result.value() == Params::SolutionError::GRID_NOT_SQUARED;

	QVERIFY(check_is_correct);
}

auto ValidityChecksTests::test_5() -> void
{
	const std::vector row_sums{1, 2, 3, 4};
	const std::vector col_sums{1, 2, 3, 4};
	const Params::input_grid_t grid
	{
		{1, 2, 3, 4},
		{1, 2, 3, 4},
		{1, 2, 3, 4},
		{1, 2, 3, 4}
	};

	const Params::Input input = {row_sums, col_sums, grid};
	const std::optional<Params::SolutionError> result = ValidityChecks::check_input(input);
	const bool check_is_correct = !result.has_value();

	QVERIFY(check_is_correct);
}
