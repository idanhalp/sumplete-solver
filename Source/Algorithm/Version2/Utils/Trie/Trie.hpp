#ifndef TRIE_HPP
#define TRIE_HPP

#include "Source/Algorithm/Version2/Utils/Trie/TrieNode.hpp"
#include <memory>
#include <vector>

/// A constrained implementation of the trie data structure, that deals with binary sequences.
/// It helps checking if some set is a subset of some other set that was inserted to the trie.
/// It is useful to efficiently check whether a subset of a row or a column is part of some set that
/// adds up to the desired sum.
namespace Algorithm::Version2::Utils
{
	class Trie
	{
	public:
		Trie();

		// Inserts each sequence to the data structure.
		Trie(const std::vector<std::vector<bool>>& sequences); 

		~Trie() = default;

		Trie(Trie&& trie) = default; // Move constructor.

		auto insert(const std::vector<bool>& sequence) -> void;

		auto check_if_prefix_exists(const std::vector<bool>& sequence) const -> bool;

	private:
		std::unique_ptr<TrieNode> root;
	};
}

#endif // TRIE_HPP
