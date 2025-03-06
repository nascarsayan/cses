# Movie Festival

[Problem Link](https://cses.fi/problemset/task/1629) | [Solution Link](../../solutions/02_Sorting_and_Searching/06_1629_Movie_Festival.cpp)

## TL;DR
Sort movies by end time and greedily select non-overlapping movies to maximize the count of movies that can be watched completely.

## Problem Overview
Given n movies with their start and end times, find the maximum number of movies that can be watched completely (no overlaps allowed).

## Solution Approach
This is a classic activity selection/interval scheduling problem solved using a greedy approach:

1. **Sort by End Time**
   - Sort all movies by their ending time
   - If end times are equal, prefer movies with later start time
   - This ensures we finish movies as early as possible

2. **Greedy Selection**
   - Keep track of last movie end time
   - Select next movie if its start time ≥ last end time
   - Count selected movies

## Key Learning Points
1. **Greedy Choice Property**
   - Sorting by end time is optimal
   - No need to try all combinations
   - Always safe to take earliest ending movie

2. **Implementation Details**
   - Custom comparator for sorting
   - Using stack to track selected movies
   - Handling equal end times correctly

## Common Pitfalls
1. Sorting by start time (wrong approach)
2. Not considering equal end times
3. Using wrong comparison in overlap check
4. Forgetting to update last end time

## Complexity
- Time Complexity: O(n log n) for sorting
- Space Complexity: O(n) for storing intervals

## Extended Learning
- Similar patterns in:
  - Meeting room scheduling
  - Task scheduling with deadlines
  - Resource allocation problems
  - Activity selection problems

## Tips for Similar Problems
1. Draw timeline to visualize overlaps
2. Consider what makes a choice "greedy optimal"
3. Think about why other sorting criteria fail
4. Test with overlapping and non-overlapping cases

## Alternative Approaches
1. Could use only last end time instead of stack
2. Dynamic programming (but overkill here)
3. Priority queue based approach (more complex)

## Why Greedy Works
- By choosing earliest ending movie, we:
  1. Minimize blocking of future options
  2. Maximize remaining time for other movies
  3. Can prove optimality by exchange argument