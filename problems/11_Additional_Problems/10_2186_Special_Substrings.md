---
title: "Special Substrings"
category: "Additional Problems"
ordered_category: "11_Additional_Problems"
order: 10
id: 2186
url: "https://cses.fi/problemset/task/2186"
---

CSES - Special Substrings

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

A substring is called _special_ if every character that appears in the string
appears the same number of times in the substring.

Your task is to count the number of special substrings in a given string.

# Input

The only input line has a string of length $n$. Every character is between
a...z.

# Output

Print one integer: the number of special substrings.

# Constraints

  * $1 \le n \le 2 \cdot 10^5$

# Example

Input:

    
    
    abccabab
    

Output:

    
    
    5
    

Explanation: The special substrings are `abc`, `cab`, `abccab`, `bccaba` and
`ccabab`.

