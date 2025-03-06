#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;
using lli = long long int;

lli solve(lli n) {
    if (n < 10) return 1;
    vector<lli> dp(10, 1);
    for (lli i = 10; i <= n; i++) {
        lli res = 1e8L;
        auto num = i;
        while (num > 0) {
            if (const auto dig = num % 10; dig > 0)
                res = min(res, dp[(i-dig)%10] + 1);
            num = num / 10;
        }
        dp[i%10] = res;
    }
    return dp[n%10];
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    if (getenv("CP_DEBUG") != nullptr) {
        freopen("/Users/nascarsayan/Code/cses/input.txt", "r", stdin);
    }
    cin.tie(nullptr);

    lli n;
    cin >> n;
    cout << solve(n) << '\n';
    return 0;
}

