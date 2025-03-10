---
title: "Removing Digits"
category: "Dynamic Programming"
ordered_category: "03_Dynamic_Programming"
order: 05
id: 1637
url: "https://cses.fi/problemset/task/1637"
---

CSES - Removing Digits

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

You are given an integer $n$. On each step, you may subtract one of the digits
from the number.

How many steps are required to make the number equal to $0$?

# Input

The only input line has an integer $n$.

# Output

Print one integer: the minimum number of steps.

# Constraints

  * $1 \le n \le 10^6$

# Example

Input:

    
    
    27
    

Output:

    
    
    5
    

Explanation: An optimal solution is $27 \rightarrow 20 \rightarrow 18
\rightarrow 10 \rightarrow 9 \rightarrow 0$.

