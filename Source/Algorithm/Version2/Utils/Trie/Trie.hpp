#ifndef TRIE_HPP
#define TRIE_HPP

#include "TrieNode.hpp"
#include <memory>

namespace Algorithm::Version2::Utils
{
	/// A constrained implementation of the trie data structure, that deals with binary numbers.
	/// It helps checking if some set is a subset of some other set that was inserted to the trie.
	/// It is useful to efficiently check whether a subset of a row or a column is part of some set that
	/// adds up to the desired sum.
	/// @example Assume some row has 5 elements, and the only way to achieve its target sum is to take its 
	/// first, third and fourth elements (creating the mask 01101).
	/// If we take the first and third elements (mask 00101), we know this is a subset of a possible solution,
	/// so we should continue searching.
	/// However, if we choose the first and second elements (mask 00011), we can see right away that it is not a subset of a solution,
	/// and prune the search right away.
	class Trie
	{
	public:
		Trie();
		
		~Trie() = default;

		auto insert(unsigned int mask) -> void;

		auto check_if_prefix_exists(unsigned int mask) const -> bool;

	private:
		std::unique_ptr<TrieNode> root;
	};
}

#endif // TRIE_HPP
