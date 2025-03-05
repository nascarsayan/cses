#include <algorithm>
#include <numeric>
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

    lli n, k;
    cin >> n >> k;
    vector<lli> arr(n);
    for (auto &v: arr) cin >> v;
    auto lo = *ranges::max_element(arr);
    auto hi = accumulate(arr.begin(), arr.end(), 0LL);
    auto check = [&](lli maxSum) {
        lli cnt = 1, curr = 0;
        for (auto v: arr) {
            if (curr + v > maxSum) {
                curr = 0;
                cnt++;
                if (cnt > k) return false;
            }
            curr += v;
        }
        return true;
    };
    lli ans = hi;
    while (lo <= hi) {
        auto mid = (lo + hi) >> 1;
        if (check(mid)) {
            ans = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    cout << ans << '\n';
    return 0;
}
