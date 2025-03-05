# https://cses.fi/problemset/task/1754
# Coin Piles

n = int(input())
for _ in range(n):
  m, M = list(map(int, input().strip().split()))
  m, M = min(m, M), max(m, M)
  val = 2 * m - M
  if val >= 0 and val % 3 == 0:
    print("YES")
  else:
    print("NO")
