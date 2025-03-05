n, mx = list(map(int, input().split()))
w = list(sorted(map(int, input().split())))
l, r = 0, n-1
res = 0
while l < r:
  res += 1
  if w[l] + w[r] > mx:
    l -= 1
  l, r = l+1, r-1
if l == r:
  res += 1
print(res)
