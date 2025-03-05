n = int(input())
markers = []
for _ in range(n):
  l, r = list(map(int, input().strip().split()))
  markers.extend([(l, 1), (r, -1)])
res, curr = 0, 0
markers.sort()
for m in markers:
  p, typ = m
  curr += typ
  res = max(res, curr)
print(res)
