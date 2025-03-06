// https://cses.fi/problemset/task/1202

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <queue>

using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
using tii = tuple<lli, lli, lli>;

void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    if (getenv("CP_DEBUG") != nullptr) {
        const auto inpPath = "/Users/nascarsayan/Code/cses/input.txt";
        if (const auto f = freopen(inpPath, "r", stdin); f == nullptr)
            cout << "Input redirect failed\n";
    }
}

class Investigation {
public:
    lli n_v = 0, inf = 1e15L, pr = 1e9+7L;
    vector<vector<pii>> graph;

    void readInput() {
        lli n_e, u, v, w;
        cin >> n_v >> n_e;
        graph.resize(n_v+1);
        for (lli i = 0; i < n_e; i++) {
            cin >> u >> v >> w;
            graph[u].emplace_back(v, w);
        }
    }

    void investigate() {
        priority_queue<pii, vector<pii>, greater<>> frontier;
        vector<lli> minCosts(n_v+1, inf), nWays(n_v+1), minHops(n_v+1, inf), maxHops(n_v+1);
        lli st = 1, fl = n_v;
        frontier.emplace(0, st);
        minCosts[st] = 0;
        nWays[st] = 1;
        minHops[st] = 1;
        maxHops[st] = 1;
        while (!frontier.empty()) {
            auto [cost, u] = frontier.top();
            frontier.pop();
            if (minCosts[u] < cost) continue;
            for (auto [v, w]: graph[u]) {
                if (minCosts[v] < cost + w) continue;
                if (minCosts[v] == cost + w) {
                    // another way to get to minCosts[v]
                    nWays[v] = (nWays[v] + nWays[u]) % pr;
                    minHops[v] = min(minHops[v], minHops[u] + 1);
                    maxHops[v] = max(maxHops[v], maxHops[u] + 1);
                    continue;
                }
                // new min found only through u.
                minCosts[v] = cost+w;
                nWays[v] = nWays[u];
                minHops[v] = minHops[u] + 1;
                maxHops[v] = maxHops[u] + 1;
                frontier.emplace(minCosts[v], v);
            }
        }
        cout << minCosts[fl] << " " << nWays[fl] << " " << minHops[fl]-1 << " " << maxHops[fl]-1 << "\n";
    }

    void run() {
        readInput();
        investigate();
    }
};

int main(int argc, char const *argv[]) {
    init();
    auto s = Investigation();
    s.run();
}
