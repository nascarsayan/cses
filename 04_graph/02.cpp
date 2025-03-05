#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <deque>

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
    pii st, fl;
    char ch;
    cin >> nr >> nc;
    vector graph(nr+2, vector<int>(nc+2, 2));
    vector pred(nr+2, vector<char>(nc+2, 0));
    for (int ir = 1; ir <= nr; ir++) {
        for (int ic = 1; ic <= nc; ic++) {
            cin >> ch;
            if (ch == '#') continue;
            graph[ir][ic] = 0;
            if (ch == 'A') st = {ir, ic};
            else if (ch == 'B') fl = {ir, ic};
        }
    }

    const vector<tuple<int, int, char>> dirs = {
        {-1, 0, 'U'}, {0, 1, 'R'}, {1, 0, 'D'}, {0, -1, 'L'}};

    deque<tuple<int, int>> frontier;
    frontier.emplace_back(st);
    graph[st.first][st.second] = 1;
    auto found = false;
    while (not frontier.empty()) {
        auto [jr, jc] = frontier.front();
        frontier.pop_front();
        graph[jr][jc] = 1;
        if (jr == fl.first and jc == fl.second) {
            found = true;
            break;
        }
        for (auto [dr, dc, ch]: dirs) {
            auto kr = jr+dr, kc = jc+dc;
            if (graph[kr][kc] != 0) continue;
            frontier.emplace_back(kr, kc);
            graph[kr][kc] = 1;
            pred[kr][kc] = ch;
        }
    }

    if (!found) {
        cout << "NO\n";
    } else {
        string path;
        int cr = fl.first, cc = fl.second;
        while (cr != st.first || cc != st.second) {
            const char dir = pred[cr][cc];
            path += dir;
            // Move in the opposite direction to trace back
            if (dir == 'U') cr++;
            else if (dir == 'D') cr--;
            else if (dir == 'L') cc++;
            else if (dir == 'R') cc--;
        }
        ranges::reverse(path);

        cout << "YES\n" << path.length() << '\n' << path << '\n';
    }
    return 0;
}
