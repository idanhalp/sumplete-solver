#include "Source/Frontend/MainModule/MainModule.hpp"

MainModule::MainModule()
{
	resize(3);
}

int MainModule::rowCount(const QModelIndex& parent) const
{
	Q_UNUSED(parent);

	return m_grid_buffer.count(); // Size.
}

QVariant MainModule::data(const QModelIndex &index, int role) const
{

}

bool MainModule::removeRows(int row, int count, const QModelIndex &parent)
{

}

QHash<int, QByteArray> MainModule::roleNames() const
{
	return {};
}

auto MainModule::resize(const int new_size) -> void
{
	m_size = new_size;
	emit sizeChanged();

	beginResetModel();

	m_grid_buffer.resize(new_size * new_size);

	endResetModel();

	m_rows_sums.resize(new_size);
	m_cols_sums.resize(new_size);
}

int MainModule::size() const
{
	return m_size;
}

void MainModule::setSize(int newSize)
{
	if (m_size == newSize)
		return;

	m_size = newSize;
	emit size();
}
