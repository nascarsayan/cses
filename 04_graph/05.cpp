#include <algorithm>
#include <iostream>
#include <deque>
#include <set>
#include <vector>

using namespace std;
using lli = long long int;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    if (getenv("CP_DEBUG") != nullptr) {
        auto _ = freopen("/Users/nascarsayan/Code/cses/input.txt", "r", stdin);
    }
    cin.tie(nullptr);

    lli c_node, c_edge;
    cin >> c_node >> c_edge;
    vector graph(c_node+1, vector<lli>());
    for (lli i = 0; i < c_edge; i++) {
        lli u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> group(c_node+1);
    group[0] = 2;
    auto possible = true;
    [&] {
        for (lli u = 1; u <= c_node; u++) {
            if (group[u] != 0) continue;
            deque<lli> frontier;
            vector<lli> prev(c_node, 0);
            frontier.push_back(u);
            while (!frontier.empty()) {
                auto curr = frontier.front();
                group[curr] = group[prev[curr]] % 2 + 1;
                frontier.pop_front();
                for (auto v: graph[curr]) {
                    if (group[v] != 0) {
                        if (group[v] != group[curr] % 2 + 1) {
                            possible = false;
                            return;
                        }
                        continue;
                    }
                    frontier.push_back(v);
                    prev[v] = curr;
                }

            }
        }
    }();
    if (not possible) cout << "IMPOSSIBLE\n";
    else {
        for (lli i = 1; i <= c_node; i++) cout << group[i] << ' ';
        cout << '\n';
    }

    return 0;
}
