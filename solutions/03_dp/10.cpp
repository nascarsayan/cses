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

    string s1, s2;
    cin >> s1 >> s2;
    vector dp(s1.length()+1, vector<lli>(s2.length()+1));
    for (lli i1 = 0; i1 <= s1.length(); i1++) dp[i1][0] = i1;
    for (lli i2 = 0; i2 <= s2.length(); i2++) dp[0][i2] = i2;
    for (lli i1 = 1; i1 <= s1.length(); i1++) {
        for (lli i2 = 1; i2 <= s2.length(); i2++) {
            if (s1[i1 - 1] == s2[i2 - 1]) {
                dp[i1][i2] = dp[i1-1][i2-1];
                continue;
            }
            auto x = {dp[i1][i2-1], dp[i1-1][i2], dp[i1-1][i2-1]};
            dp[i1][i2] = *ranges::min_element(x) + 1;
        }
    }
    cout << dp[s1.length()][s2.length()] << '\n';
    return 0;
}
