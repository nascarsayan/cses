#include <iostream>
#include <vector>
using namespace std;

using pii = pair<int, int>;

int main() {
  int n, tar;
  cin >> n >> tar;
  vector<pii> vec(n);
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    vec[i] = {v, i+1};
  }
  sort(vec.begin(), vec.end());
  int l = 0, r = n-1;
  while (l < r) {
    int s = vec[l].first + vec[r].first;
    if (s == tar) {
      cout << vec[l].second << ' ' << vec[r].second << endl;
      return 0;
    }
    if (s < tar) l++;
    else r--;
  }
  cout << "IMPOSSIBLE";
  return 0;
}
