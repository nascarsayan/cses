---
title: "Moving Robots"
category: "Mathematics"
ordered_category: "07_Mathematics"
order: 23
id: 1726
url: "https://cses.fi/problemset/task/1726"
---

CSES - Moving Robots

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

Each square of an $8 \times 8$ chessboard has a robot. Each robot
independently moves $k$ steps, and there can be many robots on the same
square.

On each turn, a robot moves one step left, right, up or down, but not outside
the board. It randomly chooses a direction among those where it can move.

Your task is to calculate the expected number of _empty_ squares after $k$
turns.

# Input

The only input line has an integer $k$.

# Output

Print the expected number of empty squares rounded to six decimal places
(rounding half to even).

# Constraints

  * $1 \le k \le 100$

# Example

Input:

    
    
    10
    

Output:

    
    
    23.120740
    

