---
title: "Exponentiation"
category: "Mathematics"
ordered_category: "07_Mathematics"
order: 02
id: 1095
url: "https://cses.fi/problemset/task/1095"
---

CSES - Exponentiation

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

Your task is to efficiently calculate values $a^b$ modulo $10^9+7$.

Note that in this task we assume that $0^0=1$.

# Input

The first input line contains an integer $n$: the number of calculations.

After this, there are $n$ lines, each containing two integers $a$ and $b$.

# Output

Print each value $a^b$ modulo $10^9+7$.

# Constraints

  * $1 \le n \le 2 \cdot 10^5$
  * $0 \le a,b \le 10^9$

# Example

Input:

    
    
    3
    3 4
    2 8
    123 123
    

Output:

    
    
    81
    256
    921450052
    

