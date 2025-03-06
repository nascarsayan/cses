# Movie Festival II

[Problem Link](https://cses.fi/problemset/task/1632) | [Solution Link](../../solutions/02_Sorting_and_Searching/34_1632_Movie_Festival_II.cpp)

## TL;DR

The problem is solved using a greedy approach combined with sorting and a priority queue (or multiset). Movies are sorted by their ending times, and we use a priority queue to track the availability of the $k$ club members. By always assigning the earliest available member to the next movie that can be watched, we maximize the total number of movies watched.

---

## Problem Overview

The problem involves scheduling movies for $k$ club members at a festival. Each movie has a start and end time, and the goal is to maximize the total number of movies that can be fully watched by the club members. Each member can only watch one movie at a time, and overlapping movies cannot be watched by the same member.

### Key Constraints:
- $1 \leq k \leq n \leq 2 \cdot 10^5$
- $1 \leq a < b \leq 10^9$

The large constraints require an efficient solution, as a brute-force approach would not work within the time limits.

---

## Solution Approach

### 1. **Sorting the Movies by Ending Time**
The first step is to sort the movies by their ending times ($b$). This ensures that we always consider the earliest-ending movie first, which is a common greedy strategy for interval scheduling problems. If two movies have the same ending time, their order does not matter.

### 2. **Using a Priority Queue to Track Member Availability**
To efficiently assign movies to club members, we use a priority queue (or a multiset). The priority queue keeps track of the times when each member becomes available. Initially, all members are available at time $0$.

### 3. **Greedy Assignment of Movies**
For each movie (in sorted order by end time):
- Check if there is a member available who can start watching the movie before its start time ($a$). This is done by comparing the earliest available time in the priority queue with the movie's start time.
- If such a member exists, assign the movie to that member, remove the earliest available time from the queue, and push the movie's end time ($b$) into the queue (indicating the member will be available after the movie ends).
- If no member is available, skip the movie.

### 4. **Maximizing the Count**
Each time a movie is successfully assigned to a member, increment a counter. At the end of the process, this counter will hold the maximum number of movies that can be watched.

---

### Key Steps in Pseudocode:
1. Parse input and store movies as pairs $(a, b)$.
2. Sort movies by $b$ (ending time).
3. Initialize a priority queue with $k$ zeros (all members available at time $0$).
4. Iterate through the sorted movies:
   - If the earliest available time in the queue is $\leq a$, assign the movie to that member and update their availability to $b$.
   - Otherwise, skip the movie.
5. Output the total count of movies assigned.

---

## Key Learning Points

1. **Greedy Algorithms for Interval Scheduling**:
   - Sorting by ending time is a common strategy for maximizing the number of non-overlapping intervals.
   - Always prioritize the earliest-ending interval to leave room for future intervals.

2. **Efficient Member Management**:
   - Using a priority queue allows efficient tracking of the earliest available member. This ensures that the solution remains optimal and fast.

3. **Handling Large Inputs**:
   - Sorting $n$ movies takes $O(n \log n)$, and each priority queue operation (insertion or removal) takes $O(\log k)$. This ensures the solution is efficient even for large inputs.

---

## Common Pitfalls

1. **Not Sorting by Ending Time**:
   - Sorting by starting time or other criteria can lead to suboptimal solutions, as it may not leave room for future movies.

2. **Incorrect Priority Queue Usage**:
   - Forgetting to update the availability of members or not using a priority queue can lead to incorrect results or slower performance.

3. **Edge Cases**:
   - Single member ($k = 1$): Ensure the algorithm handles this case correctly.
   - All movies overlap heavily: The algorithm should still select the maximum number of non-overlapping movies.

---

## Complexity

### Time Complexity:
1. Sorting the movies: $O(n \log n)$
2. Iterating through movies and updating the priority queue: $O(n \log k)$
   - Each movie involves at most one insertion and one removal in the priority queue, which takes $O(\log k)$.

**Total Time Complexity**: $O(n \log n + n \log k)$

### Space Complexity:
- Priority queue: $O(k)$
- Input storage: $O(n)$

**Total Space Complexity**: $O(n + k)$

---

## Alternative Approaches

1. **Using a Multiset Instead of a Priority Queue**:
   - A multiset (or balanced binary search tree) can also be used to track member availability. The operations (insertion, deletion, finding the smallest element) are similar in complexity to a priority queue.

2. **Binary Search for Member Assignment**:
   - Instead of a priority queue, maintain a sorted list of member availability times. Use binary search to find the earliest available member for a movie. This approach has similar complexity but may be harder to implement efficiently.

---

## Extended Learning

1. **Interval Scheduling Problems**:
   - This problem is a variation of the classic interval scheduling maximization problem. Understanding this class of problems is essential for competitive programming.

2. **Greedy Algorithms**:
   - Greedy strategies are often used in optimization problems where local decisions lead to a global optimum.

3. **Data Structures for Scheduling**:
   - Priority queues, balanced binary search trees, and sorted lists are common tools for solving scheduling problems.

---

## Tips for Similar Problems

1. **Look for Sorting Opportunities**:
   - Many scheduling problems can be simplified by sorting intervals based on start or end times.

2. **Use Appropriate Data Structures**:
   - Priority queues or balanced trees are often the key to efficiently managing resources (e.g., members, machines, or time slots).

3. **Think Greedy**:
   - In interval problems, a greedy approach often works. Focus on making the best local decision (e.g., picking the earliest-ending interval).

4. **Handle Edge Cases**:
   - Test with small inputs, single resources, or heavily overlapping intervals to ensure correctness.

---