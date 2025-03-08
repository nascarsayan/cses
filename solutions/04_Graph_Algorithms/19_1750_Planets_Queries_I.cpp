// https://cses.fi/problemset/task/1750

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <deque>
#include <cmath>

using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;

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
    lli n = 0, nq = 0;
    vector<lli> dest;
    vector<pii> q;
    vector<vector<lli>> lift;

    void run() {
        cin >> n >> nq;
        dest.resize(n+1);
        q.resize(nq);
        for (lli i = 1; i <= n; i++) cin >> dest[i];
        lli maxJumps = 0;
        for (lli i = 0; i < nq; i++) {
            cin >> q[i].first >> q[i].second;
            maxJumps = max(maxJumps, static_cast<lli>(log2(q[i].second)+1));
        }
        maxJumps = max(maxJumps, 1LL);

        lift.resize(n+1, vector<lli>(maxJumps, 0));
        for (lli i = 1; i <= n; i++) {
            lift[i][0] = dest[i];
        }
        for (lli jump = 1; jump < maxJumps; jump++) {
            for (lli i = 1; i <= n; i++) {
                lift[i][jump] = lift[lift[i][jump-1]][jump-1];
            }
        }

        for (auto [st, j]: q) {
            auto fl = st;
            for (lli b = 0; b < maxJumps; b++) {
                if ((j >> b) & 1) fl = lift[fl][b];
            }
            cout << fl << '\n';
        }
    }

};

int main(int argc, char const *argv[]) {
    init();
    auto s = PlanetQueriesI();
    s.run();
}
