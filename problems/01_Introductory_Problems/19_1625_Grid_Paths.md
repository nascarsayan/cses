---
title: "Grid Paths"
category: "Introductory Problems"
ordered_category: "01_Introductory_Problems"
order: 19
id: 1625
url: "https://cses.fi/problemset/task/1625"
---

CSES - Grid Paths

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

There are $88418$ paths in a $7 \times 7$ grid from the upper-left square to
the lower-left square. Each path corresponds to a $48$-character description
consisting of characters `D` (down), `U` (up), `L` (left) and `R` (right).

For example, the path
![](/file/3624b569007eb03818b6611755f1bdbe4cdbd0a8334baf9fedc5365914bdd661)
corresponds to the description
`DRURRRRRDDDLUULDDDLDRRURDDLLLLLURULURRUULDLLDDDD`.

You are given a description of a path which may also contain characters `?`
(any direction). Your task is to calculate the number of paths that match the
description.

# Input

The only input line has a $48$-character string of characters `?`, `D`, `U`,
`L` and `R`.

# Output

Print one integer: the total number of paths.

# Example

Input:

    
    
    ??????R??????U??????????????????????????LD????D?
    

Output:

    
    
    201
    

