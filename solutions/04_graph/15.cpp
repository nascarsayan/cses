// https://cses.fi/problemset/task/1679

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

class CourseSchedule {
public:
    enum VisitState {
        unvisited, visiting, visited
    };
    lli n_v;
    // u has the prereqs [v1, v2, v3 .. vn]
    vector<vector<lli>> prereqs;
    // Since there is no cycle, bool is fine for visited.
    vector<VisitState> visitState;
    vector<lli> res;

    void readInput() {
        lli n_e, u, v;
        cin >> n_v >> n_e;
        prereqs.resize(n_v+1);
        for (lli i = 0; i < n_e; i++) {
            cin >> u >> v;
            prereqs[v].push_back(u);
        }
        visitState.resize(n_v+1);
    }

    // return false if cycle detected.
    bool dfs(lli u) {
        if (visitState[u] == visiting) return false;
        visitState[u] = visiting;
        for (auto v: prereqs[u]) {
            if (visitState[v] == visited) continue;
            if (!dfs(v)) return false;
        }
        visitState[u] = visited;
        res.push_back(u);
        return true;
    }

    // There is another algo using outdegree count and BFS (Kahn's Algorithm)
    // It gradually trims out all the nodes with 0 dependency.
    // This cannot be used directly, as there can be cycles.
    void topoSortDfs() {
        for (lli u = 1; u <= n_v; u++) {
            if (visitState[u] == visited) continue;
            if (!dfs(u)) {
                cout << "IMPOSSIBLE\n" << "\n";
                return;
            }
        }
        for (auto u: res) {
            cout << u << " ";
        }
        cout << "\n";
    }

    void run() {
        readInput();
        topoSortDfs();
    }
};

int main(int argc, char const *argv[]) {
    init();
    auto s = CourseSchedule();
    s.run();
}
