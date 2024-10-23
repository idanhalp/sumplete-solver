#include "../Parameters.hpp"
#include "ValidityChecks.hpp"
#include <algorithm>
#include <span>

namespace ValidityChecks::Auxiliary
{
	auto check_if_number_of_grid_is_square(const Params::input_grid_t& grid) -> bool;
	auto check_if_number_of_rows_is_correct(const Params::Input& input) -> bool;
	auto check_if_number_of_cols_is_correct(const Params::Input& input) -> bool;
}

auto ValidityChecks::Auxiliary::check_if_number_of_grid_is_square(const Params::input_grid_t& grid) -> bool
{
	const size_t num_of_rows = grid.size();
	const auto num_of_cols_is_correct = [=] (std::span<const int> row) -> bool { return row.size() == num_of_rows; };
	const bool all_rows_have_correct_num_of_cols = std::ranges::all_of(grid, num_of_cols_is_correct);

	return all_rows_have_correct_num_of_cols;
}

auto ValidityChecks::Auxiliary::check_if_number_of_rows_is_correct(const Params::Input& input) -> bool
{
	return input.grid.size() == input.row_sums.size();
}

auto ValidityChecks::Auxiliary::check_if_number_of_cols_is_correct(const Params::Input& input) -> bool
{
	return input.grid.front().size() == input.col_sums.size();
}

auto ValidityChecks::check_input(const Params::Input& input) -> std::optional<Params::SolutionError>
{
	const bool grid_is_square = Auxiliary::check_if_number_of_grid_is_square(input.grid);
	
	if (!grid_is_square)
	{
		return Params::SolutionError::GRID_NOT_SQUARED;
	}
	
	const bool number_of_rows_is_correct = Auxiliary::check_if_number_of_rows_is_correct(input);
	
	if (!number_of_rows_is_correct)
	{
		return Params::SolutionError::INCORRECT_NUMBER_OF_ROWS;
	}
	
	const bool number_of_cols_is_correct = Auxiliary::check_if_number_of_cols_is_correct(input);

	if (!number_of_cols_is_correct)
	{
		return Params::SolutionError::INCORRECT_NUMBER_OF_COLUMNS;
	}

	return std::nullopt; // The input is valid.
}

