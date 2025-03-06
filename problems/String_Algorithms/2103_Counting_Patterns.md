---
title: "Counting Patterns"
category: "String Algorithms"
url: "https://cses.fi/problemset/task/2103"
id: 2103
---

CSES - Counting Patterns

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

Given a string and patterns, count for each pattern the number of positions
where it appears in the string.

# Input

The first input line has a string of length $n$.

The next input line has an integer $k$: the number of patterns. Finally, there
are $k$ lines that describe the patterns.

The string and the patterns consist of characters a–z.

# Output

For each pattern, print the number of positions.

# Constraints

  * $1 \le n \le 10^5$
  * $1 \le k \le 5 \cdot 10^5$
  * the total length of the patterns is at most $5 \cdot 10^5$

# Example

Input:

    
    
    aybabtu
    3
    bab
    abc
    a
    

Output:

    
    
    1
    0
    2
    

