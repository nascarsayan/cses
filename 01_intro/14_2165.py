# https://cses.fi/problemset/task/2165

def solve(cnt, st, mid, fl):
  if cnt == 1:
    print(st, fl)
    return
  solve(cnt-1, st, fl, mid)
  print(st, fl)
  solve(cnt-1, mid, st, fl)

n = int(input())
print(2**n-1)
solve(n, 1, 2, 3)
