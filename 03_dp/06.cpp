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
    vector grid(n+1, vector<lli>(n+1, -1));
    char ch;
    for (lli i = 1; i <= n; i++) {
        for (lli j = 1; j <= n; j++) {
            cin >> ch;
            if (ch == '*') grid[i][j] = 0;
        }
    }
    if (grid[1][1] == 0 or grid[n][n] == 0) {
        cout << 0 << '\n';
        return 0;
    }
    for (lli i = 0; i <= n; i++) {
        grid[i][0] = 0;
        grid[0][i] = 0;
    }
    grid[1][0] = 1;
    constexpr lli mod = 1e9+7;
    for (lli i = 1; i <= n; i++) {
        for (lli j = 1; j <= n; j++) {
            if (grid[i][j] == 0) continue;
            grid[i][j] = (grid[i-1][j] + grid[i][j-1]) % mod;
        }
    }
    cout << grid[n][n] << '\n';
    return 0;
}
