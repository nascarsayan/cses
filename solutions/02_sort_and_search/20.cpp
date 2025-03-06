#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
using pis = pair<lli, size_t>;

struct range {
  lli lo, hi, idx;
  bool operator<(const range second) const {
    if(lo != second.lo) return lo < second.lo;
    return hi < second.hi;
  }
};

int main(int argc, char const* argv[]) {
  ios::sync_with_stdio(false);
  if (getenv("CP_DEBUG") != nullptr) {
    freopen("/Users/nascarsayan/Code/cses/input.txt", "r", stdin);
  }
  cin.tie(nullptr);

  lli n;
  cin >> n;
  vector<range> ranges(n);
  for(lli i=0; i<n; i++) {
    cin >> ranges[i].lo;
    cin >> ranges[i].hi;
    ranges[i].idx = i;
  }
  sort(ranges.begin(), ranges.end());
  multiset<pis> ends;
  size_t mx = 0;
  vector<size_t> rooms(n);
  for (auto rng: ranges) {
    size_t idx = 0;
    if (!ends.empty()) {
      const auto mn = ends.begin();
      if (mn->first < rng.lo) {
        idx = mn->second;
        ends.erase(mn);
      }
    }
    if (idx == 0) {
      mx++;
      idx = mx;
    }
    ends.insert({rng.hi, idx});
    rooms[rng.idx] = idx;
  }
  cout << mx << '\n';
  for (auto v: rooms) {
    cout << v << ' ';
  }
  cout << '\n';

  // set<size_t> rooms;
  // for (size_t i=1; i<=n; i++) {
  //   rooms.insert(i);
  // }
  // for

  return 0;
}
