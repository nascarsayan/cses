# https://cses.fi/problemset/task/1618

n = int(input())
res = 0
div = 5
while div <= n:
  res += n // div
  div *= 5
print(res)
