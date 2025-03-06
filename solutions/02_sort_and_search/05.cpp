#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> markers;
  markers.reserve(2 * n);
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    markers.push_back({l, 1});
    markers.push_back({r, -1});
  }
  sort(markers.begin(), markers.end());
  int curr = 0, res = 0;
  for (auto m: markers) {
    auto [_, typ] = m;
    curr += typ;
    res = max(res, curr);
  }
  cout << res << endl;
  return 0;
}