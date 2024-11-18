# sumplete-solver
## What is the purpose of this project?
This project aims to provide a fast and easy-to-use solver for [Sumplete](https://sumplete.com/).

You can access the solver [here](link_to_solver).

## What is Sumplete?
Sumplete is a logic puzzle.
### Input
* A square grid filled with numbers.
* A target sum for each row and column.
### Objective
Decide which numbers to keep and which to delete so that the remaining numbers in each row and column add up to their target sum.

You can read more about the rules from the [original site](https://sumplete.com/) or from this repo's [documentation about them](link_to_rules_documentation).

## How to use the solver?
The solver can be accessed [here](link_to_solver).

Fill the grid, rows' sums and columns' sums with numbers, and press the 'solve' button. If the puzzle has a solution, the cells will be colored with green and red: The green cells are to be kept, and the red cells are to be discarded.

An additional feature of inserting a puzzle by its ID is planned for a future version.

You can read more about using the solver [here](link_solver_usage_documentation).

## Which technologies were used to create the solver?
The solver is written in C++, using the Qt framework for implementing the GUI.

Utilization of C++ combined with a practical and efficient algorithm enables the solver to find a solution with great speed and minimal memory usage.
Modern C++ standard (C++23) helps keep the program safe, while not diminishing its efficiency.

You can read more about the algorithms used to solve the puzzle [here](link_to_algorithm_documentation).
