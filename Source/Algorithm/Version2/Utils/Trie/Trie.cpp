#include "Source/Algorithm/Version2/Utils/Trie/Trie.hpp"
#include <algorithm>

Algorithm::Version2::Utils::Trie::Trie()
{
	root = std::make_unique<TrieNode>();
}

Algorithm::Version2::Utils::Trie::Trie(const std::vector<std::vector<bool>>& sequences) : Trie()
{
	std::ranges::for_each(sequences, [&] (const std::vector<bool>& sequence)
	{
		insert(sequence);
	});
}

auto Algorithm::Version2::Utils::Trie::insert(const std::vector<bool>& sequence) -> void
{
	const auto node_exists = [] (const TrieNode* child) { return child != nullptr; };
	TrieNode* current_node = root.get();

	for (const bool element : sequence)
	{
		if (!node_exists(current_node->children[element]))
		{
			current_node->children[element] = new TrieNode;
		}

		current_node = current_node->children[element];
	}
}

auto Algorithm::Version2::Utils::Trie::check_if_prefix_exists(const std::vector<bool>& sequence) const -> bool
{
	const auto node_exists = [] (const TrieNode* child) { return child != nullptr; };
	TrieNode* current_node = root.get();

	for (const bool element : sequence)
	{
		if (!node_exists(current_node->children[element]))
		{
			return false;
		}

		current_node = current_node->children[element];
	}

	return true;
}
