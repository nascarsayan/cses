# https://cses.fi/problemset/task/1624
# Chessboard and Queens

from typing import List, Tuple

def piece(board: List[List[str]], idx: Tuple[int, int]):
  return board[idx[0]][idx[1]]

def idxToInt(idx: Tuple[int, int]): return 8*idx[0]+idx[1]

def intToIdx(val: int): return (val // 8, val % 8)

def backtrack(board: List[List[str]], qPos: List[Tuple[int, int]], idx: Tuple[int, int]):
  if piece(board, idx) == '*':
    return 0
  for q in qPos:
    r1, c1 = q
    r2, c2 = idx
    d1, d2 = abs(r2-r1), abs(c2-c1)
    if d1 == 0 or d2 == 0 or (d1 == d2):
      return 0
  if len(qPos) == 7:
    return 1
  res = 0
  for nex in range(idxToInt(idx) + 1, 64):
    res += backtrack(board, qPos + [idx], intToIdx(nex))
  return res

def solve(board: List[List[str]]):
  res = 0
  for i in range(64):
    res += backtrack(board, [], intToIdx(i))
  return res

board = []
for i in range(8):
  board.append(list(input().strip()))
print(solve(board))
