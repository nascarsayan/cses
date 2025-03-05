#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <deque>
#include <format>

using namespace std;
using lli = long long int;

using pii = pair<int, int>;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    if (getenv("CP_DEBUG") != nullptr) {
        auto _ = freopen("/Users/nascarsayan/Code/cses/input.txt", "r", stdin);
    }
    cin.tie(nullptr);

    int nr, nc;
    char ch;
    cin >> nr >> nc;
    vector graph(nr+2, vector<int>(nc+2, 2));
    for (int ir = 1; ir <= nr; ir++) {
        for (int ic = 1; ic <= nc; ic++) {
            cin >> ch;
            if (ch == '.') graph[ir][ic] = 0;
        }
    }

    const auto validCoord = [&](const int ir, const int ic) {
      if (not (1 <= ir and ir <= nr)) return false;
      if (not (1 <= ic and ic <= nc)) return false;
      return true;
    };

    const vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int islands = 0;
    for (int ir = 1; ir <= nr; ir++) {
        for (int ic = 1; ic <= nc; ic++) {
            if (graph[ir][ic] != 0) continue;
            deque<pii> frontier;
            frontier.emplace_back(ir, ic);
            graph[ir][ic] = 1;
            while (not frontier.empty()) {
                auto [jr, jc] = frontier.front();
                frontier.pop_front();
                graph[jr][jc] = 1;
                for (auto [dr, dc]: dirs) {
                    auto kr = jr+dr, kc = jc+dc;
                    if (not validCoord(kr, kc)) continue;
                    if (graph[kr][kc] != 0) continue;
                    frontier.emplace_back(kr, kc);
                    graph[kr][kc] = 1;
                }
            }
            islands++;
        }
    }
    cout << islands << '\n';
    return 0;
}
