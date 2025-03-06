#include <iostream>
#include <set>
#include <vector>
#include <unordered_set>
#include <map>

using namespace std;

using lli = long long int;

int main() {
  lli n, v;
  cin >> n;
  multiset<lli> pos;
  for (int i = 0; i < n; i++) {
    cin >> v;
    auto idx = pos.lower_bound(v+1);
    if (idx != pos.end()) {
      pos.erase(idx);
    }
    pos.insert(v);
  }
  cout << pos.size() << '\n';
  return 0;
}
