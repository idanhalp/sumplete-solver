#include "Algorithm/Algorithm.hpp"
#include "ValidityChecks/ValidityChecks.hpp"
#include <cstdlib>
#include <functional>
#include <print>
#include <string>

struct TestInfo
{
	std::function<void()> test;
	std::string name;
};

auto run_all_tests() -> void
{
	const auto tests = 
	{
		TestInfo(Tests::run_algorithm_tests, "algorithm"),
		TestInfo(Tests::run_validity_checks_tests, "validity checks")
	};

	std::println("\nRunning tests.\n");

	for (const auto& [test, name] : tests)
	{
		std::println("Running {} tests.", name);
		test();
		std::println("All {} tests passed.\n", name);
	}

	std::println("All tests passed!");
}

auto main() -> int
{
	run_all_tests();

	return EXIT_SUCCESS;
}
