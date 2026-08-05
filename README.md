#  Algorithms & Data Structures

Welcome to my Algorithm repository! This project serves as my personal knowledge base and code archive for learning and implementing various algorithms and data structures. 

🎓 **Special Background:**
The contents of this repository are the result of **taking Algorithm courses from both the Computer Science and Mathematics departments simultaneously**. This dual perspective allows me to bridge rigorous mathematical theory and proofs with practical, high-performance computational implementations.

The implementations here are primarily written in **C++ (70%)** and **Python (30%)**, focusing on performance, readability, and problem-solving techniques.

## 📂 Repository Structure

I have categorized my learning into the following core topics:

*   **[dp_greedy](./dp_greedy)**: 
    *   Implementations of Dynamic Programming (DP) and Greedy algorithms.
    *   Solving optimization problems with overlapping subproblems and optimal substructure.
*   **[graph](./graph)**: 
    *   Graph theory algorithms including Traversal (BFS/DFS), Shortest Path (Dijkstra, Bellman-Ford), and Minimum Spanning Tree (Kruskal, Prim).
*   **[sort](./sort)**: 
    *   Classic sorting algorithms (Merge Sort, Quick Sort, Heap Sort, etc.) with complexity analysis.
*   **[visualization](./visualization)**: 
    *   Scripts and tools used to visualize how these algorithms work step-by-step, making abstract concepts easier to understand.

## 💡 Special Feature: Python vs C++ Guide
Since competitive programming and algorithm design often require choosing the right tool for the job, I have compiled a quick reference guide:
👉 **[python_cpp_guide.md](./python_cpp_guide.md)** 
*A comparative guide focusing on syntax, standard libraries, and performance tips when switching between Python and C++ for algorithms.*

## 🛠️ How to Compile & Run (C++)

For the C++ files, you can easily compile and run them using `g++` via the terminal:

```bash
# Example for compiling a sorting algorithm
g++ -std=c++17 -O2 sort/merge_sort.cpp -o merge_sort
./merge_sort
