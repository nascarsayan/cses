---
title: "Building Roads"
category: "Graph Algorithms"
ordered_category: "04_Graph_Algorithms"
order: 03
id: 1666
url: "https://cses.fi/problemset/task/1666"
---

CSES - Building Roads

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

Byteland has $n$ cities, and $m$ roads between them. The goal is to construct
new roads so that there is a route between any two cities.

Your task is to find out the minimum number of roads required, and also
determine which roads should be built.

# Input

The first input line has two integers $n$ and $m$: the number of cities and
roads. The cities are numbered $1,2,\dots,n$.

After that, there are $m$ lines describing the roads. Each line has two
integers $a$ and $b$: there is a road between those cities.

A road always connects two different cities, and there is at most one road
between any two cities.

# Output

First print an integer $k$: the number of required roads.

Then, print $k$ lines that describe the new roads. You can print any valid
solution.

# Constraints

  * $1 \le n \le 10^5$
  * $1 \le m \le 2 \cdot 10^5$
  * $1 \le a,b \le n$

# Example

Input:

    
    
    4 2
    1 2
    3 4
    

Output:

    
    
    1
    2 3
    

