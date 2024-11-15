#include "Tests/Algorithm/Algorithm.hpp"
#include "Tests/ValidityChecks/ValidityChecks.hpp"
#include <QtTest>

auto main(const int num_of_arguments, char* arguments[]) -> int
{
	AlgorithmTests algorithm_tests;
	ValidityChecksTests validity_checks_tests;

	const int status = 0
		| QTest::qExec(&algorithm_tests, num_of_arguments, arguments)
		| QTest::qExec(&validity_checks_tests, num_of_arguments, arguments);

	return status;
}
