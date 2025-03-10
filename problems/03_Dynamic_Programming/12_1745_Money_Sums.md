---
title: "Money Sums"
category: "Dynamic Programming"
ordered_category: "03_Dynamic_Programming"
order: 12
id: 1745
url: "https://cses.fi/problemset/task/1745"
---

CSES - Money Sums

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

You have $n$ coins with certain values. Your task is to find all money sums
you can create using these coins.

# Input

The first input line has an integer $n$: the number of coins.

The next line has $n$ integers $x_1,x_2,\dots,x_n$: the values of the coins.

# Output

First print an integer $k$: the number of distinct money sums. After this,
print all possible sums in increasing order.

# Constraints

  * $1 \le n \le 100$
  * $1 \le x_i \le 1000$

# Example

Input:

    
    
    4
    4 2 5 2
    

Output:

    
    
    9
    2 4 5 6 7 8 9 11 13
    

