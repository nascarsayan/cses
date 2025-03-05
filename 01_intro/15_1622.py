# https://cses.fi/problemset/task/1622
# Creating Strings

from typing import List, Tuple
from collections import Counter
from functools import cache

def permute(arr: List[Tuple[str, int]], size: int, combo: str):
  if len(combo) == size:
    print(combo)
    return
  for i in range(len(arr)):
    ch, cnt = arr[i]
    if cnt == 0:
      continue
    #print(combo, ch, cnt)
    arr[i] = (ch, cnt-1)
    permute(arr, size, combo+ch)
    arr[i] = (ch, cnt)

s = input()

@cache
def factorial(n):
  if n < 2:
    return 1
  return n * factorial(n-1)

cnt = list(sorted(Counter(s).items()))
tot = factorial(len(s))
for _, freq in cnt:
  tot //= factorial(freq)
print(tot)

permute(cnt, len(s), '')
