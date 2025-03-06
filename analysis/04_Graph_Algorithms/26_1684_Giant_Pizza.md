# Giant Pizza

[Problem Link](https://cses.fi/problemset/task/1684) | [Solution Link](../../solutions/04_Graph_Algorithms/26_1684_Giant_Pizza.cpp)

## TL;DR

The problem is a variation of the **2-SAT problem**, which can be solved using graph algorithms. Each family member's wishes are treated as logical constraints, and the solution involves constructing an **implication graph** and finding strongly connected components (SCCs) to check for satisfiability. If a valid assignment exists, the graph is used to determine which toppings to include or exclude.

---

## Problem Overview

The task is to decide which toppings to include on a pizza such that at least one wish from every family member is satisfied. Each family member provides two wishes about toppings, either indicating that they like a topping (e.g., "+ 1") or dislike it (e.g., "- 1"). The goal is to determine a valid configuration of toppings or declare that no such configuration is possible.

This is a classic **satisfiability problem** where we need to ensure that a set of logical constraints is satisfied.

---

## Solution Approach

### 1. Problem Representation as a 2-SAT Problem
The problem can be modeled as a **2-SAT problem**, where:
- Each topping has two states: included (`true`) or excluded (`false`).
- Each family member's wishes correspond to a logical clause of the form `(A OR B)`, where:
  - `A` is the first wish (e.g., "+ 1" means topping 1 is included).
  - `B` is the second wish (e.g., "- 2" means topping 2 is excluded).

For example:
- A wish "+ 1 + 2" means `(topping 1 is included) OR (topping 2 is included)`.
- A wish "- 1 + 3" means `(topping 1 is excluded) OR (topping 3 is included)`.

### 2. Implication Graph Construction
The 2-SAT problem can be solved using an **implication graph**, where:
- Each topping `x` has two nodes: `x` (included) and `¬x` (excluded).
- A clause `(A OR B)` is represented as two implications:
  - `¬A → B`
  - `¬B → A`

For example:
- "+ 1 + 2" leads to:
  - `¬1 → 2`
  - `¬2 → 1`
- "- 1 + 3" leads to:
  - `1 → 3`
  - `¬3 → ¬1`

### 3. Finding Strongly Connected Components (SCCs)
To determine satisfiability:
1. Use **Kosaraju's algorithm** or **Tarjan's algorithm** to find SCCs in the implication graph.
2. If a variable `x` and its negation `¬x` belong to the same SCC, the problem is unsatisfiable (i.e., "IMPOSSIBLE").
3. Otherwise, assign truth values to variables based on the topological order of SCCs:
   - If `x` is processed before `¬x`, set `x = true` (include the topping).
   - If `¬x` is processed before `x`, set `x = false` (exclude the topping).

### 4. Constructing the Output
Once a valid assignment is found:
- For each topping, output `+` if it is included (`true`) or `-` if it is excluded (`false`).

---

## Key Learning Points

1. **2-SAT Problem**:
   - The problem is a specific case of the Boolean satisfiability problem (SAT) where each clause has at most two literals.
   - It can be solved efficiently in linear time using graph-based techniques.

2. **Implication Graph**:
   - Logical constraints can be represented as implications in a directed graph.
   - This graph is key to solving the problem using SCCs.

3. **Strongly Connected Components (SCCs)**:
   - SCCs help identify contradictions in the implication graph.
   - Efficient algorithms like Kosaraju's or Tarjan's can compute SCCs in $O(V + E)$ time.

4. **Topological Order for Assignment**:
   - The order of processing SCCs determines the truth assignment for variables.

---

## Common Pitfalls

1. **Incorrect Graph Construction**:
   - Misrepresenting clauses as implications can lead to incorrect results.
   - Ensure that each clause `(A OR B)` is correctly translated into `¬A → B` and `¬B → A`.

2. **Handling Negations**:
   - Properly distinguish between `x` (included) and `¬x` (excluded) when constructing the graph.

3. **Output Format**:
   - Ensure the output matches the required format (`+` for included, `-` for excluded).

4. **Edge Cases**:
   - Single topping with contradictory wishes (e.g., "+ 1 - 1").
   - Large inputs where efficient graph traversal is critical.

---

## Complexity

### Time Complexity
- **Graph Construction**: $O(n)$, where $n$ is the number of family members (each clause adds two edges).
- **SCC Computation**: $O(V + E)$, where $V = 2m$ (two nodes per topping) and $E = 2n$ (two edges per clause).
- **Overall**: $O(n + m)$.

### Space Complexity
- **Graph Storage**: $O(V + E) = O(m + n)$.
- **Auxiliary Storage**: $O(V)$ for SCC computation.

---

## Alternative Approaches

1. **Brute Force**:
   - Try all $2^m$ combinations of toppings and check if all wishes are satisfied.
   - This is infeasible for large values of $m$ due to exponential complexity.

2. **SAT Solvers**:
   - Encode the problem as a general SAT problem and use a SAT solver.
   - This is more general but less efficient than the 2-SAT-specific approach.

---

## Extended Learning

1. **SAT and Variants**:
   - Explore the general SAT problem and its NP-completeness.
   - Study other variants like 3-SAT and k-SAT.

2. **Graph Algorithms**:
   - Learn about SCC algorithms (Kosaraju, Tarjan).
   - Understand topological sorting and its applications.

3. **Applications of 2-SAT**:
   - Scheduling problems.
   - Circuit design and verification.

---

## Tips for Similar Problems

1. **Recognizing 2-SAT Problems**:
   - Look for constraints involving two variables (e.g., "A OR B").
   - Check if the problem can be represented as a satisfiability problem.

2. **Graph Representation**:
   - Practice translating logical constraints into implication graphs.

3. **Efficient SCC Computation**:
   - Familiarize yourself with Kosaraju's and Tarjan's algorithms for SCCs.

4. **Debugging**:
   - Verify the correctness of graph construction before running SCC algorithms.

5. **Edge Cases**:
   - Test with small inputs and edge cases to ensure correctness.