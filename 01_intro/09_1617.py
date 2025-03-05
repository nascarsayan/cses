# https://cses.fi/problemset/task/1617
# Bit Strings

from functools import cache

@cache
def pow2(n: int):
  if n < 2:
    return int(2**n)
  return (pow2(n // 2) * pow2((n+1) // 2)) % (10**9 + 7)

n = int(input())
print(pow2(n))
