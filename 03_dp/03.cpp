#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;
using lli = long long int;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    lli n, total;
    cin >> n >> total;
    vector<lli> coins(n);
    for (auto &c: coins) cin >> c;
    vector<lli>dp (total+1, 0);
    dp[0] = 1;
    for (lli t = 1; t <= total; t++) {
        for (const auto c: coins) {
            if (c > t) continue;
            dp[t] = (dp[t] + dp[t-c]) % static_cast<lli>(1e9L + 7);
        }
    }
    cout << dp[total] << '\n';
    return 0;
}
