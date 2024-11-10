#include "Source/Frontend/Components/Grid/Grid.hpp"

auto Components::Grid::operator[](const size_t row, const size_t col) -> std::optional<int>&
{
	return data[row][col];
}

auto Components::Grid::operator[](const size_t row, const size_t col) const -> std::optional<int>
{
	return data[row][col];
}

auto Components::Grid::clear_values() -> void
{
	for (QList<std::optional<int>>& row : data)
	{
		for (std::optional<int>& cell : row)
		{
			cell.reset();
		}
	}
}

auto Components::Grid::change_size(const size_t new_size) -> void
{
	const bool size_changed = data.size() != new_size;

	if (size_changed)
	{
		data.resize(new_size, QList<std::optional<int>>(new_size));
	}
}
