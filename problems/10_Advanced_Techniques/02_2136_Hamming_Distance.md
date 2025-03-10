---
title: "Hamming Distance"
category: "Advanced Techniques"
ordered_category: "10_Advanced_Techniques"
order: 02
id: 2136
url: "https://cses.fi/problemset/task/2136"
---

CSES - Hamming Distance

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

The Hamming distance between two strings $a$ and $b$ of equal length is the
number of positions where the strings differ.

You are given $n$ bit strings, each of length $k$ and your task is to
calculate the minimum Hamming distance between two strings.

# Input

The first input line has two integers $n$ and $k$: the number of bit strings
and their length.

Then there are $n$ lines each consisting of one bit string of length $k$.

# Output

Print the minimum Hamming distance between two strings.

# Constraints

  * $2 \le n \le 2 \cdot 10^4$
  * $1 \le k \le 30$

# Example

Input:

    
    
    5 6
    110111
    001000
    100001
    101000
    101110
    

Output:

    
    
    1
    

Explanation: The strings `101000` and `001000` differ only at the first
position.

