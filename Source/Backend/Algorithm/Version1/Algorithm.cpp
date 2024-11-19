#include "Source/Backend/Algorithm/Version1/Algorithm.hpp"
#include "Source/Backend/Parameters.hpp"
#include "Source/Backend/ValidityChecks/ValidityChecks.hpp"
#include <optional>
#include <span>
#include <vector>

struct Cell
{
	size_t row;
	size_t col;
};

namespace Algorithm::Version1::Auxiliary
{
	auto solve(const Params::Input& input, Params::output_grid_t& output, std::span<int> actual_row_sums, std::span<int> actual_col_sums) -> bool;
	
	auto try_keeping_value(const Cell cell, const Params::Input& input, Params::output_grid_t& output, std::span<int> actual_row_sums, std::span<int> actual_col_sums) -> bool;

	auto try_deleting_value(const Cell cell, const Params::Input& input, Params::output_grid_t& output, std::span<int> actual_row_sums, std::span<int> actual_col_sums) -> bool;

	auto find_next_vacant_cell(const Params::output_grid_t& output) -> std::optional<Cell>;
}

auto Algorithm::Version1::solve(const Params::Input& input) -> Params::output_t
{
	const std::optional<Params::SolutionStatus> input_error = ValidityChecks::check_input(input);
	const bool found_error_in_input = input_error.has_value();

	if (found_error_in_input)
	{
		return std::unexpected(input_error.value());
	}

	const size_t grid_size = input.grid.size();
	
	Params::output_grid_t output(grid_size, std::vector<Params::CellStatus>(grid_size, Params::CellStatus::UNKNOWN)); // `grid_size` x `grid_size` grid.
	std::vector<int> actual_row_sums(grid_size, 0);
	std::vector<int> actual_col_sums(grid_size, 0);

	const bool solution_exists = Auxiliary::solve(input, output, actual_row_sums, actual_col_sums); // This call alters `output`.

	if (solution_exists)
	{
		return output;
	}
	else
	{
		return std::unexpected(Params::SolutionStatus::NO_SOLUTION);
	}
}

auto Algorithm::Version1::Auxiliary::solve(const Params::Input& input, Params::output_grid_t& output, std::span<int> actual_row_sums, std::span<int> actual_col_sums) -> bool
{
	const std::optional<Cell> cell = find_next_vacant_cell(output);
	const bool all_cells_are_filled = !cell.has_value();

	if (all_cells_are_filled)
	{
		return true;
	}

	const bool keeping_cell_value_leads_to_solution = try_keeping_value(cell.value(), input, output, actual_row_sums, actual_col_sums);
	
	if (keeping_cell_value_leads_to_solution)
	{
		return true;
	}

	const bool deleting_cell_value_leads_to_solution = try_deleting_value(cell.value(), input, output, actual_row_sums, actual_col_sums);

	if (deleting_cell_value_leads_to_solution)
	{
		return true;
	}

	// All attempts have failed, we need to backtrack.
	return false;
}

auto Algorithm::Version1::Auxiliary::try_keeping_value(const Cell cell, const Params::Input& input, Params::output_grid_t& output, std::span<int> actual_row_sums, std::span<int> actual_col_sums) -> bool
{
	const auto [row, col] = cell;
	output[row][col] = Params::CellStatus::KEEP;
	actual_row_sums[row] += input.grid[row][col];
	actual_col_sums[col] += input.grid[row][col];

	const bool reached_last_row = row == input.grid.size() - 1;
	const bool reached_last_col = col == input.grid.size() - 1;
	const bool rows_are_valid = !reached_last_col || actual_row_sums[row] == input.row_sums[row];
	const bool cols_are_valid = !reached_last_row || actual_col_sums[col] == input.col_sums[col];	
	const bool substitution_is_valid = rows_are_valid && cols_are_valid && solve(input, output, actual_row_sums, actual_col_sums);

	if (substitution_is_valid)
	{
		return true;
	}

	// Backtrack.
	output[row][col] = Params::CellStatus::UNKNOWN;
	actual_row_sums[row] -= input.grid[row][col];
	actual_col_sums[col] -= input.grid[row][col];
	
	return false;
}

auto Algorithm::Version1::Auxiliary::try_deleting_value(const Cell cell, const Params::Input& input, Params::output_grid_t& output, std::span<int> actual_row_sums, std::span<int> actual_col_sums) -> bool
{
	const auto [row, col] = cell;
	output[row][col] = Params::CellStatus::DELETE;

	const bool reached_last_row = row == input.grid.size() - 1;
	const bool reached_last_col = col == input.grid.size() - 1;
	const bool rows_are_valid = !reached_last_col || actual_row_sums[row] == input.row_sums[row];
	const bool cols_are_valid = !reached_last_row || actual_col_sums[col] == input.col_sums[col];	
	const bool substitution_is_valid = rows_are_valid && cols_are_valid && solve(input, output, actual_row_sums, actual_col_sums);

	if (substitution_is_valid)
	{
		return true;
	}

	// Backtrack.
	output[row][col] = Params::CellStatus::UNKNOWN;
	
	return false;
}

auto Algorithm::Version1::Auxiliary::find_next_vacant_cell(const Params::output_grid_t& output) -> std::optional<Cell>
{
	for (size_t row = 0; row < output.size(); ++row)
	{
		for (size_t col = 0; col < output.size(); ++col)
		{
			const bool cell_is_vacant = output[row][col] == Params::CellStatus::UNKNOWN;

			if (cell_is_vacant)
			{
				return Cell(row, col);
			}
		}
	}

	return std::nullopt; // All cells are filled.
}
