#include "Trie.hpp"

Algorithm::Version2::Utils::Trie::Trie()
{
	root = std::make_unique<TrieNode>();
}

auto Algorithm::Version2::Utils::Trie::insert(unsigned int mask) -> void
{
	const auto handled_all_set_bits = [&] -> bool { return mask == 0; };
	const auto node_exists = [] (const TrieNode* child) { return child != nullptr; };
	TrieNode* current_node = root.get();

	while (!handled_all_set_bits())
	{
		const bool bit_is_cleared = ((mask & 1) == 0);
		const bool bit_is_set = !bit_is_cleared;

		if (bit_is_set && !node_exists(current_node->set_bit_child))
		{
			current_node->set_bit_child = new TrieNode;
		}
		else if (bit_is_cleared && !node_exists(current_node->cleared_bit_child))
		{
			current_node->cleared_bit_child = new TrieNode;
		}
		
		if (bit_is_set)
		{
			current_node = current_node->set_bit_child;
		}
		else
		{
			current_node = current_node->cleared_bit_child;
		}

		mask >>= 1;
	}
}

auto Algorithm::Version2::Utils::Trie::check_if_prefix_exists(unsigned int mask) const -> bool
{
	const auto handled_all_set_bits = [&] -> bool { return mask == 0; };
	const auto node_exists = [] (const TrieNode* child) { return child != nullptr; };
	TrieNode* current_node = root.get();

	while (!handled_all_set_bits())
	{
		const bool bit_is_cleared = ((mask & 1) == 0);
		const bool bit_is_set = !bit_is_cleared;
		const bool prefix_exists = (bit_is_set && !node_exists(current_node->set_bit_child)) || (bit_is_cleared && !node_exists(current_node->cleared_bit_child));
		
		if (!prefix_exists)
		{
			return false;
		}
		
		if (bit_is_set)
		{
			current_node = current_node->set_bit_child;
		}
		else
		{
			current_node = current_node->cleared_bit_child;
		}

		mask >>= 1;
	}

	return true;
}
