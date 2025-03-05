#include <iostream>
#include <set>
#include <vector>
#include <unordered_set>
#include <map>

using namespace std;

using lli = long long int;

int main()
{
  lli n, v;
  cin >> n;
  map<lli, lli> pos;
  for (int i = 0; i < n; i++)
  {
    cin >> v;
    auto idx = pos.lower_bound(v + 1);
    if (idx != pos.end())
    {
      idx->second--;
      if (idx->second == 0)
        pos.erase(idx->first);
    }
    pos[v] += 1;
  }
  lli res = 0;
  for (auto v : pos)
  {
    res += v.second;
  }
  cout << res << '\n';
  return 0;
}
