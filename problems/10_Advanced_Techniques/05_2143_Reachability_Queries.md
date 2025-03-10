---
title: "Reachability Queries"
category: "Advanced Techniques"
ordered_category: "10_Advanced_Techniques"
order: 05
id: 2143
url: "https://cses.fi/problemset/task/2143"
---

CSES - Reachability Queries

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

A directed graph consists of $n$ nodes and $m$ edges. The edges are numbered
$1,2,\dots,n$.

Your task is to answer $q$ queries of the form "can you reach node $b$ from
node $a$?"

# Input

The first input line has three integers $n$, $m$ and $q$: the number of nodes,
edges and queries.

Then there are $m$ lines describing the edges. Each line has two distinct
integers $a$ and $b$: there is an edge from node $a$ to node $b$.

Finally there are $q$ lines describing the queries. Each line consists of two
integers $a$ and $b$: "can you reach node $b$ from node $a$?"

# Output

Print the answer for each query: either "YES" or "NO".

# Constraints

  * $1 \le n \le 5 \cdot 10^4$
  * $1 \le m,q \le 10^5$

# Example

Input:

    
    
    4 4 3
    1 2
    2 3
    3 1
    4 3
    1 3
    1 4
    4 1
    

Output:

    
    
    YES
    NO
    YES
    

