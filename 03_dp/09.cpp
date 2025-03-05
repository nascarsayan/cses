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

    lli tc_count;
    cin >> tc_count;
    vector<lli> tests(tc_count);
    for (auto &test: tests) cin >> test;
    auto mx = *ranges::max_element(tests);
    vector dp(mx+1, vector<lli>(2));
    dp[1][0] = 1; dp[1][1] = 1;
    lli mod = 1e9+7;
    for (lli i = 2; i <= mx; i++) {
        /*
          🟥🟥  🟥🟦      🟥🟦
          🟥🟥  🟥🟦      🟪🟦
        */
        dp[i][1] = (dp[i-1][1] * 2 + dp[i-1][0]) % mod;

        /*
          🟥🟦      🟥🟦  🟥🟥  🟥🟦  🟥🟥
          🟥🟪      🟩🟪  🟩🟪  🟩🟩  🟩🟩
        */
        dp[i][0] = (dp[i-1][1] + 4 * dp[i-1][0]) % mod;
    }
    for (auto test: tests) {
        cout << (dp[test][0] + dp[test][1]) % mod << '\n';
    }
    return 0;
}
