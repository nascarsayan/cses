# https://cses.fi/problemset/task/1623
# Apple Division

def partition(arr, s1, s2, idx):
  if idx == len(arr):
    return abs(s1 - s2)
  return min(partition(arr, s1+arr[idx], s2, idx+1), partition(arr, s1, s2+arr[idx], idx+1))

n = int(input())
arr = list(map(int, input().strip().split()))
print(partition(arr, 0, 0, 0))
