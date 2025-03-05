# https://cses.fi/problemset/task/1083
# Missing Number

n = int(input())
sigma_n = (n * (n + 1)) // 2
res = sigma_n - sum(list(map(int, input().strip().split())))
print(res)
