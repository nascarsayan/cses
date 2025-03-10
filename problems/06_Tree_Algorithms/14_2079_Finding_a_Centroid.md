---
title: "Finding a Centroid"
category: "Tree Algorithms"
ordered_category: "06_Tree_Algorithms"
order: 14
id: 2079
url: "https://cses.fi/problemset/task/2079"
---

CSES - Finding a Centroid

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

Given a tree of $n$ nodes, your task is to find a _centroid_ , i.e., a node
such that when it is appointed the root of the tree, each subtree has at most
$\lfloor n/2 \rfloor$ nodes.

# Input

The first input line contains an integer $n$: the number of nodes. The nodes
are numbered $1,2,…,n$.

Then there are $n-1$ lines describing the edges. Each line contains two
integers $a$ and $b$: there is an edge between nodes $a$ and $b$.

# Output

Print one integer: a centroid node. If there are several possibilities, you
can choose any of them.

# Constraints

  * $1 \le n \le 2 \cdot 10^5$
  * $1 \le a,b \le n$

# Example

Input:

    
    
    5
    1 2
    2 3
    3 4
    3 5
    

Output:

    
    
    3
    

