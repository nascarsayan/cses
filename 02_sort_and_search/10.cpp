#include <iostream>
#include <vector>
#include <climits>
using namespace std;

using lli = long long int;

int main() {
  int n;
  cin >> n;
  vector<lli> vec(n);
  for (auto &e: vec) {
    cin >> e;
  }
  sort(vec.begin(), vec.end());
  lli pre = 0;
  for (auto e: vec) {
    if (e > pre + 1) {
      cout << pre + 1 << endl;
      return 0;
    }
    pre += e;
  }
  cout << pre + 1 << endl;
  return 0;
}
