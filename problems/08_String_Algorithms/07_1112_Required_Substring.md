---
title: "Required Substring"
category: "String Algorithms"
ordered_category: "08_String_Algorithms"
order: 07
id: 1112
url: "https://cses.fi/problemset/task/1112"
---

CSES - Required Substring

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

Your task is to calculate the number of strings of length $n$ having a given
pattern of length $m$ as their substring. All strings consist of characters
A–Z.

# Input

The first input line has an integer $n$: the length of the final string.

The second line has a pattern of length $m$.

# Output

Print the number of strings modulo $10^9+7$.

# Constraints

  * $1 \le n \le 1000$
  * $1 \le m \le 100$

# Example

Input:

    
    
    6
    ABCDB
    

Output:

    
    
    52
    

Explanation: The final string will be of the form ABCDB$x$ or $x$ABCDB where
$x$ is any character between A–Z.

