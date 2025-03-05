// https://cses.fi/problemset/task/1680

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <deque>

using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;

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

class LongestFlightRoute {
public:
    lli n_v, ninf = -1e15;
    vector<vector<lli>> graph;
    vector<lli> topo;
    vector<bool> visited;

    void readInput() {
        lli n_e, u, v;
        cin >> n_v >> n_e;
        graph.resize(n_v+1);
        for (lli i = 0; i < n_e; i++) {
            cin >> u >> v;
            graph[u].push_back(v);
        }
        visited.resize(n_v+1);
    }

    void dfs(lli u) {
        visited[u] = true;
        for (auto v: graph[u]) {
            if (visited[v]) continue;
            dfs(v);
        }
        topo.push_back(u);
    }

    void computeTopoOrder() {
        for (lli u = 1; u <= n_v; u++) {
            if (visited[u]) continue;
            dfs(u);
        }
        ranges::reverse(topo);
    }

    void computeMaxDist() const {
        vector<lli> maxDist(n_v+1), parent(n_v+1);
        maxDist.assign(n_v+1, ninf);
        maxDist[1] = 0;
        for (auto u: topo) {
            for (auto v: graph[u]) {
                if (maxDist[u] == ninf) continue;
                if (maxDist[v] >= maxDist[u] + 1) continue;
                maxDist[v] = maxDist[u] + 1;
                parent[v] = u;
            }
        }
        if (maxDist[n_v+1] == ninf) {
            cout << "IMPOSSIBLE\n";
            return;
        }
        vector<lli> path;
        for (lli u = n_v; u != 1; u = parent[u]) {
            if (u == 0) {
                cout << "IMPOSSIBLE\n";
                return;
            }
            path.push_back(u);
        }
        path.push_back(1);
        ranges::reverse(path);
        cout << path.size() << "\n";
        for (auto u: path) cout << u << " ";
        cout << "\n";
    }

    void run() {
        readInput();
        computeTopoOrder();
        computeMaxDist();
    }
};

int main(int argc, char const *argv[]) {
    init();
    auto s = LongestFlightRoute();
    s.run();
}
