# Edit Distance

[Problem Link](https://cses.fi/problemset/task/1639) | [Solution Link](../../solutions/03_Dynamic_Programming/10_1639_Edit_Distance.cpp)

## TL;DR

The problem is to compute the minimum number of operations (insert, delete, replace) required to transform one string into another. The solution uses dynamic programming to build a 2D table where each cell represents the edit distance between prefixes of the two strings. The time complexity is $O(n \cdot m)$, and the space complexity is also $O(n \cdot m)$, where $n$ and $m$ are the lengths of the two strings.

---

## Problem Overview

The task is to calculate the **edit distance** (also known as Levenshtein distance) between two strings. The edit distance is the minimum number of operations required to transform one string into another. The allowed operations are:

1. **Insert** a character.
2. **Delete** a character.
3. **Replace** a character.

For example, the edit distance between "LOVE" and "MOVIE" is 2, as we can replace 'L' with 'M' and add 'I'.

### Input:
- Two strings, $s_1$ and $s_2$, of lengths $n$ and $m$ respectively ($1 \leq n, m \leq 5000$).

### Output:
- A single integer representing the edit distance between the two strings.

---

## Solution Approach

The solution uses **dynamic programming (DP)** to efficiently compute the edit distance. Here's a detailed breakdown:

### 1. **DP Table Definition**
We define a 2D DP table `dp[i][j]`, where:
- `dp[i][j]` represents the minimum edit distance between the first $i$ characters of `s1` and the first $j$ characters of `s2`.

### 2. **Base Cases**
- If one of the strings is empty, the edit distance is the length of the other string:
  - $dp[i][0] = i$ (requires $i$ deletions to transform `s1[0..i-1]` to an empty string).
  - $dp[0][j] = j$ (requires $j$ insertions to transform an empty string to `s2[0..j-1]`).

### 3. **Recurrence Relation**
For $i > 0$ and $j > 0$, the value of `dp[i][j]` depends on the characters `s1[i-1]` and `s2[j-1]`:
- If `s1[i-1] == s2[j-1]`, no operation is needed, so:
  $$ dp[i][j] = dp[i-1][j-1] $$
- Otherwise, we consider the three possible operations and take the minimum:
  1. **Insert** a character: $dp[i][j-1] + 1$
  2. **Delete** a character: $dp[i-1][j] + 1$
  3. **Replace** a character: $dp[i-1][j-1] + 1$
  $$ dp[i][j] = \min(dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + 1) $$

### 4. **Final Answer**
The final edit distance is stored in `dp[n][m]`, where $n$ and $m$ are the lengths of `s1` and `s2`.

### 5. **Implementation Details**
- The solution initializes the DP table with base cases.
- It iterates through all possible prefixes of `s1` and `s2` to fill the DP table using the recurrence relation.
- Finally, it outputs `dp[n][m]`.

---

## Key Learning Points

1. **Dynamic Programming for String Problems**:
   - Breaking the problem into subproblems (prefixes of strings) is a common approach.
   - The DP table helps in storing intermediate results to avoid redundant computations.

2. **Edit Distance Operations**:
   - Understanding the three operations (insert, delete, replace) is crucial for formulating the recurrence relation.

3. **Efficient Table Filling**:
   - Iterating over the DP table in a systematic way ensures correctness and efficiency.

---

## Common Pitfalls

1. **Off-by-One Errors**:
   - Be careful with 0-based indexing in strings and 1-based indexing in the DP table.

2. **Initialization of Base Cases**:
   - Forgetting to initialize `dp[i][0]` and `dp[0][j]` can lead to incorrect results.

3. **Memory Usage**:
   - For large strings ($n, m \leq 5000$), the $O(n \cdot m)$ space requirement can be significant. Consider space optimization if necessary.

---

## Complexity

### Time Complexity:
- Filling the DP table requires $O(n \cdot m)$ operations, where $n$ and $m$ are the lengths of the two strings.

### Space Complexity:
- The DP table requires $O(n \cdot m)$ space.

---

## Alternative Approaches

1. **Space Optimization**:
   - Instead of maintaining the entire DP table, we can use two 1D arrays (`prev` and `curr`) to store only the current and previous rows of the table. This reduces space complexity to $O(\min(n, m))$.

2. **Recursive Approach with Memoization**:
   - A top-down recursive approach with memoization can also solve the problem, but it may be slower due to function call overhead.

3. **Iterative with String Alignment**:
   - For specific cases, string alignment techniques (e.g., Needleman-Wunsch algorithm) can be applied.

---

## Extended Learning

1. **Applications of Edit Distance**:
   - Spell checking, DNA sequence alignment, and plagiarism detection.

2. **Variants of Edit Distance**:
   - **Hamming Distance**: Only considers substitutions and requires strings to be of equal length.
   - **Damerau-Levenshtein Distance**: Includes transpositions as an additional operation.

3. **String Matching Algorithms**:
   - Explore other string algorithms like KMP, Rabin-Karp, and Z-algorithm.

---

## Tips for Similar Problems

1. **Recognize the Problem Type**:
   - Problems involving transformations between strings often involve DP.

2. **Define Subproblems Clearly**:
   - Focus on prefixes or substrings when defining the DP state.

3. **Optimize for Constraints**:
   - If constraints are large, consider space optimization techniques like rolling arrays.

4. **Practice Variants**:
   - Solve problems with slight variations (e.g., restricted operations) to deepen understanding.