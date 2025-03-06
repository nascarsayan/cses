#include <iostream>
#include <set>
#include <vector>
#include <unordered_set>

using namespace std;

using lli = long long int;

int main() {
  lli n, m, inv = 0;
  cin >> n >> m;
  vector<lli> nums(n+2), pos(n+2);
  for (lli i = 1; i <= n; i++) {
    cin >> nums[i];
    pos[nums[i]] = i;
  }
  nums[0] = 0; pos[0] = 0;
  nums[n+1] = n+1; pos[n+1] = n+1;
  for (lli i = 1; i <= n; i++) {
    if (pos[nums[i]] < pos[nums[i]-1]) inv++;
  }
  for (lli i = 0; i < m; i++) {
    lli p1, p2;
    cin >> p1 >> p2;
    lli n1 = nums[p1], n2 = nums[p2];
    // affectedLeft is the left index of positions where inversion with neighbouring right is affected.
    set<lli> affectedLeft = {n1-1, n1, n2-1, n2};
    for (auto l: affectedLeft) {
      if (pos[l] > pos[l+1]) inv--;
    }
    swap(nums[p1], nums[p2]);
    swap(pos[n1], pos[n2]);
    for (auto l: affectedLeft) {
      if (pos[l] > pos[l+1]) inv++;
    }
    cout << inv+1 << endl;
  }
  return 0;
}