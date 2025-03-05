# https://cses.fi/problemset/task/1092
# Two Sets

n = int(input())
if n % 4 in [1, 2]:
  print("NO")
else:
  print("YES")
  sum_rem = (n * (n+1)) // 4
  s1 = set()
  for i in range(n, 1, -1):
    if sum_rem == 0:
      break
    if sum_rem < i:
      s1.add(sum_rem)
      break
    s1.add(i)
    sum_rem -= i
  print(len(s1))
  print(" ".join(list(map(str, s1))))
  print(n-len(s1))
  for i in range(1, n+1):
    if i not in s1:
      print(i, end=" ")
  print()
