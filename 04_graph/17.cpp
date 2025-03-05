// https://cses.fi/problemset/task/1681

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

class GameRoutes {
public:
    lli n_v=0, pr = 1e9+7;
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
    }

    void dfs(lli u) {
        visited[u] = true;
        for (auto v: graph[u]) {
            if (visited[v]) continue;
            dfs(v);
        }
        topo.push_back(u);
    }

    void computeTopo() {
        visited.resize(n_v+1);
        for (lli u = 1; u <= n_v; u++) {
            if (visited[u]) continue;
            dfs(u);
        }
        ranges::reverse(topo);
    }

    void calculateWays() {
        vector<lli> ways(n_v+1);
        ways[1] = 1;
        for (auto u: topo) {
            for (auto v: graph[u]) {
                ways[v] = (ways[v] + ways[u]) % pr;
            }
        }
        cout << ways[n_v] << "\n";
    }

    void run() {
        readInput();
        computeTopo();
        calculateWays();
    }
};

int main(int argc, char const *argv[]) {
    init();
    auto s = GameRoutes();
    s.run();
}
