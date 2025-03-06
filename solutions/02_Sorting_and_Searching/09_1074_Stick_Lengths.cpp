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
  auto median = vec[n/2];
  lli res = 0;
  for (auto e: vec) {
    res += abs(e - median);
  }
  cout << res << endl;
  return 0;
}
