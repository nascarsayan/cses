---
title: "Bracket Sequences II"
category: "Mathematics"
url: "https://cses.fi/problemset/task/2187"
id: 2187
---

CSES - Bracket Sequences II

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

Your task is to calculate the number of valid bracket sequences of length $n$
when a _prefix_ of the sequence is given.

# Input

The first input line has an integer $n$.

The second line has a string of $k$ characters: the prefix of the sequence.

# Output

Print the number of sequences modulo $10^9+7$.

# Constraints

  * $1 \le k \le n \le 10^6$

# Example

Input:

    
    
    6
    (()
    

Output:

    
    
    2
    

Explanation: There are two possible sequences: `(())()` and `(()())`.

