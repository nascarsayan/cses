# Concert Tickets

[Problem Link](https://cses.fi/problemset/task/1091) | [Solution Link](../../solutions/02_Sorting_and_Searching/04_1091_Concert_Tickets.cpp)

## TL;DR
Use an ordered map (BST) to efficiently find and remove the highest priced ticket that's within each customer's budget.

## Problem Overview
We have n concert tickets with different prices and m customers arriving sequentially. Each customer specifies their maximum budget, and we need to sell them the highest priced ticket that's within their budget.

## Solution Approach
The solution uses an ordered map (BST) for efficient ticket management:

1. **Data Structure Choice**
   - Use map<price, count> to store tickets
   - Automatically keeps prices sorted
   - Handles duplicate ticket prices through count

2. **Finding Best Ticket**
   - Use lower_bound(budget + 1) to find first ticket above budget
   - Take previous iterator to get highest ticket within budget
   - Decrease count or remove ticket when sold

## Key Learning Points
1. **Map Operations**
   - lower_bound returns iterator to first element >= key
   - prev() to get previous iterator
   - Efficient O(log n) operations for insert/find/delete

2. **Smart Use of BST Properties**
   - Using lower_bound with budget+1 trick
   - Managing frequency with map value
   - Iterator manipulation (prev, erase)

## Common Pitfalls
1. Using unordered_map (need ordered structure)
2. Not handling duplicate ticket prices
3. Wrong iterator manipulation
4. Forgetting to remove tickets after sale

## Complexity
- Time Complexity: O(m log n) where m = customers, n = tickets
- Space Complexity: O(n) for storing tickets

## Extended Learning
- Similar patterns in:
  - Price matching problems
  - Auction systems
  - Resource allocation with constraints

## Tips for Similar Problems
1. Consider ordered data structures when need to find "nearest" or "closest"
2. Think about how to handle duplicates efficiently
3. Be careful with iterator operations
4. Test edge cases (empty map, all tickets used)