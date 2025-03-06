---
title: "Finding Periods"
category: "String Algorithms"
ordered_category: "08_String_Algorithms"
order: 04
id: 1733
url: "https://cses.fi/problemset/task/1733"
---

CSES - Finding Periods

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

A _period_ of a string is a prefix that can be used to generate the whole
string by repeating the prefix. The last repetition may be partial. For
example, the periods of `abcabca` are `abc`, `abcabc` and `abcabca`.

Your task is to find all period lengths of a string.

# Input

The only input line has a string of length $n$ consisting of characters a–z.

# Output

Print all period lengths in increasing order.

# Constraints

  * $1 \le n \le 10^6$

# Example

Input:

    
    
    abcabca
    

Output:

    
    
    3 6 7
    

