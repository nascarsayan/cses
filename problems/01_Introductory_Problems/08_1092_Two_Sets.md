---
title: "Two Sets"
category: "Introductory Problems"
ordered_category: "01_Introductory_Problems"
order: 08
id: 1092
url: "https://cses.fi/problemset/task/1092"
---

CSES - Two Sets

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

Your task is to divide the numbers $1,2,\ldots,n$ into two sets of equal sum.

# Input

The only input line contains an integer $n$.

# Output

Print "YES", if the division is possible, and "NO" otherwise.

After this, if the division is possible, print an example of how to create the
sets. First, print the number of elements in the first set followed by the
elements themselves in a separate line, and then, print the second set in a
similar way.

# Constraints

  * $1 \le n \le 10^6$

# Example 1

Input:

    
    
    7
    

Output:

    
    
    YES
    4
    1 2 4 7
    3
    3 5 6
    

# Example 2

Input:

    
    
    6
    

Output:

    
    
    NO
    

