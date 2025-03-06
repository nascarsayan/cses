#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <deque>
#include <unordered_set>
#include <queue>

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

// NOTE: This is dijkstra modified.
// The blog entry below gives a better algorithm
// https://codeforces.com/blog/entry/102085
class ShortestKRoutes {
public:
    lli n_v = 0, k = 0;
    vector<vector<pii>> graph;

    void readInput() {
        lli n_e, u, v, w;
        cin >> n_v >> n_e >> k;
        graph.resize(n_v+1);
        for (lli i = 0; i < n_e; i++) {
            cin >> u >> v >> w;
            graph[u].emplace_back(v, w);
        }
    }

    void dijkstra() {
        vector<lli> distCnt(n_v+1);
        lli st = 1, found = 0, fl = n_v;
        // pair of distance and node
        priority_queue<pii, vector<pii>, greater<>> frontier;
        frontier.emplace(0, 1);
        while (!frontier.empty()) {
            //pr(frontier.__get_container());
            auto [d, u] = frontier.top();
            frontier.pop();
            // We have already found the k shortest routes to v.
            if (distCnt[u] == k) continue;
            distCnt[u]++;
            if (u == fl) {
                cout << d << " ";
                found++;
                if (found == k) break;
            }
            for (auto [v, w]: graph[u]) {
                // * IMPORTANT: *
                // It's critical to notice that we should not check for
                // distCnt[v] == k here, and increment distCnt[v] here.
                // That's because u will be popped in ascending order of cost.
                // When u1 is popped before u2, and
                // graph contains edges (u1,v,w1), (u2,v,w2),
                // min_cost(u1) < min_cost(u2) is true
                // BUT min_cost(u1)+w1 < min_cost(u2)+w2 is not ensured.
                frontier.emplace(d+w, v);
            }
        }
    }

    void run() {
        readInput();
        dijkstra();
    }
};

int main(int argc, char const *argv[]) {
    init();
    auto s = ShortestKRoutes();
    s.run();
}
