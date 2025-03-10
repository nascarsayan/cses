---
title: "Inverse Inversions"
category: "Additional Problems"
ordered_category: "11_Additional_Problems"
order: 19
id: 2214
url: "https://cses.fi/problemset/task/2214"
---

CSES - Inverse Inversions

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

Your task is to create a permutation of numbers $1,2,\dots,n$ that has exactly
$k$ inversions.

An inversion is a pair $(a,b)$ where $a<b$ and $p_a>p_b$ where $p_i$ denotes
the number at position $i$ in the permutation.

# Input

The only input line has two integers $n$ and $k$.

# Output

Print a line that contains the permutation. You can print any valid solution.

# Constraints

  * $1 \le n \le 10^6$
  * $0 \le k \le \frac{n(n-1)}{2}$

# Example

Input:

    
    
    5 4
    

Output:

    
    
    1 5 2 4 3
    

