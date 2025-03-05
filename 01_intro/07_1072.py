# https://cses.fi/problemset/task/1072
# Two Knights

_n = int(input())
for n in range(1, _n+1):
  total = ((n * n) * ((n * n)-1)) // 2
  excluded = ((n-1) * (n-2)) * 4
  res = total - excluded
  print(res)
