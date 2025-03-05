#include <vector>
#include <iostream>

using namespace std;

int main() {
  int D, A, k;
  cin >> D >> A >> k;
  vector<int> desired(D), actual(A);
  for (auto &e : desired) {
    cin >> e;
  }
  for (auto &e: actual) {
    cin >> e;
  }
  sort(desired.begin(), desired.end());
  sort(actual.begin(), actual.end());
  int d = 0, a = 0, res = 0;
  for (; a < A && d < D; d++, a++) {
    while (a < A && desired[d] > actual[a] + k) {
      a++;
    }
    if (a == A) break;
    if (desired[d] < actual[a] - k) {
      a--;
      continue;
    }
    res++;
  }
  cout << res << endl;
  return 0;
}