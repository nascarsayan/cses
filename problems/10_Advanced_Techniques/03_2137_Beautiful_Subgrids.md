---
title: "Beautiful Subgrids"
category: "Advanced Techniques"
ordered_category: "10_Advanced_Techniques"
order: 03
id: 2137
url: "https://cses.fi/problemset/task/2137"
---

CSES - Beautiful Subgrids

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

You are given an $n \times n$ grid whose each square is either black or white.
A subgrid is called _beautiful_ if its height and width is at least two and
all of its corners are black. How many beautiful subgrids are there within the
given grid?

# Input

The first input line has an integer $n$: the size of the grid.

Then there are $n$ lines describing the grid: `1` means that a square is black
and `0` means it is white.

# Output

Print the number of beautiful subgrids.

# Constraints

  * $1 \le n \le 3000$

# Example

Input:

    
    
    5
    00010
    11111
    00110
    11001
    00010
    

Output:

    
    
    4
    

