# Palindrome Reorder

## TL;DR
This problem involves reordering the letters of a given string to form a palindrome. The solution uses character frequency counting to determine if a palindrome is possible and constructs it accordingly.

## Problem Summary
[Problem Link](https://cses.fi/problemset/task/1755)

Given a string, your task is to reorder its letters in such a way that it becomes a palindrome (i.e., it reads the same forwards and backwards).

## Approach
The approach to solve this problem is straightforward:

1. Count the frequency of each character in the string.
2. Check if more than one character has an odd frequency. If so, print "NO SOLUTION".
3. Construct the first half of the palindrome using half of the frequency of each character.
4. If there is a character with an odd frequency, place it in the middle.
5. Append the reverse of the first half to complete the palindrome.

## Solution Analysis
[Solution Link](/solutions/01_Introductory_Problems/12_1755_Palindrome_Reorder.py)

```python
from collections import Counter
def toPalin(s: str) -> str:
  cnt = Counter(s)
  if sum(list(map(lambda x: x %2, cnt.values()))) > 1:
    return 'NO SOLUTION'
  dangle = ''
  res = ''
  for ch, freq in cnt.items():
    res += ch * (freq // 2)
    if freq % 2 == 1:
      dangle = ch
  res = res + dangle + res[::-1]
  return res
s = input().strip()
print(toPalin(s))
```

The solution works as follows:
1. Define a function toPalin to convert the string to a palindrome.
2. Count the frequency of each character using the Counter class from the collections module.
3. Check if more than one character has an odd frequency. If so, return "NO SOLUTION".
4. Initialize an empty string for the first half of the palindrome and a variable for the middle character.
5. For each character and its frequency, add half of the frequency to the first half and set the middle character if the frequency is odd.
6. Construct the palindrome by appending the middle character and the reverse of the first half.
7. Read the input string and print the result of toPalin(s).

## Time and Space Complexity
- **Time Complexity**: O(n) for counting the frequencies and constructing the palindrome, where n is the length of the string.
- **Space Complexity**: O(n) for storing the character frequencies and the resulting palindrome.

## Key Insights
1. This problem teaches us to handle character frequencies and use them to determine properties efficiently.
2. It emphasizes the importance of edge cases, such as strings with multiple characters having odd frequencies.
3. The problem is a good exercise in string manipulation and frequency counting techniques.

## Common Pitfalls
1. Forgetting to handle the case where the string has multiple characters with odd frequencies.
2. Incorrectly constructing the palindrome by not handling the middle character correctly.
3. Not handling the input parsing correctly.

## Extensions
1. What if we need to find all possible palindromes? The approach would depend on the specific problem constraints.
2. What if the string contains special characters? The solution would still work, but we need to adjust the frequency counting accordingly.
3. What if we need to find the longest possible palindrome? The approach would depend on the specific problem constraints.