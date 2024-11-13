#ifndef SOURCE_FRONTEND_MAIN_MODULE_HPP
#define SOURCE_FRONTEND_MAIN_MODULE_HPP

#include <QAbstractListModel>
#include <QList>
#include <QtQml/qqml.h>

class MainModule : public QAbstractListModel
{
	Q_OBJECT
	QML_ELEMENT
	Q_PROPERTY(int size READ size  WRITE setSize  NOTIFY sizeChanged FINAL)

public:
	MainModule();

	int rowCount(const QModelIndex &parent) const override;
	QVariant data(const QModelIndex &index, int role) const override;
	bool removeRows(int row, int count, const QModelIndex &parent) override;
	QHash<int, QByteArray> roleNames() const override;

	int size() const;
	void setSize(int newSize);

public slots:
	auto resize(int new_size) -> void;

signals:
	void sizeChanged();

private:
	QList<QString> m_grid_buffer; // Flattened grid.
	QList<QString> m_rows_sums;
	QList<QString> m_cols_sums;

	// QAbstractItemModel interface
	int m_size;
};

#endif // SOURCE_FRONTEND_MAIN_MODULE_HPP
