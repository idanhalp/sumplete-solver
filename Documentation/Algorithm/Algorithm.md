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
Given an ($n$ x $n$) grid,  there exists $2^{n^2}$ possible configurations.
If $n = 9$, this means $2^{81} \approx 2.4e24$ configurations.

This immediately take a brute force solution out of the picture.
A practical algorithm must scan through a fraction of this search space, otherwise it is going to take some time to solve...
