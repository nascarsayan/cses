# Monsters

[Problem Link](https://cses.fi/problemset/task/1194) | [Solution Link](../../solutions/04_Graph_Algorithms/07_1194_Monsters.cpp)

## TL;DR

The problem involves navigating a labyrinth while avoiding monsters that move simultaneously. The solution uses a multi-source Breadth-First Search (BFS) to simulate monster movement and determine if the player can safely reach the boundary. If a safe path exists, it reconstructs the path using backtracking.

---

## Problem Overview

You are placed in a labyrinth with walls, open spaces, monsters, and a starting position. Monsters move simultaneously in all four cardinal directions, and your goal is to escape to the boundary of the labyrinth without colliding with any monster. The task is to determine if such a path exists and, if so, output the path.

### Key Details:
- Monsters spread through the labyrinth, occupying adjacent cells each step.
- The player must avoid cells occupied by monsters at any time.
- The labyrinth is represented as a grid, with walls (`#`), open spaces (`.`), the player (`A`), and monsters (`M`).

---

## Solution Approach

### 1. **Input Parsing**
The labyrinth is read as a grid of size $n \times m$, and the positions of the player (`A`) and monsters (`M`) are identified. Walls (`#`) and open spaces (`.`) are also noted.

### 2. **Multi-Source BFS**
The solution employs a multi-source BFS to simulate the movement of both the monsters and the player:
   
#### Monster Movement:
- Monsters spread first during each BFS iteration.
- A queue is initialized with all monster positions, and their movement is simulated in all four directions.
- A cell becomes occupied by a monster if it is not a wall or already occupied by another monster.

#### Player Movement:
- After monsters move, the player's movement is simulated.
- Starting from the player's position, BFS explores all valid moves (up, down, left, right).
- If the player reaches a boundary cell (outside the grid), the escape is successful.

### 3. **Path Reconstruction**
If the player reaches a boundary, the solution backtracks using a `route` array to reconstruct the path:
- Each cell stores the direction from which it was reached.
- The path is traced back from the boundary to the starting position and reversed to get the correct order.

### 4. **Output**
- If the player escapes, the solution outputs "YES" followed by the path length and the path itself.
- If escape is impossible, it outputs "NO".

---

## Key Learning Points

1. **Multi-Source BFS**:
   - BFS can handle multiple starting points simultaneously, making it ideal for problems involving simultaneous movements (e.g., monsters spreading).

2. **Path Reconstruction**:
   - Storing the direction of movement during BFS allows for efficient path reconstruction.

3. **Simulation of Dynamic Obstacles**:
   - Problems involving moving obstacles (e.g., monsters) can often be modeled using BFS with state updates.

4. **Boundary Conditions**:
   - Identifying when the player reaches the boundary is critical for determining escape success.

---

## Common Pitfalls

1. **Incorrect BFS Order**:
   - Monsters must move before the player in each BFS iteration to ensure the player avoids newly occupied cells.

2. **Boundary Handling**:
   - Forgetting to check if the player has reached the boundary during BFS can lead to incorrect results.

3. **Grid Updates**:
   - Updating the grid for monster movements must not overwrite valid player paths.

4. **Path Reconstruction Errors**:
   - Failing to correctly backtrack through the `route` array can result in incorrect paths.

---

## Complexity

### Time Complexity:
- **Monster BFS**: Each cell is visited at most once by monsters, so $O(n \cdot m)$.
- **Player BFS**: Each cell is visited at most once by the player, so $O(n \cdot m)$.
- Total: $O(n \cdot m)$.

### Space Complexity:
- Grid storage: $O(n \cdot m)$.
- BFS queues: $O(n \cdot m)$ in the worst case.
- Total: $O(n \cdot m)$.

---

## Alternative Approaches

1. **Dijkstra's Algorithm**:
   - Use Dijkstra's algorithm with a priority queue to simulate both player and monster movements with time as a dimension. This approach is more complex but can handle weighted grids.

2. **Dynamic Programming**:
   - Use a DP table to store the minimum time required to reach each cell and simulate monster movements simultaneously.

3. **Flood Fill**:
   - A flood-fill approach could be used to precompute monster reachability and then check if the player can avoid these cells.

---

## Extended Learning

1. **Multi-Source Shortest Path**:
   - Problems requiring shortest paths from multiple sources can often be solved using BFS or Dijkstra's algorithm.

2. **Dynamic Obstacles in Grids**:
   - Learn how to handle dynamic obstacles by simulating their movement and updating the grid state.

3. **Pathfinding Algorithms**:
   - Explore other pathfinding algorithms like A* for heuristic-based solutions.

---

## Tips for Similar Problems

1. **Recognize Multi-Source BFS Scenarios**:
   - Problems involving simultaneous movements or multiple starting points are good candidates for multi-source BFS.

2. **Simulate Dynamic States**:
   - When obstacles or states change over time, simulate these changes step-by-step during BFS or DP.

3. **Boundary and Escape Problems**:
   - For problems involving escaping a grid, always check boundary conditions during traversal.

4. **Path Reconstruction**:
   - Use auxiliary data structures (e.g., parent pointers or direction arrays) to reconstruct paths efficiently.

5. **Grid-Based Problems**:
   - Practice problems involving grids, as they often involve BFS, DFS, or DP techniques.