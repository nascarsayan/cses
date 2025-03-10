---
title: "Robot Path"
category: "Additional Problems"
ordered_category: "11_Additional_Problems"
order: 45
id: 1742
url: "https://cses.fi/problemset/task/1742"
---

CSES - Robot Path

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

You are given a description of a robot's path. The robot begins at point
$(0,0)$ and performs $n$ commands. Each command moves the robot some distance
up, down, left or right.

The robot will stop when it has performed all commands, or immediately when it
returns to a point that it has already visited. Your task is to calculate the
total distance the robot moves.

# Input

The first input line has an integer $n$: the number of commands.

After that, there are $n$ lines describing the commands. Each line has a
character $d$ and an integer $x$: the robot moves the distance $x$ to the
direction $d$. Each direction is U (up), D (down), L (left), or R (right).

# Output

Print the total distance the robot moves.

# Constraints

  * $1 \le n \le 10^5$
  * $1 \le x \le 10^6$

# Example

Input:

    
    
    5
    U 2
    R 3
    D 1
    L 5
    U 2
    

Output:

    
    
    9
    

