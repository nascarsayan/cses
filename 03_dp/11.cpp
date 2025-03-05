#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;
using lli = long long int;

void printMat(const vector<vector<lli>> &mat) {
    for (const auto& row: mat) {
        for (const auto cell: row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    if (getenv("CP_DEBUG") != nullptr) {
        freopen("/Users/nascarsayan/Code/cses/input.txt", "r", stdin);
    }
    cin.tie(nullptr);

    lli s1, s2;
    cin >> s1 >> s2;
    vector dp(s1+1, vector<lli>(s2+1));
    for (lli i1 = 1; i1 <= s1; i1++) {
        for (lli i2 = 1; i2 <= s2; i2++) {
            if (i1 == i2) {
                dp[i1][i2] = 0;
                continue;
            }
            dp[i1][i2] = 1e9L;
            for (lli j1 = 1; 2 * j1 <= i1 + 1; j1++) {
                dp[i1][i2] = min(dp[i1][i2], dp[j1][i2] + dp[i1-j1][i2] + 1);
            }
            for (lli j2 = 1; 2 * j2 <= i2 + 1; j2++) {
                dp[i1][i2] = min(dp[i1][i2], dp[i1][j2] + dp[i1][i2-j2] + 1);
            }
            // printMat(dp);
        }
    }
    cout << dp[s1][s2] << '\n';
    return 0;
}
