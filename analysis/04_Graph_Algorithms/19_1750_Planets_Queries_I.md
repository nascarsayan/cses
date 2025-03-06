# Planets Queries I

[Problem Link](https://cses.fi/problemset/task/1750) | [Solution Link](../../solutions/04_Graph_Algorithms/19_1750_Planets_Queries_I.cpp)

## TL;DR

The problem is solved using a **binary lifting** technique to efficiently compute the destination planet after $k$ teleporter jumps. Precompute a sparse table that allows jumping powers of 2 steps at a time, reducing the complexity of each query to $O(\log k)$. This approach ensures the solution is efficient even for large constraints.

---

## Problem Overview

You are given $n$ planets, each with a teleporter leading to another planet (possibly itself). For $q$ queries, you need to determine the destination planet after starting at planet $x$ and taking $k$ teleporter jumps. The constraints make it infeasible to simulate $k$ jumps directly, especially when $k$ can be as large as $10^9$.

---

## Solution Approach

The key challenge is efficiently determining the destination planet after $k$ jumps without simulating each jump individually. The solution leverages **binary lifting**, a technique commonly used in graph problems to handle repeated operations over large distances.

### Key Steps:

1. **Binary Lifting Precomputation**:
   - Construct a sparse table where `up[i][j]` represents the planet reached by taking $2^j$ jumps starting from planet $i$.
   - Base case: `up[i][0] = t_i` (1 jump from planet $i$).
   - Recursive relation: 
     $$
     up[i][j] = up[up[i][j-1]][j-1]
     $$
     This means that to take $2^j$ jumps from planet $i$, you first take $2^{j-1}$ jumps to an intermediate planet, then another $2^{j-1}$ jumps.

2. **Query Processing**:
   - For each query $(x, k)$, decompose $k$ into powers of 2 (binary representation).
   - Use the precomputed `up` table to "jump" through the powers of 2. For example, if $k = 13$ (binary: $1101$), compute the destination by combining jumps of $2^3$, $2^2$, and $2^0$.

3. **Efficiency**:
   - Precomputing the `up` table takes $O(n \log n)$ time, as there are $O(\log n)$ levels and $n$ planets.
   - Each query is processed in $O(\log k)$ time, as $k$ is decomposed into at most $\log k$ powers of 2.

### Example Walkthrough:

#### Input:
```
n = 4, q = 3
t = [2, 1, 1, 4]
queries = [(1, 2), (3, 4), (4, 1)]
```

#### Precomputation:
- `up[i][0]` is directly from the input: `[2, 1, 1, 4]`.
- Compute higher powers:
  - `up[i][1]` (2 jumps): `[1, 2, 2, 4]`.
  - `up[i][2]` (4 jumps): `[2, 1, 1, 4]`.

#### Query Processing:
- Query $(1, 2)$:
  - Decompose $2$ into $10_2$: take $2^1$ jump → `up[1][1] = 1`.
- Query $(3, 4)$:
  - Decompose $4$ into $100_2$: take $2^2$ jump → `up[3][2] = 2`.
- Query $(4, 1)$:
  - Decompose $1$ into $1_2$: take $2^0$ jump → `up[4][0] = 4`.

Output: `1, 2, 4`.

---

## Key Learning Points

1. **Binary Lifting**:
   - A powerful technique for efficiently handling repeated operations (e.g., ancestor queries, jumps in graphs).
   - Precomputing powers of 2 allows logarithmic-time queries.

2. **Sparse Table Representation**:
   - Storing intermediate results in a sparse table enables efficient computation of larger steps.

3. **Decomposing Large Numbers**:
   - Representing $k$ as a sum of powers of 2 (binary representation) is a common trick in competitive programming.

---

## Common Pitfalls

1. **Incorrect Base Case**:
   - Ensure `up[i][0]` is initialized correctly from the input array.

2. **Out-of-Bounds Access**:
   - When computing `up[i][j]`, ensure that the intermediate index `up[i][j-1]` is valid.

3. **Handling Large $k$**:
   - Always decompose $k$ into powers of 2 instead of iterating linearly.

4. **Memory Constraints**:
   - The sparse table requires $O(n \log n)$ space, which can be significant for large $n$.

---

## Complexity

### Time Complexity:
- **Precomputation**: $O(n \log n)$ for the sparse table.
- **Query Processing**: $O(\log k)$ per query, for a total of $O(q \log k)$.

### Space Complexity:
- Sparse table: $O(n \log n)$.

---

## Alternative Approaches

1. **Direct Simulation**:
   - Simulate $k$ jumps for each query. This is infeasible for large $k$ due to $O(k)$ complexity per query.

2. **Cycle Detection**:
   - If teleporters form cycles, detect the cycle and reduce $k$ modulo the cycle length. This approach is useful when $k$ is very large, but it requires additional preprocessing.

---

## Extended Learning

1. **Binary Lifting in Trees**:
   - The same technique is used to find the $k$-th ancestor of a node in a tree.

2. **Dynamic Programming on Graphs**:
   - Binary lifting is a form of dynamic programming where results for smaller steps are reused for larger steps.

3. **Cycle Detection Algorithms**:
   - Techniques like Floyd's cycle detection can complement this problem when analyzing teleporter cycles.

---

## Tips for Similar Problems

1. **Look for Repeated Operations**:
   - If a problem involves repeated actions (e.g., jumps, ancestors), consider binary lifting.

2. **Precompute for Efficiency**:
   - Use preprocessing to handle large inputs or queries efficiently.

3. **Decompose Large Numbers**:
   - Represent large numbers in binary to break down operations into manageable steps.

4. **Understand Constraints**:
   - Analyze constraints to decide between simulation, precomputation, or hybrid approaches.