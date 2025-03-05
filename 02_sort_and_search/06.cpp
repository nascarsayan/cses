#include <iostream>
#include <vector>
#include <stack>
using namespace std;

using pii = pair<int, int>;

// Return true if e1 should occur before e2.
bool comparator(pii e1, pii e2) {
  if (e1.second == e2.second) {
    return e1.first > e2.first;
  }
  return e1.second < e2.second;
}

int main() {
  int n;
  cin >> n;
  vector<pii> intervals;
  stack<pii> st;
  intervals.reserve(n);
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    intervals.push_back({l, r});
  }
  sort(intervals.begin(), intervals.end(), comparator);
  int res = 0;
  for (auto i: intervals) {
    if (st.empty() || st.top().second <= i.first) {
      st.push(i);
    }
    res = max(res, (int)st.size());
  }
  cout << res << endl;
  return 0;
}
