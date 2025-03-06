# https://cses.fi/problemset/task/1094
# Increasing Array

n = int(input())
res = 0
arr = list(map(int, input().strip().split()))
for i in range(1, n):
  if arr[i] < arr[i-1]:
    res += arr[i-1]-arr[i]
    arr[i] = arr[i-1]
print(res)
