#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <thread>
#include <vector>
#include <deque>

using namespace std;
using lli = long long int;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    if (getenv("CP_DEBUG") != nullptr) {
        auto _ = freopen("/Users/nascarsayan/Code/cses/input.txt", "r", stdin);
    }
    cin.tie(nullptr);

    lli c_node, c_edge, u, v;
    cin >> c_node >> c_edge;
    vector graph(c_node+1, vector<lli>());
    for (lli i = 0; i < c_edge; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<lli> prev(c_node+1);
    deque<pair<lli, lli>> frontier;
    frontier.emplace_back(1, 0);
    prev[1] = -1;
    lli minDist = -1;
    while(!frontier.empty()) {
        auto [u, dist]  = frontier.front();
        frontier.pop_front();
        if (u == c_node) {
            minDist = dist;
            break;
        }
        for (auto v: graph[u]) {
            if (prev[v] != 0) continue;
            frontier.emplace_back(v, dist+1);
            prev[v] = u;
        }
    }
    if (minDist == -1) cout << "IMPOSSIBLE";
    else {
        cout << minDist+1 << '\n';
        vector<lli> path;
        for (lli curr = c_node; curr != -1; curr = prev[curr])
            path.push_back(curr);
        ranges::reverse(path);
        for (auto u: path) cout << u << ' ';
        cout << '\n';
    }

    return 0;
}
