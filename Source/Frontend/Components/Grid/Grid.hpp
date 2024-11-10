#ifndef SOURCE_FRONTEND_COMPONENTS_GRID_HPP
#define SOURCE_FRONTEND_COMPONENTS_GRID_HPP

#include <QList>
#include <QObject>
#include <optional>

namespace Components
{
	class Grid : public QObject
	{
		Q_OBJECT

	public:
		auto operator[](size_t row, size_t col) -> std::optional<int>&;
		auto operator[](size_t row, size_t col) const -> std::optional<int>;

		auto clear_values() -> void;
		auto change_size(const size_t new_size) -> void;

	private:
		QList<QList<std::optional<int>>> data;
	};
}

#endif // SOURCE_FRONTEND_COMPONENTS_GRID_HPP
