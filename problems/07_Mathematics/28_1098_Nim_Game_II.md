---
title: "Nim Game II"
category: "Mathematics"
ordered_category: "07_Mathematics"
order: 28
id: 1098
url: "https://cses.fi/problemset/task/1098"
---

CSES - Nim Game II

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

There are $n$ heaps of sticks and two players who move alternately. On each
move, a player chooses a non-empty heap and removes $1$, $2$, or $3$ sticks.
The player who removes the last stick wins the game.

Your task is to find out who wins if both players play optimally.

# Input

The first input line contains an integer $t$: the number of tests. After this,
$t$ test cases are described:

The first line contains an integer $n$: the number of heaps.

The next line has $n$ integers $x_1,x_2,\ldots,x_n$: the number of sticks in
each heap.

# Output

For each test case, print "first" if the first player wins the game and
"second" if the second player wins the game.

# Constraints

  * $1 \le t \le 2 \cdot 10^5$
  * $1 \le n \le 2 \cdot 10^5$
  * $1 \le x_i \le 10^9$
  * the sum of all $n$ is at most $2 \cdot 10^5$

# Example

Input:

    
    
    3
    4
    5 7 2 5
    2
    4 1
    3
    4 4 4
    

Output:

    
    
    first
    first
    second
    

