#ifndef TRIE_HPP
#define TRIE_HPP

#include "Source/Backend/Algorithm/Version2/Utils/Trie/TrieNode.hpp"
#include <memory>
#include <vector>

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
