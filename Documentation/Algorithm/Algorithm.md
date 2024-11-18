# Algorithm
This document aims to explain the algorithm used to solve **Sumplete** puzzles.

## Introduction
The core challenge of this project is to find a reliable way to solve **Sumplete** puzzles.

One can easily solve smaller puzzles using nothing but logical deductions, however this often turns
out to be impractical, as grids can be rather large (9 x 9) and may have very specific solutions -
too much for an average human to handle.

Computers are much harder to overwhelm with calculations and deductions.
Nevertheless, there is a serious challenge in converting logical reasoning
to actual code.

## Analysis of the Problem
Given an ($n$ x $n$) grid,  there exist $2^{n^2}$ possible configurations.
If $n = 9$, this means $2^{81} \approx 2.4e24$ configurations.

This immediately takes a brute force solution out of the picture.
A practical algorithm must scan through a fraction of this search space, otherwise it is going to take some time to solve...

## Idea
The common approach for this type of problems is to perform a brute force scan, and backtrack whenever a dead end is reached.
Identifying such dead ends earlier saves a lot of redundant work. This is also known as [pruning](https://en.wikipedia.org/wiki/Decision_tree_pruning).

The better the pruning is, the faster the algorithm.

## Version I
### Algorithm
We scan the grid in row-major order, looking for unassigned cell.

If no such cell exists, we found a solution.

Otherwise we try including the cell.
If we reached the end of some row (namely `col == n - 1`) or column (namely `row == n - 1`),
we check if the sum of the row/col is the same as the target.
If it is, we continue scanning the grid and check if a solution is found.
If the sum is invalid or a solution was not found, we try discarding the cell and repeat the same process.

If both keeping and discarding the cell fail, we reached a dead end and backtrack.

### Analysis
This version works for smaller grids. Is has however a major flaw: Pruning happens only at the end of rows and columns.
which happens scarcely. Moreover, since we scan in row-major order, columns are ignored until the last row is reached.
The lax pruning makes solving (9 x 9) grids infeasible. In fact, medium level grids of such size can take 20 seconds
to solve, while a masters level runs out of memory and SEGFAULTS.
