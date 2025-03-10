---
title: "Pyramid Array"
category: "Additional Problems"
ordered_category: "11_Additional_Problems"
order: 23
id: 1747
url: "https://cses.fi/problemset/task/1747"
---

CSES - Pyramid Array

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

You are given an array consisting of $n$ distinct integers. On each move, you
can swap any two adjacent values.

You want to transform the array into a _pyramid array_. This means that the
final array has to be first increasing and then decreasing. It is also allowed
that the final array is only increasing or decreasing.

What is the minimum number of moves needed?

# Input

The first input line has an integer $n$: the size of the array.

The next line has $n$ distinct integers $x_1,x_2,\dots,x_n$: the contents of
the array.

# Output

Print one integer: the minimum number of moves.

# Constraints

  * $1 \le n \le 2 \cdot 10^5$
  * $1 \le x_i \le 10^9$

# Example

Input:

    
    
    4
    2 1 5 3
    

Output:

    
    
    1
    

Explanation: You may swap the first two values which creates a pyramid array
$[1,2,5,3]$.

