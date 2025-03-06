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

class CycleFinding {
public:
    lli n_v, inf = 1e15;
    vector<vector<pii>> graph;
    vector<lli> dist, parent;

    void readInput() {
        lli n_e;
        cin >> n_v >> n_e;
        graph.resize(n_v+1);
        for (lli i = 0; i < n_e; i++) {
            lli a, b, c;
            cin >> a >> b >> c;
            graph[a].emplace_back(b, c);
        }
        parent.resize(n_v+1);
        dist.resize(n_v+1);
        for (lli i = 0; i <= n_v; i++) dist[i] = inf;
    }

    // use bellmanFord to compute if cycle present with -ve path sum.
    void bellmanFord() {
        for (auto st = 1; st <= n_v; st++) {
            if (dist[st] != inf) continue;

            dist[st] = 0;
            for (lli node = 1; node <= n_v; node++) {
                bool relaxed = false;
                // iterate over each edge, and relax using that edge the dist to v through u.
                for (lli u = 1; u <= n_v; u++) {
                    if (dist[u] == inf) continue;
                    for (auto [v, w]: graph[u]) {
                        if (dist[u]+w >= dist[v]) continue;
                        relaxed = true;
                        dist[v] = dist[u]+w;
                        parent[v] = u;
                    }
                }
                if (!relaxed) {
                    // no edge was relaxed in this iteration, any more loop is a waste of time :)
                    break;
                }
            }

            // Try relaxing once more
            lli cycleStart = -1;
            for (lli u = 1; u <= n_v; u++) {
                if (dist[u] == inf) continue;
                for (auto [v, w]: graph[u]) {
                    if (dist[u]+w >= dist[v]) continue;
                    // u and v falls inside cycle.
                    cycleStart = v;
                }
            }
            if (cycleStart == -1) continue;

            // cycleStart might lie outside the cycle (as a tail).
            // trace back through parent V times to ensure that
            // the starting node always falls within the cycle.
            for (lli i = 1; i <= n_v; i++) cycleStart = parent[cycleStart];

            vector<lli> cycle;
            cycle.push_back(cycleStart);
            lli curr = parent[cycleStart];
            while (curr != cycleStart) {
                cycle.push_back(curr);
                curr = parent[curr];
            }
            cycle.push_back(curr);
            ranges::reverse(cycle);
            cout << "YES\n";
            for (auto node: cycle) {
                cout << node << " ";
            }
            cout << "\n";
            return;
        }
        cout << "NO\n";
    }

    void run() {
        readInput();
        bellmanFord();
    }
};

int main(int argc, char const *argv[]) {
    init();
    auto s = CycleFinding();
    s.run();
}
