---
title: "Monotone Subsequences"
category: "Additional Problems"
ordered_category: "11_Additional_Problems"
order: 20
id: 2215
url: "https://cses.fi/problemset/task/2215"
---

CSES - Monotone Subsequences

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

Your task is to create a permutation of numbers $1,2,\dots,n$ whose longest
monotone subsequence has exactly $k$ elements.

A monotone subsequence is either increasing or decreasing. For example, some
monotone subsequences in $[2,1,4,5,3]$ are $[2,4,5]$ and $[4,3]$.

# Input

The first input line has an integer $t$: the number of tests.

After this, there are $t$ lines. Each line has two integers $n$ and $k$.

# Output

For each test, print a line that contains the permutation. You can print any
valid solution. If there are no solutions, print `IMPOSSIBLE`.

# Constraints

  * $1 \le t \le 1000$
  * $1 \le k \le n \le 100$

# Example

Input:

    
    
    3
    5 3
    5 2
    7 7
    

Output:

    
    
    2 1 4 5 3
    IMPOSSIBLE
    1 2 3 4 5 6 7
    

