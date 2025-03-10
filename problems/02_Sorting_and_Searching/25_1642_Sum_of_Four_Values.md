---
title: "Sum of Four Values"
category: "Sorting and Searching"
ordered_category: "02_Sorting_and_Searching"
order: 25
id: 1642
url: "https://cses.fi/problemset/task/1642"
---

CSES - Sum of Four Values

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

You are given an array of $n$ integers, and your task is to find four values
(at distinct positions) whose sum is $x$.

# Input

The first input line has two integers $n$ and $x$: the array size and the
target sum.

The second line has $n$ integers $a_1,a_2,\dots,a_n$: the array values.

# Output

Print four integers: the positions of the values. If there are several
solutions, you may print any of them. If there are no solutions, print
`IMPOSSIBLE`.

# Constraints

  * $1 \le n \le 1000$
  * $1 \le x,a_i \le 10^9$

# Example

Input:

    
    
    8 15
    3 2 5 8 1 3 2 3
    

Output:

    
    
    2 4 6 7
    

