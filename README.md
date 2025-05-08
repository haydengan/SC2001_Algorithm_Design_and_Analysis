# SC2001 Algorithm Design and Analysis

This repository contains implementations of core algorithms covered in Lab 1–3 of the Algorithm Design module. 

---

## Lab 1: Merge Sort & Hybrid Sort

### 🔹 Merge Sort
A classic divide-and-conquer algorithm that recursively splits arrays and merges them in sorted order. Time complexity is **O(n log n)** in all cases.

### 🔹 Hybrid Sort
A variation of Merge Sort that switches to Insertion Sort for small subarrays (typically when size ≤ 32), improving real-world performance by reducing recursion overhead.

---

## Lab 2: Dijkstra’s Algorithm

Implements Dijkstra’s shortest path algorithm using a priority queue (min-heap) to efficiently find the shortest path from a source node to all others in a weighted graph with non-negative edge weights.

---

## Lab 3: 0/1 Knapsack Problem

Solves the 0/1 Knapsack problem using two dynamic programming approaches:

### 🔹 Top-Down (Memoization)
- Uses recursion + caching
- Avoids redundant computation
- Easier to understand conceptually

### 🔹 Bottom-Up (Tabulation)
- Builds solution from base cases
- Iterative and efficient
- Better for large inputs due to stack safety
