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
    vector<lli>dp (total+1, 0);
    dp[0] = 1;
    for (const auto coin : coins) {
        for (lli t = coin; t <= total; t++) {
            dp[t] = (dp[t] + dp[t-coin]) % static_cast<lli>(1e9L + 7);
        }
    }
    cout << dp[total] << '\n';
    return 0;
}
