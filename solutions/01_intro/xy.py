# Direction vectors for right, left, down, and up
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

# The path description string
str_path = input()

# Initialize the visited array
vis = [[0] * 7 for _ in range(7)]

# Function to check if a coordinate is valid in the grid
def isValid(a):
    return 1 if a >= 0 and a < 7 else 0

# Function to count the number of paths that match the description
def countPaths(x, y, pos):
    # If we have processed all characters in the string and we are at the lower-left square, return 1
    if pos == len(str_path):
        return 1 if x == 6 and y == 0 else 0

    # If we have reached the lower-left square before processing all characters, return 0
    if x == 6 and y == 0:
        return 0

    # If the current cell is already visited, return 0
    if vis[x][y]:
        return 0

    # Array to keep track of the visited status of the neighboring cells
    visited = [-1]*4
    for k in range(4):
        if isValid(x + dx[k]) and isValid(y + dy[k]):
            visited[k] = vis[x + dx[k]][y + dy[k]]

    # If we are at a position such that the up and down squares are unvisited and the left and right squares are visited return 0
    if not visited[2] and not visited[3] and visited[0] and visited[1]:
        return 0

    # If we are at a position such that the left and right squares are unvisited and the up and down squares are visited return 0
    if not visited[0] and not visited[1] and visited[2] and visited[3]:
        return 0

    # If we are at a position such that the upper-right diagonal square is visited and the up and right squares are unvisited return 0
    if isValid(x - 1) and isValid(y + 1) and vis[x - 1][y + 1] == 1:
        if not visited[0] and not visited[3]:
            return 0

    # If we are at a position such that the lower-right diagonal square is visited and the down and right squares are unvisited return 0
    if isValid(x + 1) and isValid(y + 1) and vis[x + 1][y + 1] == 1:
        if not visited[0] and not visited[2]:
            return 0

    # If we are at a position such that the upper-left diagonal square is visited and the up and left squares are unvisited return 0
    if isValid(x - 1) and isValid(y - 1) and vis[x - 1][y - 1] == 1:
        if not visited[1] and not visited[3]:
            return 0

    # If we are at a position such that the lower-left diagonal square is visited and the down and right squares are unvisited return 0
    if isValid(x + 1) and isValid(y - 1) and vis[x + 1][y - 1] == 1:
        if not visited[1] and not visited[2]:
            return 0

    # Mark the current cell as visited
    vis[x][y] = 1

    # Variable to store the number of paths
    numberOfPaths = 0

    # If the current character is '?', try all four directions
    if str_path[pos] == '?':
        for k in range(4):
            if isValid(x + dx[k]) and isValid(y + dy[k]):
                numberOfPaths += countPaths(x + dx[k], y + dy[k], pos + 1)

    # If the current character is a direction, go in that direction
    elif str_path[pos] == 'R' and y + 1 < 7:
        numberOfPaths += countPaths(x, y + 1, pos + 1)
    elif str_path[pos] == 'L' and y - 1 >= 0:
        numberOfPaths += countPaths(x, y - 1, pos + 1)
    elif str_path[pos] == 'U' and x - 1 >= 0:
        numberOfPaths += countPaths(x - 1, y, pos + 1)
    elif str_path[pos] == 'D' and x + 1 < 7:
        numberOfPaths += countPaths(x + 1, y, pos + 1)

    # Unmark the current cell
    vis[x][y] = 0

    # Return the number of paths
    return numberOfPaths

# Call the function and print the result
print(countPaths(0, 0, 0))