#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <deque>

using namespace std;
using lli = long long int;

void init() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    if (getenv("CP_DEBUG") != nullptr) {
        const auto inpPath = "/Users/nascarsayan/Code/cses/input.txt";
        if (const auto f = freopen(inpPath, "r", stdin); f == nullptr)
            cout << "Input redirect failed\n";
    }
}

class Solver {
public:
    lli c_node = 0;
    vector<vector<lli>> graph;
    vector<lli> prev;
    vector<lli> dist;
    lli st = -1, fl = -1;
    void readInput() {
        lli c_edge;
        cin >> c_node >> c_edge;
        graph.resize(c_node+1);
        prev.resize(c_node+1);
        dist.resize(c_node+1);
        for (lli i = 0; i < c_edge; i++) {
            lli u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }
    void solve() {
        for (lli u = 1; u <= c_node; u++) {
            if (dist[u] != 0) continue;
            if (dfs(u, 0)) return;
        }
    }
    bool dfs(const lli u, const lli par) {
        if (dist[u] != 0) {
            st = u;
            fl = par;
            return true;
        }
        dist[u] = dist[par] + 1;
        prev[u] = par;
        for (const auto v: graph[u]) {
            if (v == par) continue;
            if (dfs(v, u)) return true;
        }
        return false;
    }
    void printResult() {
        if (st == -1) {
            cout << "IMPOSSIBLE\n";
            return;
        }
        vector<lli> route;
        for (; fl != st and fl != 0; fl = prev[fl]) {
            route.push_back(fl);
        }
        route.push_back(st);
        ranges::reverse(route);
        cout << route.size() + 1 << '\n';
        for (auto u: route) cout << u << ' ';
        cout << st;
        cout << '\n';
    }
    void run() {
        readInput();
        solve();
        printResult();
    }
};

int main(int argc, char const *argv[]) {
    init();
    auto s = Solver();
    s.run();
}
