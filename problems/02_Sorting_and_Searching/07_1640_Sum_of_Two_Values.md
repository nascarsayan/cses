---
title: "Sum of Two Values"
category: "Sorting and Searching"
ordered_category: "02_Sorting_and_Searching"
order: 07
id: 1640
url: "https://cses.fi/problemset/task/1640"
---

CSES - Sum of Two Values

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

You are given an array of $n$ integers, and your task is to find two values
(at distinct positions) whose sum is $x$.

# Input

The first input line has two integers $n$ and $x$: the array size and the
target sum.

The second line has $n$ integers $a_1,a_2,\dots,a_n$: the array values.

# Output

Print two integers: the positions of the values. If there are several
solutions, you may print any of them. If there are no solutions, print
`IMPOSSIBLE`.

# Constraints

  * $1 \le n \le 2 \cdot 10^5$
  * $1 \le x,a_i \le 10^9$

# Example

Input:

    
    
    4 8
    2 7 5 1
    

Output:

    
    
    2 4
    

