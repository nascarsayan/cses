# https://cses.fi/problemset/task/1071
# Number Spiral

n = int(input())
for _ in range(n):
  r, c = list(map(int, input().strip().split()))
  mx = max(r, c)
  val = (mx - 1) * (mx - 1)
  if mx % 2 == 1:
    r, c = c, r
  val += r
  if c < r:
    val += (r - c)
  print(val)
