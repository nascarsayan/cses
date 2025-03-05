#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
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
    vector<lli> coins(n);
    for (auto &c: coins) cin >> c;
    ranges::sort(coins);
    const auto mx = accumulate(coins.begin(), coins.end(), 0L);
    vector<bool> dp(mx+1, false);
    dp[0] = true;
    lli cnt = 0;
    for (const auto c : coins) {
        for (lli val = mx; val >= c; val--) {
            if (dp[val]) continue;
            dp[val] = dp[val] | dp[val-c];
        }
    }
    for (lli val = 1; val <= mx; val++) {
        if (dp[val]) cnt++;
    }
    cout << cnt <<'\n';
    for (lli val = 1; val <= mx; val++) {
        if (dp[val]) cout << val << ' ';
    }
    cout << '\n';
    return 0;
}
