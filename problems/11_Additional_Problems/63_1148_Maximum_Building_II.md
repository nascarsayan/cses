---
title: "Maximum Building II"
category: "Additional Problems"
ordered_category: "11_Additional_Problems"
order: 63
id: 1148
url: "https://cses.fi/problemset/task/1148"
---

CSES - Maximum Building II

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

You are given a map of a forest where some squares are empty and some squares
have trees.

You want to place a rectangular building in the forest so that no trees need
to be cut down. For each building size, your task is to calculate the number
of ways you can do this.

# Input

The first input line contains integers $n$ and $m$: the size of the forest.

After this, the forest is described. Each square is empty (`.`) or has trees
(`*`).

# Output

Print $n$ lines each containing $m$ integers.

# Constraints

  * $1 \le n,m \le 1000$

# Example

Input:

    
    
    4 7
    ...*.*.
    .*.....
    .......
    ......*
    

Output:

    
    
    24 17 13 9 6 3 1 
    16 9 7 5 3 1 0 
    9 3 2 1 0 0 0 
    3 0 0 0 0 0 0
    

Explanation: For example, there are $5$ possible places for a building of size
$2 \times 4$.

