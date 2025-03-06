#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
  int T, C;
  map<int, int> t;
  cin >> T >> C;
  for (int i = 0; i < T; i++) {
    int v;
    cin >> v;
    t[v]++;
  }
  for (int i = 0; i < C; i++) {
    int v;
    cin >> v;
    auto j = t.lower_bound(v+1);
    if (j == t.begin()) {
      cout << -1 << endl;
      continue;
    }
    auto el = prev(j);
    cout << el->first << endl;
    if (--(el->second) == 0) {
      t.erase(el);
    }
  }
  return 0;
}