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

constexpr lli inf = 1e16L;

class ShortestRoutes2 {
public:
    lli c_node;
    vector<vector<lli>> graph;

    void readInput() {
        lli c_edge, q, u, v, cost;
        cin >> c_node >> c_edge >> q;
        graph.resize(c_node+1, vector<lli>(c_node+1, inf));
        for (lli i = 1; i <= c_node; i++) graph[i][i] = 0;
        for (lli i = 0; i < c_edge; i++) {
            cin >> u >> v >> cost;
            if (u == v) continue;
            graph[u][v] = min(graph[u][v], cost);
            graph[v][u] = min(graph[u][v], cost);
        }
        floydWarshall();
        for (lli i = 0; i < q; i++) {
            cin >> u >> v;
            cout << (graph[u][v] == inf ? -1: graph[u][v]) << '\n';
        }
    }

    void floydWarshall() {
        for (lli inter = 1; inter <= c_node; inter++) {
            for (lli u = 1; u <= c_node; u++) {
                for (lli v = 1; v <= c_node; v++) {
                    graph[u][v] = min(graph[u][v], graph[u][inter]+graph[inter][v]);
                }
            }
        }
    }

    void run() {
        readInput();
    }
};

int main(int argc, char const *argv[]) {
    init();
    auto s = ShortestRoutes2();
    s.run();
}
