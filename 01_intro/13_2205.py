# https://cses.fi/problemset/task/2205
# Gray Code

n = int(input())
for r in range(2**n):
  for c in range(n, 0, -1):
    batch = (r // (2**c))
    isAsc = batch % 2 == 0
    aboveMid = r % (2**c) < (2**(c-1))
    is1 = isAsc ^ aboveMid
    print(1 if is1 else 0, end='')
  print()
