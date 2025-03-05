#include <iostream>
#include <vector>
#include <climits>
using namespace std;

using lli = long long int;

int main() {
  int n, e;
  cin >> n;
  lli res = LLONG_MIN, curr = 0;
  for (int i = 0; i < n; i++) {
    cin >> e;
    curr += e;
    res = max(res, curr);
    if (curr < 0) curr = 0;
  }
  cout << res << endl;
  return 0;
}