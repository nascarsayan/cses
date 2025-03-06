# https://cses.fi/problemset/task/1070
# Permutations

n = int(input())
if n == 1:
  print("1")
elif n < 4:
  print("NO SOLUTION")
else:
  for st in [n-1, n]:
    for i in range(st, 0, -2):
      print(i, end=' ')
print()
