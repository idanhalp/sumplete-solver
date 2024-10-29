#ifndef TRIE_HPP
#define TRIE_HPP

#include "TrieNode.hpp"
#include <memory>
#include <vector>

/// A constrained implementation of the trie data structure, that deals with binary sequences.
/// It helps checking if some set is a subset of some other set that was inserted to the trie.
/// It is useful to efficiently check whether a subset of a row or a column is part of some set that
/// adds up to the desired sum.
/// @example Assume some row has 5 elements, and the only way to achieve its target sum is to take its 
/// first, third and fourth elements.
/// If we take the first and third elements, we know this is a subset of a possible solution,
/// so we should continue searching.
/// However, if we choose the first and second elements, we can see right away that it is not a subset of a solution,
/// and prune the search.
namespace Algorithm::Version2::Utils
{
	class Trie
	{
	public:
		Trie();

		Trie(const std::vector<std::vector<bool>>& sequences); 

		~Trie() = default;

		auto insert(const std::vector<bool>& sequence) -> void;

		auto check_if_prefix_exists(const std::vector<bool>& sequence) const -> bool;

	private:
		std::unique_ptr<TrieNode> root;
	};
}

#endif // TRIE_HPP
