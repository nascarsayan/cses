---
title: "Bit Inversions"
category: "Additional Problems"
ordered_category: "11_Additional_Problems"
order: 26
id: 1188
url: "https://cses.fi/problemset/task/1188"
---

CSES - Bit Inversions

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

There is a bit string consisting of $n$ bits. Then, there are some changes
that invert one given bit. Your task is to report, after each change, the
length of the longest substring whose each bit is the same.

# Input

The first input line has a bit string consisting of $n$ bits. The bits are
numbered $1,2,\ldots,n$.

The next line contains an integer $m$: the number of changes.

The last line contains $m$ integers $x_1,x_2,\ldots,x_m$ describing the
changes.

# Output

After each change, print the length of the longest substring whose each bit is
the same.

# Constraints

  * $1 \le n \le 2 \cdot 10^5$
  * $1 \le m \le 2 \cdot 10^5$
  * $1 \le x_i \le n$

# Example

Input:

    
    
    001011
    3
    3 2 5
    

Output:

    
    
    4 2 3
    

Explanation: The bit string first becomes `000011`, then `010011`, and finally
`010001`.

