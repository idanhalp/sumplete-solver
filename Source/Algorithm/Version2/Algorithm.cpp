#include "Source/Algorithm/Version2/Algorithm.hpp"
#include "Source/Algorithm/Version2/Utils/Trie/Trie.hpp"
#include "Source/Algorithm/Version2/Utils/ValidSubsetsGeneration/ValidSubsetsGeneration.hpp"
#include "Source/Parameters.hpp"
#include "Source/ValidityChecks/ValidityChecks.hpp"
#include <optional>
#include <ranges>
#include <span>

struct Cell
{
	size_t row;
	size_t col;
};

namespace Algorithm::Version2::Auxiliary
{
	auto solve(const Params::Input& input, Params::output_grid_t& output, std::span<const Utils::Trie> valid_rows_sequences, std::span<const Utils::Trie> valid_cols_sequences) -> bool;
	
	auto check_if_substitution_is_valid(const Cell cell, const Params::output_grid_t& output, std::span<const Utils::Trie> valid_rows_sequences, std::span<const Utils::Trie> valid_cols_sequences) -> bool;

	// Converts a list of cells to a vector of booleans that indicate whether each relevant cell is included in the sum.
	auto get_boolean_sequence(std::span<const Params::CellStatus> cells) -> std::vector<bool>;

	// Processes the rows and inserts all the valid subsets that sum to a row's target into a trie.
	auto get_valid_rows_sequences(const Params::Input& input) -> std::vector<Utils::Trie>;

	// Processes the columns and inserts all the valid subsets that sum to a column's target into a trie.
	auto get_valid_cols_sequences(const Params::Input& input) -> std::vector<Utils::Trie>;

	// Returns the `col_index`th column of `grid` as a std::vector.
	template <typename T>
	auto get_col(size_t col_index, const std::vector<std::vector<T>>& grid) -> std::vector<T>;

	auto find_next_vacant_cell(const Params::output_grid_t& output) -> std::optional<Cell>;
}

auto Algorithm::Version2::solve(const Params::Input& input) -> Params::output_t
{
	const std::optional<Params::SolutionError> input_error = ValidityChecks::check_input(input);
	const bool found_error_in_input = input_error.has_value();

	if (found_error_in_input)
	{
		return std::unexpected(input_error.value());
	}

	const std::vector valid_rows_sequences = Auxiliary::get_valid_rows_sequences(input);
	const std::vector valid_cols_sequences = Auxiliary::get_valid_cols_sequences(input);

	const size_t grid_size = input.grid.size();	
	Params::output_grid_t output(grid_size, std::vector<Params::CellStatus>(grid_size, Params::CellStatus::UNKNOWN)); // `grid_size` x `grid_size` grid.

	const bool solution_exists = Auxiliary::solve(input, output, valid_rows_sequences, valid_cols_sequences); // This call alters `output`.

	if (solution_exists)
	{
		return output;
	}
	else
	{
		return std::unexpected(Params::SolutionError::NO_SOLUTION);
	}
}

auto Algorithm::Version2::Auxiliary::solve(const Params::Input& input, Params::output_grid_t& output, std::span<const Utils::Trie> valid_rows_sequences, std::span<const Utils::Trie> valid_cols_sequences) -> bool
{
	const std::optional<Cell> cell = find_next_vacant_cell(output);
	const bool all_cells_are_filled = !cell.has_value();

	if (all_cells_are_filled)
	{
		return true;
	}

	const auto [row, col] = cell.value();

	for (const Params::CellStatus substitution : {Params::CellStatus::KEEP, Params::CellStatus::DELETE})
	{
		output[row][col] = substitution;
		const bool substitution_is_valid = Auxiliary::check_if_substitution_is_valid(cell.value(), output, valid_rows_sequences, valid_cols_sequences);
		const bool substitution_leads_to_solution = substitution_is_valid && solve(input, output, valid_rows_sequences, valid_cols_sequences);
		
		if (substitution_leads_to_solution)
		{
			return true;
		}	
	}

	// All the substitutions have failed, we need to backtrack.
	output[row][col] = Params::CellStatus::UNKNOWN;

	return false;
}

auto Algorithm::Version2::Auxiliary::check_if_substitution_is_valid(const Cell cell, const Params::output_grid_t& output, std::span<const Utils::Trie> valid_rows_sequences, std::span<const Utils::Trie> valid_cols_sequences) -> bool
{
	const auto [row, col] = cell;
	const std::vector row_sequence = get_boolean_sequence(output[row]);
	const std::vector col_sequence = get_boolean_sequence(get_col(col, output));
	const bool row_is_valid = valid_rows_sequences[row].check_if_prefix_exists(row_sequence);
	const bool col_is_valid = valid_cols_sequences[col].check_if_prefix_exists(col_sequence);

	return row_is_valid && col_is_valid;
}

/// @brief Converts a list of cells to a vector of booleans that indicate whether each relevant cell is included in the sum.
/// This function is used to interact with the tries.
/// @note an `UNKNOWN` CellStatus indicates the end of the sequence. 
/// It is guaranteed that once such CellStatus is found, the rest are also `UNKNOWN`.
/// @example `get_boolean_sequence({KEEP, DELETE, KEEP, DELETE})`  => `{true, false, true, false}`.
/// @example `get_boolean_sequence({KEEP, DELETE, KEEP, UNKNOWN})` => `{true, false, true}`.
auto Algorithm::Version2::Auxiliary::get_boolean_sequence(std::span<const Params::CellStatus> cells) -> std::vector<bool>
{
	const auto cell_is_filled = [] (const Params::CellStatus cell_status) -> bool { return cell_status != Params::CellStatus::UNKNOWN; };
	const auto cell_is_kept = [] (const Params::CellStatus cell_status) -> bool { return cell_status == Params::CellStatus::KEEP; };
	
	const std::vector sequence = cells 
		| std::views::take_while(cell_is_filled)
		| std::views::transform(cell_is_kept)
		| std::ranges::to<std::vector>();

	return sequence;
}

/// @brief Processes the rows and inserts all the valid subsets that sum to a row's target into a trie.
/// This function preprocesses the input to make the process of pruning dead end substitutions more efficient.
/// @returns a std::vector of tries, s.t each trie contains the subsequences that sum to its respective row's target. 
auto Algorithm::Version2::Auxiliary::get_valid_rows_sequences(const Params::Input& input) -> std::vector<Utils::Trie>
{
	std::vector<Utils::Trie> valid_rows_sequences;
	valid_rows_sequences.reserve(input.row_sums.size());

	for (const auto& [row, target_row_sum] : std::views::zip(input.grid, input.row_sums))
	{
		valid_rows_sequences.emplace_back(Utils::generate_valid_subsets(row, target_row_sum));
	}

	return valid_rows_sequences;
}

/// @brief Processes the columns and inserts all the valid subsets that sum to a column's target into a trie.
/// This function preprocesses the input to make the process of pruning dead end substitutions more efficient.
/// @returns a std::vector of tries, s.t each trie contains the subsequences that sum to its respective column's target.
auto Algorithm::Version2::Auxiliary::get_valid_cols_sequences(const Params::Input& input) -> std::vector<Utils::Trie>
{
	std::vector<Utils::Trie> valid_cols_sequences;
	valid_cols_sequences.reserve(input.col_sums.size());

	for (size_t col_index = 0; col_index < input.col_sums.size(); ++col_index)
	{
		const std::vector col = get_col(col_index, input.grid);
		const int target_col_sum = input.col_sums[col_index];

		valid_cols_sequences.emplace_back(Utils::generate_valid_subsets(col, target_col_sum));
	}

	return valid_cols_sequences;
}

/// @brief Returns the specified column as a `std::vector`.
/// @return std::vector col, s.t `col.size() == grid.size()` and `col[row_index] == grid[row_index][col_index]`.
/// @example `get_col(0, {{1, 2}, {3, 4}})` => `{1, 3}`.
/// @example `get_col(1, {{1, 2}, {3, 4}})` => `{2, 4}`.
template <typename T>
auto Algorithm::Version2::Auxiliary::get_col(size_t col_index, const std::vector<std::vector<T>>& grid) -> std::vector<T>
{
	std::vector<T> col_elements;

	for (size_t row_index = 0; row_index < grid.size(); ++row_index)
	{
		col_elements.push_back(grid[row_index][col_index]);
	}

	return col_elements;
}

auto Algorithm::Version2::Auxiliary::find_next_vacant_cell(const Params::output_grid_t& output) -> std::optional<Cell>
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
