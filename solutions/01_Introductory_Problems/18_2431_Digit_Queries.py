# https://cses.fi/problemset/task/2431/
# Digit Queries

import bisect

chunks = [0]
qList = []
qLen = int(input())
for _ in range(qLen):
  qList.append(int(input()))

lim = max(qList)
while chunks[-1] < lim:
  digs = len(chunks)
  chunks.append((9 * (10**(digs-1))) * digs + chunks[-1])

for q in qList:
  digs = bisect.bisect_left(chunks, q)
  offset = chunks[digs-1]
  chunkDigPos = q - offset - 1
  numPos = chunkDigPos // digs
  start = 10**(digs-1)
  number = start + numPos
  numDigPos = (digs-1) - (chunkDigPos%digs)
  digit = (number // (10**numDigPos)) % 10
  print(digit)
