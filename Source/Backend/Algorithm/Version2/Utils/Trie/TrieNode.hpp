#ifndef TRIE_NODE_HPP
#define TRIE_NODE_HPP

#include <array>

namespace Algorithm::Version2::Utils
{
	struct TrieNode
	{
		// One child for false (0).
		// One child for true  (1).
		std::array<TrieNode*, 2> children;

		TrieNode()
		{
			children.fill(nullptr);
		}

		~TrieNode()
		{
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
