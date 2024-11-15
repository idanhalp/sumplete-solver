#include "Source/Backend/Algorithm/Version2/Utils/ValidSubsetsGeneration/ValidSubsetsGeneration.hpp"
#include "Tests/Algorithm/Version2/ValidSubsetsGeneration/ValidSubsetsGeneration.hpp"

auto ValidSubsetsGenerationTests::test_1() const -> void
{
	const std::vector elements{2, 3, 5};
	const int target_sum = 5;
	const std::vector<std::vector<bool>> expected_valid_subsets
	{
		{true, true, false},
		{false, false, true}
	};

	const std::vector valid_subsets = Algorithm::Version2::Utils::generate_valid_subsets(elements, target_sum);
	QVERIFY(sorted(valid_subsets) == sorted(expected_valid_subsets));
}

auto ValidSubsetsGenerationTests::test_2() const -> void
{
	const std::vector elements{7, 3, 3, 2};
	const int target_sum = 12;
	const std::vector<std::vector<bool>> expected_valid_subsets
	{
		{true, true, false, true},
		{true, false, true, true},
	};

	const std::vector valid_subsets = Algorithm::Version2::Utils::generate_valid_subsets(elements, target_sum);
	QVERIFY(sorted(valid_subsets) == sorted(expected_valid_subsets));
}

auto ValidSubsetsGenerationTests::test_3() const -> void
{
	const std::vector elements{7, 3, 3, 2};
	const int target_sum = 14;
	const std::vector<std::vector<bool>> expected_valid_subsets
	{
	};

	const std::vector valid_subsets = Algorithm::Version2::Utils::generate_valid_subsets(elements, target_sum);
	QVERIFY(sorted(valid_subsets) == sorted(expected_valid_subsets));
}
