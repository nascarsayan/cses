---
title: "Digit Queries"
category: "Introductory Problems"
ordered_category: "01_Introductory_Problems"
order: 18
id: 2431
url: "https://cses.fi/problemset/task/2431"
---

CSES - Digit Queries

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

Consider an infinite string that consists of all positive integers in
increasing order:

12345678910111213141516171819202122232425...

Your task is to process $q$ queries of the form: what is the digit at position
$k$ in the string?

# Input

The first input line has an integer $q$: the number of queries.

After this, there are $q$ lines that describe the queries. Each line has an
integer $k$: a $1$-indexed position in the string.

# Output

For each query, print the corresponding digit.

# Constraints

  * $1 \le q \le 1000$
  * $1 \le k \le 10^{18}$

# Example

Input:

    
    
    3
    7
    19
    12
    

Output:

    
    
    7
    4
    1
    

