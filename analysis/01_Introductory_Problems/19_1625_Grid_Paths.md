# Grid Paths

## TL;DR
This problem involves finding the number of paths in a 7x7 grid from the upper-left square to the lower-left square, given a path description that may contain wildcards. The solution uses depth-first search (DFS) to explore all possible paths and count the valid ones.

## Problem Summary
[Problem Link](https://cses.fi/problemset/task/1625)

There are 88418 paths in a 7x7 grid from the upper-left square to the lower-left square. Each path corresponds to a 48-character description consisting of characters `D` (down), `U` (up), `L` (left), and `R` (right). You are given a description of a path which may also contain characters `?` (any direction). Your task is to calculate the number of paths that match the description.

## Approach
The approach to solve this problem is straightforward:

1. Use a depth-first search (DFS) function to explore all possible paths in the grid.
2. The base case is when the path description is fully matched, and the current position is the lower-left square.
3. For each step, recursively consider all possible directions if the current character is a wildcard, or the specified direction if it is not.
4. Count the number of valid paths.

## Solution Analysis
[Solution Link](/solutions/01_Introductory_Problems/19_1625_Grid_Paths.py)

```python
from typing import List, Tuple
dirs = [(-1, -1), (-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1)]
ch2dirIdx = { 'U': 1, 'R': 3, 'D': 5, 'L': 7 }
def dfs(board: List[List[int]], boardIdx: Tuple[int, int], path: str, pathIdx: int) -> int:
  def exist(*idcs: Tuple[int, int]):
    for (r, c) in idcs:
      if not (0 <= r < 7 and 0 <= c < 7):
        return False
    return True
  def visited(idx: Tuple[int, int]):
    nonlocal board
    if not exist(idx):
      return True
    return board[idx[0]][idx[1]] == 1
  def setSquare(idx: Tuple[int, int], val: int):
    nonlocal board
    board[idx[0]][idx[1]] = val
  
  if not exist(boardIdx):
    return 0
  if visited(boardIdx):
    return 0
  if pathIdx == len(path):
    if boardIdx == (6, 0):
      return 1
    return 0
  if boardIdx == (6, 0):
    return 0
  r, c = boardIdx
  N = [(r+dr, c+dc) for (dr, dc) in dirs]
  for diag in range(0, 7, 2):
    if exist(N[diag]) and visited(N[diag]) and all(not visited(i) for i in (N[diag-1], N[diag+1])):
      return 0
  if visited(N[1]) == visited(N[5]) and visited(N[3]) == visited(N[7]):
    if visited(N[1]) == (not visited(N[3])):
      return 0
  
  setSquare(boardIdx, 1)
  ch = path[pathIdx]
  nextBoardIdcs = [N[1], N[3], N[5], N[7]]
  if ch != '?':
    nextBoardIdcs = [N[ch2dirIdx[ch]]]
  res = 0
  for nextBoardIdx in nextBoardIdcs:
    if visited(nextBoardIdx):
      continue
    res += dfs(board, nextBoardIdx, path, pathIdx+1)
  setSquare(boardIdx, 0)
  return res
path = input().strip()
res = dfs([[0] * 7 for _ in range(7)], (0, 0), path, 0)
print(res)
```

The solution works as follows:
1. Define a depth-first search (DFS) function dfs to explore all possible paths in the grid.
2. Check if the current position is valid and not visited.
3. If the path description is fully matched and the current position is the lower-left square, return 1.
4. If the current position is the lower-left square but the path is not fully matched, return 0.
5. For each step, recursively consider all possible directions if the current character is a wildcard, or the specified direction if it is not.
6. Count the number of valid paths and return the result.
7. Read the input path description and call the dfs function to print the number of valid paths.

## Time and Space Complexity
- **Time Complexity**: O(4^48) for the DFS function, as we explore all possible paths in the grid.
- **Space Complexity**: O(7x7) for storing the grid and the visited positions.

## Key Insights
1. This problem teaches us to handle depth-first search (DFS) algorithms and use them to explore all possible paths efficiently.
2. It emphasizes the importance of understanding DFS and its applications.
3. The problem is a good exercise in DFS and problem-solving techniques.

## Common Pitfalls
1. Forgetting to handle the case where the current position is invalid or visited.
2. Incorrectly implementing the DFS function without handling the wildcards correctly.
3. Not handling the input parsing correctly.

## Extensions
1. What if we need to find the number of paths in a different type of grid? The approach would depend on the specific grid and its properties.
2. What if the path description contains different characters? The solution would still work, but we need to adjust the DFS function accordingly.
3. What if we need to find the number of paths with specific properties? The approach would depend on the specific problem constraints.