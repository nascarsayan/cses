#include <iostream>
#include <set>
#include <vector>
#include <unordered_set>

using namespace std;

using lli = long long int;

int main() {
  int n;
  cin >> n;
  vector<lli> arr(n);
  unordered_set<lli> rounds;
  for (auto &e: arr) {
    cin >> e;
  }
  for (auto e: arr) {
    auto it = rounds.find(e-1);
    if (it != rounds.end()) {
      rounds.erase(it);
    }
    rounds.insert(e);
  }
  cout << rounds.size() << endl;
  return 0;
}