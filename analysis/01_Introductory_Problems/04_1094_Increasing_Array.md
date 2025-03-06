# Increasing Array

## TL;DR
This problem involves modifying an array to make it non-decreasing by incrementing elements. The solution uses a simple iteration to track the number of increments needed to achieve this.

## Problem Summary
[Problem Link](https://cses.fi/problemset/task/1094)

You are given an array of n integers. You want to modify the array so that it is non-decreasing, i.e., every element is at least as large as the previous element. On each move, you may increase the value of any element by one. What is the minimum number of moves required?

## Approach
The approach to solve this problem is straightforward:

1. Initialize a counter for the number of moves.
2. Iterate through the array from the second element to the end.
3. If the current element is less than the previous element, increment the counter by the difference and set the current element to the previous element's value.
4. Continue this process until the end of the array.
5. The counter will hold the minimum number of moves required.

## Solution Analysis
[Solution Link](/solutions/01_Introductory_Problems/04_1094_Increasing_Array.py)

```python
n = int(input())
res = 0
arr = list(map(int, input().strip().split()))
for i in range(1, n):
  if arr[i] < arr[i-1]:
    res += arr[i-1]-arr[i]
    arr[i] = arr[i-1]
print(res)
```

The solution works as follows:
1. Read the input number n and the array.
2. Initialize the result counter to 0.
3. Iterate through the array starting from the second element.
4. If the current element is less than the previous one, increment the result counter by the difference and set the current element to the previous element's value.
5. Print the result counter.

## Time and Space Complexity
- **Time Complexity**: O(n) where n is the length of the array, as we iterate through the array once.
- **Space Complexity**: O(1) as we only use a few integer variables for counting.

## Key Insights
1. This problem teaches us to handle non-decreasing sequences and use simple iteration to track and update counters.
2. It emphasizes the importance of edge cases, such as the array being already non-decreasing.
3. The problem is a good exercise in array manipulation and basic iteration techniques.

## Common Pitfalls
1. Forgetting to update the current element to the previous element's value.
2. Not handling the case where the array length is 1.
3. Incorrectly incrementing the result counter.

## Extensions
1. What if we need to make the array strictly increasing? We could add a condition to check for equality and increment accordingly.
2. What if we need to minimize the number of decrements instead of increments? The approach would be similar but in reverse.
3. What if the array contains negative numbers? The solution would still work, but we need to handle negative differences.