#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;
using lli = long long int;
lli ninf = -2e9L;

pair<lli, lli> solve(
    const vector<lli> &nums,
    vector<vector<pair<lli, lli>>> &dp,
    const lli st, const lli fl) {
    if (st == fl) {
        return {nums[st], 0};
    }
    auto v = dp[st][fl];
    if (v.first != ninf) {
        return v;
    }
    // the first guy picks from the left
    auto [l1, l2] = solve(nums, dp, st+1, fl);
    // the first guy picks from the right
    auto [r1, r2] = solve(nums, dp, st, fl-1);
    pair<lli, lli> res;
    if (l2 + nums[st] > r2 + nums[fl]) res = {l2 + nums[st], l1};
    else res = {r2 + nums[fl], r1};
    dp[st][fl] = res;
    return dp[st][fl];
}

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
    vector dp(n, vector<pair<lli, lli>>(n, {ninf, ninf}));
    auto [v1, v2] = solve(nums, dp, 0, n-1);
    cout << v1 << '\n';
    return 0;
}
