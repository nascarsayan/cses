---
title: "Labyrinth"
category: "Graph Algorithms"
ordered_category: "04_Graph_Algorithms"
order: 02
id: 1193
url: "https://cses.fi/problemset/task/1193"
---

CSES - Labyrinth

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

You are given a map of a labyrinth, and your task is to find a path from start
to end. You can walk left, right, up and down.

# Input

The first input line has two integers $n$ and $m$: the height and width of the
map.

Then there are $n$ lines of $m$ characters describing the labyrinth. Each
character is `.` (floor), `#` (wall), `A` (start), or `B` (end). There is
exactly one `A` and one `B` in the input.

# Output

First print "YES", if there is a path, and "NO" otherwise.

If there is a path, print the length of the shortest such path and its
description as a string consisting of characters `L` (left), `R` (right), `U`
(up), and `D` (down). You can print any valid solution.

# Constraints

  * $1 \le n,m \le 1000$

# Example

Input:

    
    
    5 8
    ########
    #.A#...#
    #.##.#B#
    #......#
    ########
    

Output:

    
    
    YES
    9
    LDDRRRRRU
    

