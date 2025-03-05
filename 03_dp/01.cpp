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
    vector<lli> dp(7, 0);
    dp[0] = 1;
    lli mod = 1e9L+7;
    for (lli i = 1; i <= n; i++) {
        dp[i%7] = 0;
        for (lli j = i+1; j <= i+6; j++) dp[i%7] = (dp[i%7] + dp[j % 7]) % mod;
    }
    cout << dp[n%7] << '\n';
    return 0;
}
