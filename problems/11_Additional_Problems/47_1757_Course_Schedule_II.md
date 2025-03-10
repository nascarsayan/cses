---
title: "Course Schedule II"
category: "Additional Problems"
ordered_category: "11_Additional_Problems"
order: 47
id: 1757
url: "https://cses.fi/problemset/task/1757"
---

CSES - Course Schedule II

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

You want to complete $n$ courses that have requirements of the form "course
$a$ has to be completed before course $b$".

You want to complete course $1$ as soon as possible. If there are several ways
to do this, you want then to complete course $2$ as soon as possible, and so
on.

Your task is to determine the order in which you complete the courses.

# Input

The first input line has two integers $n$ and $m$: the number of courses and
requirements. The courses are numbered $1,2,\dots,n$.

Then, there are $m$ lines describing the requirements. Each line has two
integers $a$ and $b$: course $a$ has to be completed before course $b$.

You can assume that there is at least one valid schedule.

# Output

Print one line having $n$ integers: the order in which you complete the
courses.

# Constraints

  * $1 \le n \le 10^5$
  * $1 \le m \le 2 \cdot 10^5$
  * $1 \le a,b \le n$

# Example

Input:

    
    
    4 2
    2 1
    2 3
    

Output:

    
    
    2 1 3 4
    

