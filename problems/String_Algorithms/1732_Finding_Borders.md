---
title: "Finding Borders"
category: "String Algorithms"
url: "https://cses.fi/problemset/task/1732"
id: 1732
---

CSES - Finding Borders

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

A _border_ of a string is a prefix that is also a suffix of the string but not
the whole string. For example, the borders of `abcababcab` are `ab` and
`abcab`.

Your task is to find all border lengths of a given string.

# Input

The only input line has a string of length $n$ consisting of characters a–z.

# Output

Print all border lengths of the string in increasing order.

# Constraints

  * $1 \le n \le 10^6$

# Example

Input:

    
    
    abcababcab
    

Output:

    
    
    2 5
    

