#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <deque>
#include <unordered_set>

using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;

constexpr lli inf = 1e17L;

void init() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    if (getenv("CP_DEBUG") != nullptr) {
        const auto inpPath = "/Users/nascarsayan/Code/cses/input.txt";
        if (const auto f = freopen(inpPath, "r", stdin); f == nullptr)
            cout << "Input redirect failed\n";
    }
}

class HighScore {
public:
    lli c_node=0;
    vector<vector<pii>> graph, revGraph;
    vector<lli> minCost;

    void readInput() {
        lli c_edge, u, v, cost;
        cin >> c_node >> c_edge;
        graph.resize(c_node+1);
        revGraph.resize(c_node+1);
        minCost.resize(c_node+1, inf);
        for (lli i = 0; i < c_edge; i++) {
            cin >> u >> v >> cost;
            graph[u].emplace_back(v, -cost);
            revGraph[v].emplace_back(u, -cost);
        }
        minCost[1] = 0;
    }

    static void dfs(const lli u, const lli par, vector<vector<pii>> &graph, unordered_set<lli> &visited) {
        if (visited.contains(u)) return;
        visited.insert(u);
        for (auto [v, _]: graph[u]) {
            if (v == par) continue;
            dfs(v, u, graph, visited);
        }
    }

    lli bellmanFord() {
        for (lli i = 0; i < c_node; i++) {
            for (lli u = 1; u <= c_node; u++) {
                for (auto [v, cost]: graph[u]) {
                    minCost[v] = min(minCost[v], minCost[u] + cost);
                }
            }
        }

        unordered_set<lli> fromSrc, fromDst;
        dfs(1, -1, graph, fromSrc);
        dfs(c_node, -1, revGraph, fromDst);
        unordered_set<lli> reachable;
        for (auto u: fromSrc) if (fromDst.contains(u)) reachable.insert(u);

        for (lli u = 1; u <= c_node; u++) {
            for (auto [v, cost]: graph[u]) {
                if (!reachable.contains(u)) continue;
                if (minCost[v] > minCost[u] + cost) return -1;
            }
        }

        return -minCost[c_node];
    }

    void run() {
        readInput();
        cout << bellmanFord() << '\n';
    }
};

int main(int argc, char const *argv[]) {
    init();
    auto s = HighScore();
    s.run();
}
