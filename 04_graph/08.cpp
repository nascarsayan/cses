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
    ios::sync_with_stdio(false);
    if (getenv("CP_DEBUG") != nullptr) {
        const auto inpPath = "/Users/nascarsayan/Code/cses/input.txt";
        if (const auto f = freopen(inpPath, "r", stdin); f == nullptr)
            cout << "Input redirect failed\n";
    }
}

class ShortestRoute1 {
public:
    lli c_node;
    vector<vector<pii>> graph;
    vector<lli> minCost;

    void readInput() {
        lli c_edge, u, v, cost;
        cin >> c_node >> c_edge;
        graph.resize(c_node+1);
        minCost.resize(c_node+1, -1);
        for (lli i = 0; i < c_edge; i++) {
            cin >> u >> v >> cost;
            graph[u].emplace_back(v, cost);
        }
    }

    void dijkstra() {
        set<pii> frontier = {{0, 1}};
        while (!frontier.empty()) {
            auto it = frontier.begin();
            auto [agg, u] = *it;
            frontier.erase(it);
            if (minCost[u] != -1) continue;
            minCost[u] = agg;
            for (auto [v, cost]: graph[u]) {
                if (minCost[v] != -1) continue;
                frontier.insert({agg+cost, v});
            }
        }
    }

    void run() {
        readInput();
        dijkstra();
        for (lli i = 1; i <= c_node; i++) cout << minCost[i] << ' ';
        cout << '\n';
    }
};

int main(int argc, char const *argv[]) {
    init();
    auto s = ShortestRoute1();
    s.run();
}
