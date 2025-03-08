// https://cses.fi/problemset/task/1750

#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;
using lli = long long int;

void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    if (getenv("CP_DEBUG") != nullptr) {
        const auto inpPath = "/Users/nascarsayan/Code/github.com/nascarsayan/cses/input.txt";
        if (const auto f = freopen(inpPath, "r", stdin); f == nullptr)
            cout << "Input redirect failed\n";
    }
}

class PlanetQueriesI {
public:
    static const lli MAXN = 2e5 + 5;
    static const lli MAXLOG = 31; // log2(10^9) ~ 30
    
    lli n = 0, q = 0;
    lli lift[MAXN][MAXLOG];
    
    void run() {
        cin >> n >> q;

        // Initialize the lift table
        for (lli i = 1; i <= n; i++) {
            cin >> lift[i][0];
        }
        
        // Precompute the binary lifting table
        for (lli j = 1; j < MAXLOG; j++) {
            for (lli i = 1; i <= n; i++) {
                lift[i][j] = lift[lift[i][j-1]][j-1];
            }
        }
        
        // Process queries
        for (lli i = 0; i < q; i++) {
            lli x, k;
            cin >> x >> k;
            
            for (lli j = 0; j < MAXLOG; j++) {
                if (k & (1LL << j)) {
                    x = lift[x][j];
                }
            }
            
            cout << x << '\n';
        }
    }
};

int main() {
    init();
    PlanetQueriesI solution;
    solution.run();
    return 0;
}
