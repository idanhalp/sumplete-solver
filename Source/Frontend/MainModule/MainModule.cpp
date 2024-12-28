#include "Source/Backend/Algorithm/Version2/Algorithm.hpp"
#include "Source/Frontend/MainModule/MainModule.hpp"
#include <QVariant>
#include <algorithm>
#include <span>
#include <vector>

MainModule::MainModule() : NO_VALUE(1'000)
{
	m_size = 0; // Guarantees that `m_size != new_size` when `resize` is called.
	resize(Params::DEFAULT_GRID_SIZE);
}

auto MainModule::rowCount(const QModelIndex& parent) const -> int
{
	Q_UNUSED(parent)

	return m_grid_buffer.count(); // Size.
}

auto MainModule::data(const QModelIndex& index, int role) const -> QVariant
{
	Q_UNUSED(index)
	Q_UNUSED(role)

	return {};
}

auto MainModule::clear() -> void
{
	const int original_size = m_size;

	resize(0);
	resize(original_size);
}

auto MainModule::resize(const int new_size) -> void
{
	const bool size_changed = m_size != new_size;

	// If the size didn't change, the grid's content must not be deleted.
	if (!size_changed)
	{
		return;
	}

	set_size(new_size);

	beginResetModel();

	m_grid_buffer.clear();
	m_rows_sums.clear();
	m_cols_sums.clear();

	m_grid_buffer.fill(NO_VALUE, new_size * new_size);
	m_rows_sums.fill(NO_VALUE, new_size);
	m_cols_sums.fill(NO_VALUE, new_size);

	reset_cell_statuses();

	endResetModel();
}

auto MainModule::load_grid(const QList<int>& grid_buffer, const QList<int>& rows_sums, const QList<int>& cols_sums) -> void
{
	clear();

	const size_t new_size = rows_sums.size();
	resize(new_size);

	set_grid_buffer(grid_buffer);
	set_rows_sums(rows_sums);
	set_cols_sums(cols_sums);
	reset_cell_statuses();
}

auto MainModule::update_grid(const int index, const int value) -> void
{
	m_grid_buffer[index] = value;
	emit grid_buffer_changed();

	reset_cell_statuses();
}

auto MainModule::update_col_sum(const int col, const int value) -> void
{
	m_cols_sums[col] = value;
	emit cols_sums_changed();

	reset_cell_statuses();
}

auto MainModule::update_row_sum(const int row, const int value) -> void
{
	m_rows_sums[row] = value;
	emit rows_sums_changed();

	reset_cell_statuses();
}

auto MainModule::display_solution() -> Params::SolutionStatus
{
	const bool input_is_complete = check_input_validity();

	if (!input_is_complete)
	{
		return Params::SolutionStatus::INCOMPLETE_INPUT;
	}

	const Params::Input input = convert_input_format();
	const Params::output_t solution = Algorithm::Version2::solve(input);
	const bool solution_is_found = solution.has_value();

	if (!solution_is_found)
	{
		return Params::SolutionStatus::NO_SOLUTION;
	}

	// This call emits a signal that causes the cell to change colors.
	QVariantList converted_solution = convert_solution_format(solution.value());
	set_cell_statuses(converted_solution);

	return Params::SolutionStatus::VALID_SOLUTION;
}

/// @brief  Checks if the input is valid.
/// @return True iff all the cells of the grid and the
///         rows' and columns' sums contain valid numbers.
auto MainModule::check_input_validity() const -> bool
{
	const bool grid_is_valid = std::ranges::count(m_grid_buffer, NO_VALUE) == 0;
	const bool rows_sums_are_valid = std::ranges::count(m_rows_sums, NO_VALUE) == 0;
	const bool cols_sums_are_valid = std::ranges::count(m_cols_sums, NO_VALUE) == 0;

	return grid_is_valid && rows_sums_are_valid && cols_sums_are_valid;
}

/// @brief  Converts the input to a format `Algorithm::version2::solve` can handle.
/// @return The input grid, rows' and columns' sums converted to the correct format.
///
///         Since The `solve` function uses `std::vector` and Qt uses `QList`,
///         the input must be converted before solving.
auto MainModule::convert_input_format() const -> Params::Input
{
	const std::vector rows_sums(m_rows_sums.begin(), m_rows_sums.end());
	const std::vector cols_sums(m_cols_sums.begin(), m_cols_sums.end());

	Params::input_grid_t grid(m_size, std::vector<int>(m_size));

	for (int row = 0; row < m_size; ++row)
	{
		for (int col = 0; col < m_size; ++col)
		{
			grid[row][col] = m_grid_buffer[row * m_size + col];
		}
	}

	const Params::Input converted_input = {.row_sums = rows_sums, .col_sums = cols_sums, .grid = grid};

	return converted_input;
}

auto MainModule::convert_solution_format(const Params::output_grid_t& solution) -> QVariantList
{
	QVariantList converted_output;

	for (std::span<const Params::CellStatus> row : solution)
	{
		for (const Params::CellStatus status : row)
		{
			converted_output.push_back(QVariant::fromValue(status));
		}
	}

	return converted_output;
}

auto MainModule::reset_cell_statuses() -> void
{
	set_cell_statuses(QVariantList(m_grid_buffer.size(), QVariant::fromValue(Params::CellStatus::UNKNOWN)));
}

auto MainModule::get_NO_VALUE() const -> int
{
	return NO_VALUE;
}

auto MainModule::get_size() const -> int
{
	return m_size;
}

auto MainModule::set_size(int new_size) -> void
{
	if (m_size == new_size)
		return;

	m_size = new_size;
	emit size_changed();
}

auto MainModule::get_grid_buffer() const -> QList<int>
{
	return m_grid_buffer;
}

auto MainModule::set_grid_buffer(const QList<int> new_grid_buffer) -> void
{
	if (m_grid_buffer == new_grid_buffer)
	{
		return;
	}

	m_grid_buffer = new_grid_buffer;
	emit grid_buffer_changed();
}

auto MainModule::get_rows_sums() const -> QList<int>
{
	return m_rows_sums;
}

auto MainModule::set_rows_sums(const QList<int> new_rows_sums) -> void
{
	if (m_rows_sums == new_rows_sums)
	{
		return;
	}

	m_rows_sums = new_rows_sums;
	emit rows_sums_changed();
}

auto MainModule::get_cols_sums() const -> QList<int>
{
	return m_cols_sums;
}

auto MainModule::set_cols_sums(const QList<int> new_cols_sums) -> void
{
	if (m_cols_sums == new_cols_sums)
	{
		return;
	}

	m_cols_sums = new_cols_sums;
	emit cols_sums_changed();
}

auto MainModule::get_cell_statuses() const -> QVariantList
{
	return m_cell_statuses;
}

auto MainModule::set_cell_statuses(const QVariantList& new_cell_statuses) -> void
{
	if (m_cell_statuses == new_cell_statuses)
	{
		return;
	}

	m_cell_statuses = new_cell_statuses;
	emit cell_statuses_changed();
}
