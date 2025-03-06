# Chessboard and Queens

## TL;DR
This problem involves placing eight queens on a chessboard such that no two queens are attacking each other, considering some squares are reserved. The solution uses backtracking to explore all possible placements and count the valid ones.

## Problem Summary
[Problem Link](https://cses.fi/problemset/task/1624)

Your task is to place eight queens on a chessboard so that no two queens are attacking each other. Each square is either free (.) or reserved (*), and you can only place queens on the free squares. How many possible ways are there to place the queens?

## Approach
The approach to solve this problem is straightforward:

1. Use a backtracking function to explore all possible placements of the queens.
2. The base case is when all eight queens have been placed, and the placement is valid.
3. For each square, recursively consider placing a queen if it is free and does not result in an attack.
4. Count the number of valid placements.

## Solution Analysis
[Solution Link](/solutions/01_Introductory_Problems/17_1624_Chessboard_and_Queens.py)

```python
from typing import List, Tuple
def piece(board: List[List[str]], idx: Tuple[int, int]):
  return board[idx[0]][idx[1]]
def idxToInt(idx: Tuple[int, int]): return 8*idx[0]+idx[1]
def intToIdx(val: int): return (val // 8, val % 8)
def backtrack(board: List[List[str]], qPos: List[Tuple[int, int]], idx: Tuple[int, int]):
  if piece(board, idx) == '*':
    return 0
  for q in qPos:
    r1, c1 = q
    r2, c2 = idx
    d1, d2 = abs(r2-r1), abs(c2-c1)
    if d1 == 0 or d2 == 0 or (d1 == d2):
      return 0
  if len(qPos) == 7:
    return 1
  res = 0
  for nex in range(idxToInt(idx) + 1, 64):
    res += backtrack(board, qPos + [idx], intToIdx(nex))
  return res
def solve(board: List[List[str]]):
  res = 0
  for i in range(64):
    res += backtrack(board, [], intToIdx(i))
  return res
board = []
for i in range(8):
  board.append(list(input().strip()))
print(solve(board))
```

The solution works as follows:
1. Define a backtracking function backtrack to explore all possible placements of the queens.
2. If the current square is reserved, return 0.
3. Check if the current placement results in an attack with any previously placed queens. If so, return 0.
4. If all eight queens have been placed, return 1.
5. Recursively consider placing a queen in the next square and count the number of valid placements.
6. Define a solve function to initialize the board and call the backtracking function for each square.
7. Read the input board and print the number of valid placements.

## Time and Space Complexity
- **Time Complexity**: O(8!) for the backtracking function, as we explore all possible placements of the queens.
- **Space Complexity**: O(8) for storing the positions of the queens.

## Key Insights
1. This problem teaches us to handle backtracking algorithms and use them to explore all possible placements efficiently.
2. It emphasizes the importance of understanding backtracking and its applications.
3. The problem is a good exercise in backtracking and problem-solving techniques.

## Common Pitfalls
1. Forgetting to handle the case where the current square is reserved.
2. Incorrectly implementing the backtracking function without handling the attacks correctly.
3. Not handling the input parsing correctly.

## Extensions
1. What if we need to place more than eight queens? The approach would be more complex and require different algorithms.
2. What if the board has different properties? The solution would still work, but we need to adjust the conditions accordingly.
3. What if we need to find the number of ways to place the queens on a different type of board? The approach would depend on the specific problem constraints.