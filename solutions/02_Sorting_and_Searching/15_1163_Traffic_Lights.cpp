#include <iostream>
#include <set>
#include <vector>
#include <unordered_set>
#include <map>

using namespace std;

using lli = long long int;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  lli x, n;
  cin >> x >> n;
  set<lli> pos = {0, x};
  multiset<lli> segs = {x};
  for (lli i = 0; i < n; i++) {
    lli p;
    cin >> p;
    auto idx = pos.lower_bound(p);
    auto r = *idx, l = *prev(idx);
    segs.erase(segs.find(r-l));
    for (auto val: {p-l, r-p}) {
      if (val != 0) segs.insert(val);
    }
    pos.insert(p);
    cout << *segs.rbegin() << " ";
  }
  cout << '\n';
  return 0;
}