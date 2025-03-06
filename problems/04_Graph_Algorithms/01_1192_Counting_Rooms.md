---
title: "Counting Rooms"
category: "Graph Algorithms"
ordered_category: "04_Graph_Algorithms"
order: 01
id: 1192
url: "https://cses.fi/problemset/task/1192"
---

CSES - Counting Rooms

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

You are given a map of a building, and your task is to count the number of its
rooms. The size of the map is $n \times m$ squares, and each square is either
floor or wall. You can walk left, right, up, and down through the floor
squares.

# Input

The first input line has two integers $n$ and $m$: the height and width of the
map.

Then there are $n$ lines of $m$ characters describing the map. Each character
is either `.` (floor) or `#` (wall).

# Output

Print one integer: the number of rooms.

# Constraints

  * $1 \le n,m \le 1000$

# Example

Input:

    
    
    5 8
    ########
    #..#...#
    ####.#.#
    #..#...#
    ########
    

Output:

    
    
    3
    

