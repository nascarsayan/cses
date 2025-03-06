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
  lli n;
  cin >> n;
  set<lli> circle;
  for (lli i = 1; i <= n; i++) {
    circle.insert(i);
  }
  auto it = circle.begin();
  while (circle.size() > 1) {
    it = next(it);
    if (it == circle.end()) it = circle.begin();
    auto toDel = it;
    cout << *it << ' ';
    it = next(it);
    circle.erase(toDel);
    if (it == circle.end()) it = circle.begin();
  }
  if (circle.size() > 0) {
    cout << *circle.begin() << ' ';
  }
  cout << '\n';
  return 0;
}