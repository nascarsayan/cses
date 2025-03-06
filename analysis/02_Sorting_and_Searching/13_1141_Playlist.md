# Playlist

[Problem Link](https://cses.fi/problemset/task/1141) | [Solution Link](../../solutions/02_Sorting_and_Searching/13_1141_Playlist.cpp)

## TL;DR
Use sliding window technique with a map to track the most recent position of each song, updating window start when duplicates are found.

## Problem Overview
Find the longest sequence of consecutive songs where no song is repeated (all songs are unique).

## Solution Approach
This problem uses a clever variation of the sliding window technique:

1. **Position Tracking**
   - Use map to store last position of each song
   - Window start moves to position after last occurrence
   - Update length based on window size

2. **Implementation Details**
   - For each song at position i:
     * Get last position of current song (0 if new)
     * Update window start if needed
     * Update maximum length seen
     * Store current position in map

## Key Learning Points
1. **Sliding Window Optimization**
   - No need to actually maintain window
   - Only track start position
   - Map provides O(log n) access to history

2. **One-Pass Solution**
   - No need for two pointers
   - Map handles both detection and history
   - Immediate length calculation

## Common Pitfalls
1. Using set to track window contents (inefficient)
2. Not handling first occurrence correctly
3. Wrong window start update logic
4. Integer overflow with large inputs

## Complexity
- Time Complexity: O(n log n) due to map operations
- Space Complexity: O(n) for storing positions

## Extended Learning
- Similar patterns in:
  1. Longest substring without repeating chars
  2. Subarray with distinct elements
  3. Window-based uniqueness problems
  4. Stream processing with history

## Tips for Similar Problems
1. Consider if you need full window contents
2. Look for ways to optimize window updates
3. Think about what history you need to maintain
4. Consider map vs set tradeoffs

## Implementation Variations
1. Using unordered_map for O(1) operations
2. Two-pointer with set approach
3. Array-based solution for small value range
4. Stream processing version

## Why It Works
1. Map tracks all needed history
2. Window start jumps efficiently
3. No need to shrink window gradually
4. Maximum length always captures optimal solution