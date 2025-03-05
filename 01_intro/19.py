from typing import List, Tuple

dirs = [(-1, -1), (-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1)]
ch2dirIdx = { 'U': 1, 'R': 3, 'D': 5, 'L': 7 }

def dfs(board: List[List[int]], boardIdx: Tuple[int, int], path: str, pathIdx: int) -> int:
  def exist(*idcs: Tuple[int, int]):
    for (r, c) in idcs:
      if not (0 <= r < 7 and 0 <= c < 7):
        return False
    return True
  def visited(idx: Tuple[int, int]):
    nonlocal board
    if not exist(idx):
      return True
    return board[idx[0]][idx[1]] == 1
  def setSquare(idx: Tuple[int, int], val: int):
    nonlocal board
    board[idx[0]][idx[1]] = val
  
  if not exist(boardIdx):
    return 0
  if visited(boardIdx):
    return 0
  if pathIdx == len(path):
    if boardIdx == (6, 0):
      return 1
    return 0
  if boardIdx == (6, 0):
    return 0
  r, c = boardIdx
  N = [(r+dr, c+dc) for (dr, dc) in dirs]
  for diag in range(0, 7, 2):
    if exist(N[diag]) and visited(N[diag]) and all(not visited(i) for i in (N[diag-1], N[diag+1])):
      return 0
  if visited(N[1]) == visited(N[5]) and visited(N[3]) == visited(N[7]):
    if visited(N[1]) == (not visited(N[3])):
      return 0
  
  setSquare(boardIdx, 1)
  ch = path[pathIdx]
  nextBoardIdcs = [N[1], N[3], N[5], N[7]]
  if ch != '?':
    nextBoardIdcs = [N[ch2dirIdx[ch]]]
  res = 0
  for nextBoardIdx in nextBoardIdcs:
    if visited(nextBoardIdx):
      continue
    res += dfs(board, nextBoardIdx, path, pathIdx+1)
  setSquare(boardIdx, 0)
  return res

path = input().strip()
res = dfs([[0] * 7 for _ in range(7)], (0, 0), path, 0)
print(res)
