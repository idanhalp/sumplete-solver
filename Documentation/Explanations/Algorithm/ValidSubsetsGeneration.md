# Valid Subsets Generation
This document aims to explain about the valid subsets generation process.

## Definition
Given a row (or a column) and its target sum, we call a subset of it *valid* if its elements add up
to the target sum.

## Purpose
Finding the valid subsets of some row (or column) can narrow our search, by only looking at choices
that may lead us to the target.

## Implementation
Denote the input's grid size by $n$. Since $n$ is small, we can use brute force force:
We iterate over each subset and check if it is *valid*.

Iterating over all subsets is achieved by looping through the numbers in $[0, 2^{n})$. The $j^{th}$ element
is included in the $i^{th}$ subset iff the $j^{th}$ bit of $i$ is set. Another approach would be using
recursion to generate the subsets, however it is more complex and was discarded.
