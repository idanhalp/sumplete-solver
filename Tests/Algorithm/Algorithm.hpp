#ifndef TESTS_ALGORITHM_HPP
#define TESTS_ALGORITHM_HPP

#include "Source/Backend/Parameters.hpp"
#include <QObject>
#include <QtTest>

class AlgorithmTests : public QObject
{
	Q_OBJECT

private slots:
	auto test_1() -> void;
	auto test_2() -> void;
	auto test_3() -> void;
	auto test_4() -> void;
	auto test_5() -> void;
	auto test_6() -> void;
	auto test_7() -> void;
	auto test_8() -> void;

private:
	auto check_output_validity(const Params::Input& input, const Params::output_t& output) -> bool;
	auto get_actual_row_and_col_sums(const Params::Input& input, const Params::output_grid_t& solution) -> std::pair<std::vector<int>, std::vector<int>>;
};

#endif // TESTS_ALGORITHM_HPP
