# https://cses.fi/problemset/task/1755
# Palindrome Reorder

from collections import Counter

def toPalin(s: str) -> str:
  cnt = Counter(s)
  if sum(list(map(lambda x: x %2, cnt.values()))) > 1:
    return 'NO SOLUTION'
  dangle = ''
  res = ''
  for ch, freq in cnt.items():
    res += ch * (freq // 2)
    if freq % 2 == 1:
      dangle = ch
  res = res + dangle + res[::-1]
  return res

s = input().strip()
print(toPalin(s))
