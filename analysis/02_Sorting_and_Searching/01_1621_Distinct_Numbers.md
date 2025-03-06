# Distinct Numbers

[Problem Link](https://cses.fi/problemset/task/1621) | [Solution Link](../../solutions/02_Sorting_and_Searching/01_1621_Distinct_Numbers.cpp)

## TL;DR
Count unique elements in an array using a Set data structure. The Set automatically handles duplicates and gives us the count of distinct elements.

## Problem Overview
Given a list of n integers, we need to find how many distinct (unique) values are present in the list.

## Solution Approach
The problem introduces us to one of the most fundamental applications of the Set data structure. Here's why this approach is elegant:

1. **Using Set Data Structure**
   - A Set automatically stores only unique elements
   - Elements in a set are stored in sorted order (though not needed for this problem)
   - Insertion of n elements takes O(n log n) time

2. **Implementation Details**
   - We use C++'s STL set
   - Direct construction of set from vector using iterator range
   - Just need to output the size of the set

## Key Learning Points
1. **STL Set Basics**
   - This is a perfect introductory problem to understand when to use Sets
   - Shows how Sets can handle duplicates automatically
   - Demonstrates efficient construction of Set from a vector

2. **C++ Specific**
   - Usage of constructor `set<int>(begin_iterator, end_iterator)`
   - How to get input into a vector and convert it to a set

## Common Pitfalls
1. Don't try to manually check for duplicates using nested loops - O(n²) will be too slow
2. Don't sort and then count unique elements - using Set is more straightforward

## Complexity
- Time Complexity: O(n log n)
- Space Complexity: O(n)

## Extended Learning
- This problem can also be solved using:
  - Sorting and counting unique elements
  - HashMap/unordered_set (slightly different complexity trade-offs)
  - std::unique after sorting (C++ specific)

## Tips for Similar Problems
1. Whenever you need to find unique elements, think of Set first
2. Sets are particularly useful when you don't need to maintain element frequency
3. If you need to maintain frequency, consider using a Map instead