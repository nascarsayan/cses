---
title: "Cycle Finding"
category: "Graph Algorithms"
ordered_category: "04_Graph_Algorithms"
order: 12
id: 1197
url: "https://cses.fi/problemset/task/1197"
---

CSES - Cycle Finding

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

You are given a directed graph, and your task is to find out if it contains a
negative cycle, and also give an example of such a cycle.

# Input

The first input line has two integers $n$ and $m$: the number of nodes and
edges. The nodes are numbered $1,2,\ldots,n$.

After this, the input has $m$ lines describing the edges. Each line has three
integers $a$, $b$, and $c$: there is an edge from node $a$ to node $b$ whose
length is $c$.

# Output

If the graph contains a negative cycle, print first "YES", and then the nodes
in the cycle in their correct order. If there are several negative cycles, you
can print any of them. If there are no negative cycles, print "NO".

# Constraints

  * $1 \le n \le 2500$
  * $1 \le m \le 5000$
  * $1 \le a,b \le n$
  * $-10^9 \le c \le 10^9$

# Example

Input:

    
    
    4 5
    1 2 1
    2 4 1
    3 1 1
    4 1 -3
    4 3 -2
    

Output:

    
    
    YES
    1 2 4 1
    

