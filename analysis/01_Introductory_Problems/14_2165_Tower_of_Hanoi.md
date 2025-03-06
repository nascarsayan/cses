# Tower of Hanoi

## TL;DR
This problem involves solving the Tower of Hanoi puzzle with n disks. The solution uses a recursive approach to determine the sequence of moves that minimizes the number of moves.

## Problem Summary
[Problem Link](https://cses.fi/problemset/task/2165)

The Tower of Hanoi game consists of three stacks (left, middle, and right) and n round disks of different sizes. Initially, the left stack has all the disks, in increasing order of size from top to bottom. The goal is to move all the disks to the right stack using the middle stack. On each move, you can move the uppermost disk from a stack to another stack. It is not allowed to place a larger disk on a smaller disk. Your task is to find a solution that minimizes the number of moves.

## Approach
The approach to solve this problem is straightforward:

1. Use a recursive function to solve the Tower of Hanoi puzzle.
2. The base case is when there is only one disk, which can be moved directly to the target stack.
3. For more than one disk, move the top n-1 disks to the auxiliary stack, move the nth disk to the target stack, and then move the n-1 disks from the auxiliary stack to the target stack.
4. Print the sequence of moves.

## Solution Analysis
[Solution Link](/solutions/01_Introductory_Problems/14_2165_Tower_of_Hanoi.py)

```python
def solve(cnt, st, mid, fl):
  if cnt == 1:
    print(st, fl)
    return
  solve(cnt-1, st, fl, mid)
  print(st, fl)
  solve(cnt-1, mid, st, fl)
n = int(input())
print(2**n-1)
solve(n, 1, 2, 3)
```

The solution works as follows:
1. Define a recursive function solve to solve the Tower of Hanoi puzzle.
2. If there is only one disk, print the move from the start stack to the final stack.
3. For more than one disk, recursively move the top n-1 disks to the auxiliary stack, move the nth disk to the final stack, and then recursively move the n-1 disks from the auxiliary stack to the final stack.
4. Read the input number n and print the total number of moves (2^n - 1).
5. Call the solve function to print the sequence of moves.

## Time and Space Complexity
- **Time Complexity**: O(2^n) for the recursive function, as we make 2^n - 1 moves.
- **Space Complexity**: O(n) for the recursion stack.

## Key Insights
1. This problem teaches us to handle recursive algorithms and use them to solve puzzles efficiently.
2. It emphasizes the importance of understanding recursion and its applications.
3. The problem is a good exercise in recursion and problem-solving techniques.

## Common Pitfalls
1. Forgetting to handle the base case where there is only one disk.
2. Incorrectly implementing the recursive function without handling the auxiliary stack correctly.
3. Not handling the input parsing correctly.

## Extensions
1. What if we need to solve the Tower of Hanoi puzzle with more than three stacks? The approach would be more complex and require different algorithms.
2. What if the disks have different properties? The solution would still work, but we need to adjust the conditions accordingly.
3. What if we need to find the number of moves for a different type of puzzle? The approach would depend on the specific puzzle and its properties.