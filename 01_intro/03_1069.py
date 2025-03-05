# https://cses.fi/problemset/task/1069
# Repititions

cnt = 1
res = 1
s = input().strip()
for i in range(1, len(s)):
  if s[i] != s[i-1]:
    res = max(res, cnt)
    cnt = 0
  cnt += 1
res = max(res, cnt)
print(res)
