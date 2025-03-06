# Apple Division

## TL;DR
This problem involves dividing a set of apples with known weights into two groups such that the difference between the weights of the groups is minimal. The solution uses a recursive approach to explore all possible partitions and find the optimal one.

## Problem Summary
[Problem Link](https://cses.fi/problemset/task/1623)

There are n apples with known weights. Your task is to divide the apples into two groups so that the difference between the weights of the groups is minimal.

## Approach
The approach to solve this problem is straightforward:

1. Use a recursive function to explore all possible partitions of the apples.
2. The base case is when all apples have been considered, and the difference between the weights of the two groups is calculated.
3. For each apple, recursively consider adding it to either group and return the minimum difference.
4. Print the minimum difference.

## Solution Analysis
[Solution Link](/solutions/01_Introductory_Problems/16_1623_Apple_Division.py)

```python
def partition(arr, s1, s2, idx):
  if idx == len(arr):
    return abs(s1 - s2)
  return min(partition(arr, s1+arr[idx], s2, idx+1), partition(arr, s1, s2+arr[idx], idx+1))
n = int(input())
arr = list(map(int, input().strip().split()))
print(partition(arr, 0, 0, 0))
```

The solution works as follows:
1. Define a recursive function partition to explore all possible partitions of the apples.
2. If all apples have been considered, return the absolute difference between the weights of the two groups.
3. For each apple, recursively consider adding it to either group and return the minimum difference.
4. Read the input number n and the weights of the apples.
5. Call the partition function to print the minimum difference.

## Time and Space Complexity
- **Time Complexity**: O(2^n) for the recursive function, as we explore all possible partitions.
- **Space Complexity**: O(n) for the recursion stack.

## Key Insights
1. This problem teaches us to handle recursive algorithms and use them to explore all possible partitions efficiently.
2. It emphasizes the importance of understanding recursion and its applications.
3. The problem is a good exercise in recursion and problem-solving techniques.

## Common Pitfalls
1. Forgetting to handle the base case where all apples have been considered.
2. Incorrectly implementing the recursive function without handling the partitions correctly.
3. Not handling the input parsing correctly.

## Extensions
1. What if we need to divide the apples into more than two groups? The approach would be more complex and require different algorithms.
2. What if the apples have different properties? The solution would still work, but we need to adjust the conditions accordingly.
3. What if we need to find the number of ways to partition the apples? The approach would depend on the specific problem constraints.