# Counting Numbers

[Problem Link](https://cses.fi/problemset/task/2220) | [Solution Link](../../solutions/03_Dynamic_Programming/19_2220_Counting_Numbers.cpp)

## TL;DR

The problem involves counting integers between $a$ and $b$ where no two adjacent digits are the same. The solution uses digit dynamic programming (digit DP) to efficiently calculate the count by breaking the problem into smaller subproblems. This approach avoids iterating through all numbers in the range, which would be infeasible for large inputs like $10^{18}$.

---

## Problem Overview

The task is to count how many integers in the range $[a, b]$ satisfy the condition that no two adjacent digits in the number are the same. For example:
- In the range $[123, 321]$, valid numbers include $123$, $124$, $125$, etc., but not $122$ or $133$.

### Key Challenges:
1. The range $[a, b]$ can be as large as $[0, 10^{18}]$, making brute force solutions infeasible.
2. The problem requires efficiently counting numbers with a specific property (no adjacent digits being the same).

---

## Solution Approach

The solution uses **digit dynamic programming (digit DP)**, a common technique for problems involving properties of digits in numbers. Here's the step-by-step breakdown:

### 1. **Digit DP Overview**
Digit DP is used to count numbers that satisfy certain properties by processing their digits one by one. The key idea is to use a recursive function with memoization to explore all possible valid numbers digit by digit.

### 2. **Breaking Down the Problem**
To count the numbers in the range $[a, b]$, we compute:
$$
\text{count(b)} - \text{count(a-1)}
$$
Where `count(x)` is the number of integers in the range $[0, x]$ that satisfy the condition.

### 3. **Defining the State**
The digit DP state is defined as:
- `pos`: The current digit position being processed (from most significant to least significant).
- `tight`: A boolean indicating whether the current number being formed is "tight" (i.e., still constrained by the digits of $x$).
- `prev_digit`: The digit chosen for the previous position (to ensure no two adjacent digits are the same).

### 4. **Recursive Transition**
For each digit position:
- If `tight` is true, the current digit can only take values up to the corresponding digit in $x$.
- Otherwise, the current digit can take any value from $0$ to $9`.
- Skip any digit that is the same as `prev_digit` to enforce the "no two adjacent digits" condition.

The base case is when all digits are processed (`pos == n`), at which point a valid number is found.

### 5. **Implementation Steps**
1. Convert the number $x$ to a string for easy digit access.
2. Use the recursive DP function to calculate `count(x)`:
   - Start at the most significant digit (`pos = 0`).
   - Initialize `tight` as true and `prev_digit` as -1 (no previous digit yet).
3. Compute the result for $b$ and $a-1$, and subtract.

### 6. **Edge Cases**
- Handle the case when $a = 0$ carefully, as $a-1$ would be negative.
- Ensure leading zeros are managed correctly (e.g., treat them as valid digits when forming numbers).

---

## Key Learning Points

1. **Digit DP**: A powerful technique for solving problems involving digit properties in numbers.
2. **Range Queries**: Breaking down range problems into smaller subproblems using $[0, x]$ queries.
3. **State Representation**: Choosing an appropriate DP state is critical for solving digit DP problems.
4. **Efficiency**: Avoid brute force by leveraging constraints and properties of the problem.

---

## Common Pitfalls

1. **Incorrect State Definition**: Forgetting to include `prev_digit` or `tight` in the state can lead to incorrect results.
2. **Handling Leading Zeros**: Not accounting for leading zeros can cause logical errors.
3. **Edge Cases**: Failing to handle cases like $a = 0$ or $a = b$ properly.
4. **Overlapping Subproblems**: Not using memoization can lead to redundant computations and inefficiency.

---

## Complexity

### Time Complexity:
The time complexity is approximately:
$$
O(\text{number of digits in } b \times 10 \times 2)
$$
- `number of digits in b`: The maximum depth of recursion is the number of digits in $b$ (at most 18 for $10^{18}$).
- `10`: At each digit position, we try up to 10 possible digits.
- `2`: The `tight` state doubles the number of subproblems.

Thus, the complexity is $O(18 \times 10 \times 2) = O(360)$ for each `count(x)` computation.

### Space Complexity:
The space complexity is $O(\text{number of digits in } b \times 10 \times 2)$ for the DP table, which is small and manageable.

---

## Alternative Approaches

1. **Brute Force**:
   - Iterate through all numbers in the range $[a, b]$ and check if each number satisfies the condition.
   - This is infeasible for large ranges like $[0, 10^{18}]$ due to the sheer size of the range.

2. **Iterative DP**:
   - Instead of recursion, use an iterative approach to fill the DP table.
   - This is less intuitive for digit DP problems but can be used in some cases.

---

## Extended Learning

1. **Other Digit DP Problems**:
   - Counting numbers with a specific digit sum.
   - Counting numbers with a specific digit frequency.
   - Counting palindromic numbers in a range.

2. **General DP Concepts**:
   - Memoization and state representation.
   - Transition functions in dynamic programming.

3. **Range Queries**:
   - Techniques to handle range problems efficiently, such as prefix sums or breaking ranges into smaller parts.

---

## Tips for Similar Problems

1. **Recognize Digit Constraints**:
   - If the problem involves properties of digits (e.g., adjacent digits, digit sums), consider digit DP.

2. **Break Down the Range**:
   - For range problems, compute results for $[0, b]$ and $[0, a-1]$ to simplify the calculation.

3. **Define the State Clearly**:
   - Ensure the DP state captures all necessary information (e.g., current position, tightness, previous digit).

4. **Start Small**:
   - Test your approach on small inputs to validate the logic before scaling to larger inputs.

5. **Use Memoization**:
   - Avoid recomputing results for the same state by caching results in a DP table.