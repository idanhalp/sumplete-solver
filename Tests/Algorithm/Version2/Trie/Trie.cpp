#include "Source/Backend/Algorithm/Version2/Utils/Trie/Trie.hpp"
#include "Tests/Algorithm/Version2/Trie/Trie.hpp"

auto TrieTests::initTestCase() -> void
{
	sequence_1 = std::vector<bool>{true, true, false, false, true};
	sequence_2 = std::vector<bool>{false, false, true, true, true};

	trie.insert(sequence_1);
	trie.insert(sequence_2);
}

auto TrieTests::test_1() const -> void
{
	const std::vector subsequence = sequence_1;
	QVERIFY(trie.check_if_prefix_exists(subsequence));
}

auto TrieTests::test_2() const -> void
{
	const std::vector subsequence = sequence_2;
	QVERIFY(trie.check_if_prefix_exists(subsequence));
}

auto TrieTests::test_3() const -> void
{
	const std::vector subsequence{true, true};
	QVERIFY(trie.check_if_prefix_exists(subsequence));
}

auto TrieTests::test_4() const -> void
{
	const std::vector subsequence{false, false};
	QVERIFY(trie.check_if_prefix_exists(subsequence));
}

auto TrieTests::test_5() const -> void
{
	const std::vector subsequence{true, false};
	QVERIFY(!trie.check_if_prefix_exists(subsequence));
}

auto TrieTests::test_6() const -> void
{
	const std::vector subsequence{false, true};
	QVERIFY(!trie.check_if_prefix_exists(subsequence));
}
