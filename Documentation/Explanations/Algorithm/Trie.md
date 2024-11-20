# Trie
The document aims to explain about the trie data structure and its use in imlementing the solver.

## Description
Trie is a data structure that specializes in finding if a string is a prefix of a string that was
inserted to it.

You can read more from the Wikipedia page [here](https://en.wikipedia.org/wiki/Trie).

## Purpose
The solver's algorithm uses tries to prune dead ends.

A trie is assigned to each row and column. Representations of the row's (or column's) valid subsets
are inserted to the data structure. This enables us to check after every substitution if the current
configuration is a prefix of a valid subset. If it is not, we backtrack and save much effort.

## Example
Assume we have the row {1, 2, 3}, whose target sum is 3.

The row has 8 subsets:
1. `{}        => {false, false, false} (sum is 0)`
2. `{1}       => {true,  false, false} (sum is 1)`
3. `{2}       => {false, true, false } (sum is 2)`
4. `{1, 2}    => {true,  true, false } (sum is 3)`
5. `{3}       => {false, false, true } (sum is 3)`
6. `{1, 3}    => {true,  false, true } (sum is 4)`
7. `{2, 3}    => {false, true, true  } (sum is 5)`
8. `{1, 2, 3} => {true,  true, true  } (sum is 6)`

Of those, only (4) and (5) are valid.

Let us examine a situation we may encounter during our search:

Assume we chose to discard the first element, so the configuration is `{false}`.
We try both keeping and discarding the second option:
1. If we keep it, our configuration becomes `{false, true}`. Since this is not a prefix of neither of the valid subsets, we know keeping the element is not an option.
2. If we discard it, our configuration becomes `{false, false}`. Since this is a prefix of subset (5), we continue the search from this configuration.

## Conclusion
The trie data structure is vital for making the algorithm fast and the solver usable.
