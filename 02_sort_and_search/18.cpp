#include <bits/stdc++.h>

// https://codeforces.com/blog/entry/98629?locale=en
// https://www.geeksforgeeks.org/cses-solutions-nested-ranges-check/

using namespace std;
using lli = long long int;

struct segment {
  lli l, r, i;

  bool operator<(const segment& other) const {
    if (l != other.l)
      return l < other.l;
    return r > other.r;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // freopen("input.txt", "r", stdin);
  lli n;
  cin >> n;
  vector<segment> ranges(n);
  for (lli i = 0; i < n; i++) {
    auto& range = ranges[i];
    cin >> range.l;
    cin >> range.r;
    range.i = i;
  }
  sort(ranges.begin(), ranges.end());
  vector<lli> contains(n, 0), contained(n, 0);
  lli maxEnd = 0;
  for (auto rng : ranges) {
    if (rng.r <= maxEnd) {
      contained[rng.i] = 1;
    } else {
      maxEnd = rng.r;
    }
  }
  lli minEnd = 1e10L;
  for (auto it = ranges.rbegin(); it != ranges.rend(); it++) {
    if (it->r >= minEnd) {
      contains[it->i] = 1;
    } else {
      minEnd = it->r;
    }
  }
  for (auto v : contains)
    cout << v << " ";
  cout << '\n';
  for (auto v : contained)
    cout << v << " ";
  cout << '\n';
  return 0;
}