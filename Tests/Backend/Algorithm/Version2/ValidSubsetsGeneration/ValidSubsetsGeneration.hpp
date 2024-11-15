#ifndef TESTS_VALID_SUBSETS_GENERATION_HPP
#define TESTS_VALID_SUBSETS_GENERATION_HPP

namespace Tests::Version2
{
	auto run_valid_subsets_generation_tests() -> void;
}

#include <QObject>
#include <QtTest>
#include <algorithm>
#include <vector>

class ValidSubsetsGenerationTests : public QObject
{
	Q_OBJECT

private slots:
	auto test_1() const -> void;
	auto test_2() const -> void;
	auto test_3() const -> void;

private:
	// Behaves like Python's `sorted(iterable)`.
	// Helps checking if two vectors contain the same elements
	// regardless of their order.
	template <typename T>
	static auto sorted(std::vector<T> elements) -> std::vector<T>
	{
		std::ranges::sort(elements);

		return elements;
	}
};

#endif // TESTS_VALID_SUBSETS_GENERATION_HPP
