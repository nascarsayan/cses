---
title: "Coin Arrangement"
category: "Additional Problems"
ordered_category: "11_Additional_Problems"
order: 49
id: 2180
url: "https://cses.fi/problemset/task/2180"
---

CSES - Coin Arrangement

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

There is a $2 \times n$ grid whose each cell contains some number of coins.
The total number of coins is $2n$.

Your task is to arrange the coins so that each cell contains exactly one coin.
On each move you can choose any coin and move it one step left, right, up or
down.

What is the minimum number of moves if you act optimally?

# Input

The first input line has an integer $n$: the width of the grid.

After this, there are two lines that describe the grid. Each line has $n$
integers: the number of coins in each cell.

# Output

Print one integer: the minimum number of moves.

# Constraints

  * $1 \le n \le 10^5$

# Example

Input:

    
    
    4
    0 1 0 1
    2 0 1 3
    

Output:

    
    
    5
    

