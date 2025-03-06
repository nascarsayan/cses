#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;
using lli = long long int;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    if (getenv("CP_DEBUG") != nullptr) {
        freopen("/Users/nascarsayan/Code/cses/input.txt", "r", stdin);
    }
    cin.tie(nullptr);

    lli n;
    cin >> n;
    vector<lli> nums(n);
    for (auto &num: nums) cin >> num;
    vector<lli> lis;
    for (auto num: nums) {
        auto it = ranges::lower_bound(lis, num);
        if (it == lis.end()) {
            lis.push_back(num);
            continue;
        }
        *it = num;
    }
    cout << lis.size() << '\n';
    return 0;
}
