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

    lli n, mx;
    lli mod = 1e9+7;
    cin >> n >> mx;
    vector<lli> nums(n);
    for (auto &v: nums) cin >> v;
    vector dp(n, vector<lli>(mx+2, 0));
    if (nums[0] != 0) dp[0][nums[0]] = 1;
    else for (lli v = 1; v <= mx; v++) dp[0][v] = 1;
    for (lli idx = 1; idx < n; idx++) {
        if (const auto v = nums[idx]; v != 0) {
            dp[idx][v] = (dp[idx-1][v-1] + dp[idx-1][v] + dp[idx-1][v+1]) % mod;
            continue;
        }
        for (lli v = 1; v <= mx; v++) {
            dp[idx][v] = (dp[idx-1][v-1] + dp[idx-1][v] + dp[idx-1][v+1]) % mod;
        }
    }
    const auto val = accumulate(dp[n-1].begin(), dp[n-1].end(), 0L) % mod;
    cout << val << '\n';
    return 0;
}
