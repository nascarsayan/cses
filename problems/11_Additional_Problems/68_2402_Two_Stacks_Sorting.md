---
title: "Two Stacks Sorting"
category: "Additional Problems"
ordered_category: "11_Additional_Problems"
order: 68
id: 2402
url: "https://cses.fi/problemset/task/2402"
---

CSES - Two Stacks Sorting

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

You are given an input list that consists of $n$ numbers. Each integer between
$1$ and $n$ appears exactly once in the list.

Your task is to create a sorted output list using two stacks. On each move you
can do one of the following:

  * Move the first number from the input list to a stack
  * Move a number from a stack to the end of the output list

# Input

The first input line has an integer $n$.

The second line has $n$ integers: the contents of the input list.

# Output

Print $n$ integers: for each number the stack where it is moved ($1$ or $2$).

You can print any valid solution. If there are no solutions, print
`IMPOSSIBLE`.

# Constraints

  * $1 \le n \le 2 \cdot 10^5$

# Example

Input:

    
    
    5
    2 3 1 5 4
    

Output:

    
    
    1 2 1 1 2
    

