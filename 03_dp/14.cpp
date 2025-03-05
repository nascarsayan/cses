#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;
using lli = long long int;

lli mod = 1e9+7;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    if (getenv("CP_DEBUG") != nullptr) {
        freopen("/Users/nascarsayan/Code/cses/input.txt", "r", stdin);
    }
    cin.tie(nullptr);

    lli n;
    cin >> n;
    auto sigma_n = (n * (n + 1)) / 2;
    if (sigma_n % 2 != 0) {
        cout << 0 << '\n';
        return 0;
    }
    auto target = sigma_n / 2;
    vector<lli> dp(sigma_n + 1, 0);
    dp[0] = 1;

    for (lli curr = 2; curr <= n; curr++) {
        for (lli sum = sigma_n; sum >= curr; sum--) {
            dp[sum] = (dp[sum] + dp[sum-curr]) % mod;
        }

    }

    cout << dp[target] << '\n';
    return 0;
}
