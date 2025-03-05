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

class RoundTrip2 {
public:
    enum VisitState {
        unvisited, visiting, visited
    };

    lli n_v = 0;
    vector<vector<lli>> graph;
    vector<VisitState> visitState;

    void readInput() {
        lli n_e, u, v;
        cin >> n_v >> n_e;
        graph.resize(n_v+1);
        for (lli i = 0; i < n_e; i++) {
            cin >> u >> v;
            graph[u].push_back(v);
        }
        visitState.resize(n_v+1);
    }

    bool containsCycle(const lli u, vector<lli> &path) {
        path.push_back(u);
        if (visitState[u] == visiting) return true;
        visitState[u] = visiting;
        for (auto v: graph[u]) {
            if (visitState[v] == visited) continue;
            if (containsCycle(v, path)) return true;
        }
        visitState[u] = visited;
        path.pop_back();
        return false;
    }

    void run() {
        readInput();
        for (lli u = 1; u <= n_v; u++) {
            if (visitState[u] != unvisited) continue;
            vector<lli> path;
            if (!(containsCycle(u, path))) continue;
            int start = 0;
            while (path[start] != path.back()) start++;
            cout << path.size() - start << "\n";
            for (int i = start; i < path.size(); i++) {
                cout << path[i] << " ";
            }
            cout << "\n";
            return;
        }
        cout << "IMPOSSIBLE\n";
    }
};

int main(int argc, char const *argv[]) {
    init();
    auto s = RoundTrip2();
    s.run();
}

