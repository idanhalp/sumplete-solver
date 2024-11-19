#ifndef SOURCE_PARAMETERS_HPP
#define SOURCE_PARAMETERS_HPP

#include <QObject>
#include <expected>
#include <vector>

namespace Params
{
	Q_NAMESPACE

	const int DEFAULT_GRID_SIZE = 3;

	// Indication whether a cell is included in the sum or omitted from it.
	enum class CellStatus
	{
		KEEP,
		DELETE,
		UNKNOWN
	};

	enum class SolutionStatus
	{
		INCOMPLETE_INPUT,
		INCORRECT_NUMBER_OF_ROWS,
		INCORRECT_NUMBER_OF_COLUMNS,
		GRID_NOT_SQUARED,
		NO_SOLUTION,
		VALID_SOLUTION
	};

	typedef std::vector<std::vector<int>> input_grid_t;
	typedef std::vector<std::vector<CellStatus>> output_grid_t;
	typedef std::expected<output_grid_t, SolutionStatus> output_t;

	struct Input
	{
		std::vector<int> row_sums;
		std::vector<int> col_sums;
		input_grid_t grid;
	};

	Q_ENUM_NS(CellStatus); // Register the enum in meta object data.
}

#endif // SOURCE_PARAMETERS_HPP
