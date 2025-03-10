---
title: "Counting Sequences"
category: "Additional Problems"
ordered_category: "11_Additional_Problems"
order: 41
id: 2228
url: "https://cses.fi/problemset/task/2228"
---

CSES - Counting Sequences

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

Your task is to count the number of sequences of length $n$ where each element
is an integer between $1 \dots k$ and each integer between $1 \dots k$ appears
at least once in the sequence.

For example, when $n=6$ and $k=4$, some valid sequences are $[1,3,1,4,3,2]$
and $[2,2,1,3,4,2]$.

# Input

The only input line has two integers $n$ and $k$.

# Output

Print one integer: the number of sequences modulo $10^9+7$.

# Constraints

  * $1 \le k \le n \le 10^6$

# Example

Input:

    
    
    6 4
    

Output:

    
    
    1560
    

