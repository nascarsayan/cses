---
title: "Two Sets II"
category: "Dynamic Programming"
ordered_category: "03_Dynamic_Programming"
order: 14
id: 1093
url: "https://cses.fi/problemset/task/1093"
---

CSES - Two Sets II

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

Your task is to count the number of ways numbers $1,2,\ldots,n$ can be divided
into two sets of equal sum.

For example, if $n=7$, there are four solutions:

  * $\\{1,3,4,6\\}$ and $\\{2,5,7\\}$
  * $\\{1,2,5,6\\}$ and $\\{3,4,7\\}$
  * $\\{1,2,4,7\\}$ and $\\{3,5,6\\}$
  * $\\{1,6,7\\}$ and $\\{2,3,4,5\\}$

# Input

The only input line contains an integer $n$.

# Output

Print the answer modulo $10^9+7$.

# Constraints

  * $1 \le n \le 500$

# Example

Input:

    
    
    7
    

Output:

    
    
    4
    

