---
title: "Creating Strings"
category: "Introductory Problems"
ordered_category: "01_Introductory_Problems"
order: 15
id: 1622
url: "https://cses.fi/problemset/task/1622"
---

CSES - Creating Strings

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

Given a string, your task is to generate all different strings that can be
created using its characters.

# Input

The only input line has a string of length $n$. Each character is between a–z.

# Output

First print an integer $k$: the number of strings. Then print $k$ lines: the
strings in alphabetical order.

# Constraints

  * $1 \le n \le 8$

# Example

Input:

    
    
    aabac
    

Output:

    
    
    20
    aaabc
    aaacb
    aabac
    aabca
    aacab
    aacba
    abaac
    abaca
    abcaa
    acaab
    acaba
    acbaa
    baaac
    baaca
    bacaa
    bcaaa
    caaab
    caaba
    cabaa
    cbaaa
    

