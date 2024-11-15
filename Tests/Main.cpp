#include "Tests/Algorithm/Algorithm.hpp"
#include "Tests/ValidityChecks/ValidityChecks.hpp"
#include <QtTest>

auto main(const int num_of_arguments, char* arguments[]) -> int
{
	const auto run = [&] <typename TEST> (TEST test) -> int { return QTest::qExec(&test, num_of_arguments, arguments); };

	const int status = 0
		| run(AlgorithmTests())
		| run(ValidityChecksTests());

	return status;
}
