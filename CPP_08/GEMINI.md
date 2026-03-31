# C++ Module 08 - Templated containers, iterators, and algorithms

This project is part of the 42 school C++ Piscine, focusing on the use of Standard Template Library (STL) containers, iterators, and algorithms in C++98.

## Project Structure

The project is divided into several exercises, each located in its own directory:

### [ex00/](./ex00/) - Easyfind
- **Goal:** Implement a template function `easyfind` that finds the first occurrence of an integer in a container of integers.
- **Key Files:**
  - `easyfind.hpp`: Contains the template function and a custom exception.
  - `main.cpp`: Test cases for different containers (e.g., `std::vector`, `std::list`).

### [ex01/](./ex01/) - Span
- **Goal:** Create a `Span` class that can store a maximum of `N` integers and find the shortest and longest span (difference) between any two numbers stored.
- **Features:**
  - Member function `addNumber` to add a single number.
  - Template member function to add a range of numbers using iterators.
  - `shortestSpan` and `longestSpan` functions.
  - Exception handling for full containers or insufficient elements.
- **Key Files:**
  - `Span.hpp` / `Span.cpp`: The `Span` class implementation.
  - `main.cpp`: Comprehensive tests including large-scale tests (10,000+ elements).

## Building and Running

Each exercise directory contains a `Makefile` with standard rules.

### Prerequisites
- `c++` compiler (supporting C++98)
- `make`

### Commands
Navigate to an exercise directory (e.g., `cd ex00`) and use:

```bash
# Build the executable
make

# Run the program
./easyfind    # for ex00
./span        # for ex01

# Clean object files
make clean

# Clean everything (objects + executable)
make fclean

# Rebuild
make re
```

## Development Conventions

- **Standard:** All code is written in **C++98** as per 42 school requirements.
- **Orthodox Canonical Form:** Classes follow the mandatory structure:
  - Default constructor
  - Copy constructor
  - Copy assignment operator
  - Destructor
- **Naming Convention:**
  - Private member variables are often prefixed with an underscore (e.g., `_maxSize`).
  - Class names follow PascalCase (e.g., `Span`).
- **Exceptions:** Custom exception classes are used for error handling, inheriting from `std::exception`.
- **STL Usage:** Heavy emphasis on using STL algorithms (like `std::find`, `std::sort`, `std::min_element`, `std::max_element`) instead of manual loops where possible.
- **Memory Management:** Use of STL containers (like `std::vector`) ensures safe memory management without manual `new`/`delete` in most cases.
