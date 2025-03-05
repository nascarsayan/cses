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

    lli n, total;
    cin >> n >> total;
    vector<lli> coins(n);
    for (auto &c: coins) cin >> c;
    constexpr lli inf = 1e9L;
    vector<lli>dp (total+1, inf);
    dp[0] = 0;
    for (lli t = 1; t <= total; t++) {
        for (const auto c: coins) {
            if (c > t) continue;
            dp[t] = min(dp[t], dp[t-c] + 1);
        }
    }
    if (dp[total] == inf) cout << -1 << '\n';
    else cout << dp[total] << '\n';
    return 0;
}
