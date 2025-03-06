# Repetitions

## TL;DR
This problem involves finding the longest contiguous substring of the same character in a given string. The solution uses a simple iteration to track the length of such substrings and determine the maximum length.

## Problem Summary
[Problem Link](https://cses.fi/problemset/task/1069)

You are given a DNA sequence: a string consisting of characters A, C, G, and T. Your task is to find the longest repetition in the sequence. This is a maximum-length substring containing only one type of character.

## Approach
The approach to solve this problem is straightforward:

1. Initialize two counters: one for the current repetition length and one for the maximum repetition length.
2. Iterate through the string, comparing each character with the previous one.
3. If the characters are the same, increment the current repetition counter.
4. If they are different, update the maximum repetition counter if the current repetition is longer, and reset the current repetition counter.
5. After the loop, ensure to update the maximum repetition counter one last time in case the longest repetition is at the end of the string.

## Solution Analysis
[Solution Link](/solutions/01_Introductory_Problems/03_1069_Repetitions.py)

```python
cnt = 1
res = 1
s = input().strip()
for i in range(1, len(s)):
  if s[i] != s[i-1]:
    res = max(res, cnt)
    cnt = 0
  cnt += 1
res = max(res, cnt)
print(res)
```

The solution works as follows:
1. Initialize `cnt` and `res` to 1, as the minimum repetition length is 1.
2. Read the input string and strip any leading/trailing whitespace.
3. Iterate through the string starting from the second character.
4. If the current character is different from the previous one, update the maximum repetition length and reset the current repetition counter.
5. Increment the current repetition counter.
6. After the loop, update the maximum repetition length one last time.
7. Print the maximum repetition length.

## Time and Space Complexity
- **Time Complexity**: O(n) where n is the length of the string, as we iterate through the string once.
- **Space Complexity**: O(1) as we only use a few integer variables for counting.

## Key Insights
1. This problem teaches us to handle contiguous substrings and use simple iteration to track and update counters.
2. It emphasizes the importance of edge cases, such as the longest repetition being at the end of the string.
3. The problem is a good exercise in string manipulation and basic iteration techniques.

## Common Pitfalls
1. Forgetting to update the maximum repetition length after the loop.
2. Not handling the case where the string length is 1.
3. Incorrectly resetting the current repetition counter.

## Extensions
1. What if we need to find the longest repetition of a specific character? We could add a condition to check for that character.
2. What if we need to find the starting and ending indices of the longest repetition? We could track the indices along with the counters.
3. What if the string contains other characters? We could extend the solution to handle different character sets.