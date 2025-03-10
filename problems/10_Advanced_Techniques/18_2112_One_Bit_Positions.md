---
title: "One Bit Positions"
category: "Advanced Techniques"
ordered_category: "10_Advanced_Techniques"
order: 18
id: 2112
url: "https://cses.fi/problemset/task/2112"
---

CSES - One Bit Positions

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

You are given a binary string of length $n$. Your task is to calculate, for
every $k$ between $1 \ldots n-1$, the number of ways we can choose two
positions $i$ and $j$ such that $i-j=k$ and there is a one-bit at both
positions.

# Input

The only input line has a string that consists only of characters $0$ and $1$.

# Output

For every distance $k$ between $1\ldots n-1$ print the number of ways we can
choose two such positions.

# Constraints

  * $2 \le n \le 2 \cdot 10^5$

# Example

Input:

    
    
    1001011010
    

Output:

    
    
    1 2 3 0 2 1 0 1 0
    

