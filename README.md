# Competitive Programming Algorithm Templates

## Overview
This repository is a comprehensive collection of **contest-ready C++ templates** for over 60 algorithms commonly used in competitive programming. Designed for speed and flexibility, these templates are optimized for use in platforms like Codeforces, AtCoder, LeetCode, and other online judges. Each template includes **fast I/O**, clear comments, and a minimal main function, making them easy to adapt for specific problems.

Whether you're preparing for coding competitions, practicing algorithmic problem-solving, or building a reference library, this repository provides robust, standalone implementations of essential algorithms across multiple categories.

## Features
- **Contest-Ready**: Templates are optimized with fast input/output (`ios_base::sync_with_stdio(false); cin.tie(nullptr);`) to meet strict time limits.
- **Modular Design**: Each algorithm is implemented in a single `.cpp` file, ready to be copied or modified.
- **Clear Documentation**: Inline comments explain key steps, making the code accessible to intermediate and advanced programmers.
- **Broad Coverage**: Includes algorithms from basic data structures to advanced techniques, covering all major competitive programming topics.

## Algorithm Categories and Templates
The repository organizes algorithms into the following categories, with each template implemented in C++:

### 1. Basic Data Structures and Algorithms

### 2. Graph Algorithms

### 3. Tree Algorithms

### 4. Dynamic Programming

### 5. Number Theory and Mathematics

### 6. Greedy Algorithms

### 7. Divide and Conquer

### 8. String Algorithms

### 9. Geometry Algorithms

### 10. Advance Data structures

### 11. Miscellaneous Algorithms

## How to Use
1. **Clone or Download**: Clone the repository or download individual `.cpp` files.
2. **Compile**: Use a C++ compiler (e.g., `g++`) with C++17 or later:
   ```bash
   g++ -std=c++17 -O2 template_name.cpp -o template_name
   ```
3. **Run**: Execute the compiled program and provide input as specified in the main function:
   ```bash
   ./template_name
   ```
4. **Adapt**: Modify the main function or algorithm logic to fit the specific problem. Most templates include a sample input/output format for testing.
5. **Optimize**: Adjust constants (e.g., `mod`, `base`) or data structures based on problem constraints.

## Compilation Notes
- **Requirements**: C++17 or later, standard libraries only (no external dependencies).
- **Optimization**: Use `-O2` for performance. For debugging, add `-g` and remove fast I/O.
- **Input/Output**: Templates use `cin`/`cout` with fast I/O disabled (`ios_base::sync_with_stdio(false)`). For file I/O, modify the main function to use `ifstream`/`ofstream`.

## Example Usage
To use the `binary_search.cpp` template:
1. Compile: `g++ -std=c++17 -O2 binary_search.cpp -o binary_search`
2. Input (example):
   ```
   5
   1 2 3 4 5
   3
   ```
3. Output:
   ```
   2
   ```
4. Modify: Adjust the `binary_search` function to return a different result (e.g., first/last occurrence).

## Contributing
Feel free to submit pull requests or issues for:
- Additional algorithms (e.g., geometric algorithms, randomized algorithms).
- Optimizations or bug fixes.
- Improved documentation or examples.

## Acknowledgments
- Inspired by competitive programming platforms like Codeforces, CodeChef, and LeetCode.

For questions or suggestions, open an issue or contact me.

Happy coding!
