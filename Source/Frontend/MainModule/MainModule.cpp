#include "Source/Frontend/MainModule/MainModule.hpp"

MainModule::MainModule()
{
	resize(3);
}

auto MainModule::rowCount(const QModelIndex& parent) const -> int
{
	Q_UNUSED(parent);

	return m_grid_buffer.count(); // Size.
}

auto MainModule::data(const QModelIndex& index, int role) const -> QVariant
{

}

auto MainModule::removeRows(int row, int count, const QModelIndex& parent) -> bool
{

}

auto MainModule::roleNames() const -> QHash<int, QByteArray>
{
	return {};
}

auto MainModule::resize(const int new_size) -> void
{
	m_size = new_size;
	emit sizeChanged();

	beginResetModel();

	m_grid_buffer.resize(new_size * new_size);
	m_rows_sums.resize(new_size);
	m_cols_sums.resize(new_size);

	endResetModel();
}

auto MainModule::size() const -> int
{
	return m_size;
}

auto MainModule::setSize(int new_size) -> void
{
	if (m_size == new_size)
		return;

	m_size = new_size;
	emit sizeChanged();
}
