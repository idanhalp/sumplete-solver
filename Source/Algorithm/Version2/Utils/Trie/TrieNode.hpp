#ifndef TRIE_NODE_HPP
#define TRIE_NODE_HPP

#include <initializer_list>

namespace Algorithm::Version2::Utils
{
	struct TrieNode
	{
		TrieNode* cleared_bit_child; // If the bit is 0
		TrieNode* set_bit_child;     // If the bit is 1.

		~TrieNode()
		{
			const auto children = {cleared_bit_child, set_bit_child};

			for (TrieNode* child : children)
			{
				const bool child_exists = child != nullptr;

				if (child_exists)
				{
					delete child; // Recursive call to the destructor.
					child = nullptr;
				}
			}
		}
	};	
}

#endif // TRIE_NODE_HPP
