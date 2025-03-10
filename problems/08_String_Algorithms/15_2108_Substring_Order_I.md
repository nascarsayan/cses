---
title: "Substring Order I"
category: "String Algorithms"
ordered_category: "08_String_Algorithms"
order: 15
id: 2108
url: "https://cses.fi/problemset/task/2108"
---

CSES - Substring Order I

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

You are given a string of length $n$. If all of its distinct substrings are
ordered lexicographically, what is the $k$th smallest of them?

# Input

The first input line has a string of length $n$ that consists of characters
a–z.

The second input line has an integer $k$.

# Output

Print the $k$th smallest distinct substring in lexicographical order.

# Constraints

  * $1 \le n \le 10^5$
  * $1 \le k \le \frac{n(n+1)}{2}$
  * It is guaranteed that $k$ does not exceed the number of distinct substrings.

# Example

Input:

    
    
    babaacbaab
    10
    

Output:

    
    
    aba
    

Explanation: The 10 smallest distinct substrings in order are a, aa, aab, aac,
aacb, aacba, aacbaa, aacbaab, ab, and aba.

