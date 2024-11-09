#include "Backend/Source/Algorithm/Version2/Utils/Trie/Trie.hpp"
#include "Tests/Algorithm/Version2/Trie/Trie.hpp"
#include <cassert>

auto Tests::Version2::run_trie_tests() -> void
{
	const std::vector sequence_1{true, true, false, false, true};
	const std::vector sequence_2{false, false, true, true, true};
	const std::vector sequences{sequence_1, sequence_2};
	const Algorithm::Version2::Utils::Trie trie(sequences);

	const std::vector subsequence_1 = sequence_1;
	assert(trie.check_if_prefix_exists(subsequence_1));

	const std::vector subsequence_2 = sequence_2;
	assert(trie.check_if_prefix_exists(subsequence_2));

	const std::vector subsequence_3{true, true};
	assert(trie.check_if_prefix_exists(subsequence_3));
	
	const std::vector subsequence_4{false, false};
	assert(trie.check_if_prefix_exists(subsequence_4));
	
	const std::vector subsequence_5{true, false};
	assert(!trie.check_if_prefix_exists(subsequence_5));
	
	const std::vector subsequence_6{false, true};
	assert(!trie.check_if_prefix_exists(subsequence_6));
}
