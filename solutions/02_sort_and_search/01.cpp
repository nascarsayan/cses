// https://cses.fi/problemset/task/1621

#include <vector>
#include <iostream>
#include <set>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  set<int> unique_elements(arr.begin(), arr.end());
  cout << unique_elements.size() << endl;
  return 0;
}
