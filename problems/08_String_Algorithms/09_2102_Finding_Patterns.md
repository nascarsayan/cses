---
title: "Finding Patterns"
category: "String Algorithms"
ordered_category: "08_String_Algorithms"
order: 09
id: 2102
url: "https://cses.fi/problemset/task/2102"
---

CSES - Finding Patterns

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

Given a string and patterns, check for each pattern if it appears in the
string.

# Input

The first input line has a string of length $n$.

The next input line has an integer $k$: the number of patterns. Finally, there
are $k$ lines that describe the patterns.

The string and the patterns consist of characters a–z.

# Output

For each pattern, print "YES" if it appears in the string and "NO" otherwise.

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
    ayba
    

Output:

    
    
    YES
    NO
    YES
    

