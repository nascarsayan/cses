---
title: "Writing Numbers"
category: "Additional Problems"
ordered_category: "11_Additional_Problems"
order: 28
id: 1086
url: "https://cses.fi/problemset/task/1086"
---

CSES - Writing Numbers

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

You would like to write a list of positive integers $1,2,3,\ldots$ using your
computer. However, you can press each key $0$–$9$ at most $n$ times during the
process.

What is the last number you can write?

# Input

The only input line contains the value of $n$.

# Output

Print the last number you can write.

# Constraints

  * $1 \le n \le 10^{18}$

# Example

Input:

    
    
    5
    

Output:

    
    
    12
    

Explanation: You can write the numbers $1,2,\ldots,12$. This requires that you
press key $1$ five times, so you cannot write the number $13$.

