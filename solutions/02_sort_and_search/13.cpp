#include <iostream>
#include <set>
#include <vector>
#include <unordered_set>
#include <map>

using namespace std;

using lli = long long int;

int main() {
  lli n, v, res = 0, st = 0;
  map<lli,lli> pos;
  cin >> n;
  for (lli i = 1; i <= n; i++) {
    cin >> v;
    st = max(st, pos[v]);
    res = max(res, i-st);
    pos[v] = i;
  }
  cout << res << '\n';
  return 0;
}