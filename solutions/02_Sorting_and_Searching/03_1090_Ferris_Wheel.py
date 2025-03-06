n, mx = list(map(int, input().split()))
w = list(sorted(map(int, input().split())))
left, r = 0, n-1
res = 0
while left < r:
  res += 1
  if w[left] + w[r] > mx:
    left -= 1
  left, r = left+1, r-1
if left == r:
  res += 1
print(res)
