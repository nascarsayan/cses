---
title: "Counting Reorders"
category: "Additional Problems"
ordered_category: "11_Additional_Problems"
order: 57
id: 2421
url: "https://cses.fi/problemset/task/2421"
---

CSES - Counting Reorders

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

Calculate the number of ways you can reorder the characters of a string so
that no two adjacent characters are the same.

For example, the answer for `aabc` is $6$, because the possible orders are
`abac`, `abca`, `acab`, `acba`, `baca`, and `caba`.

# Input

The only input line has a string that consists of $n$ characters between
`a`–`z`.

# Output

Print an integer: the answer modulo $10^9+7$.

# Constraints

  * $1 \le n \le 5000$

# Example

Input:

    
    
    aabc
    

Output:

    
    
    6
    

