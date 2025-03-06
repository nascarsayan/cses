#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <deque>

using namespace std;
using lli = long long int;
using pii = pair<lli, lli>;
using dirs_t = pair<lli, lli>;

void init() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    if (getenv("CP_DEBUG") != nullptr) {
        const auto inpPath = "/Users/nascarsayan/Code/cses/input.txt";
        if (const auto f = freopen(inpPath, "r", stdin); f == nullptr)
            cout << "Input redirect failed\n";
    }
}

enum class cell {
    floor, wall, human, monster
};

class Monsters {
public:
    lli nr, nc;
    char ch;
    map<char, cell> cellmap = {
        {'.', cell::floor},
        {'#', cell::wall},
        {'A', cell::human},
        {'M', cell::monster},
    };

    vector<vector<cell>> grid;
    vector<vector<dirs_t>> route;
    pii st = {-1, -1}, fl = {-1, -1};
    vector<dirs_t> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    void readInput() {
        cin >> nr >> nc;
        grid.resize(nr, vector<cell>(nc));
        route.resize(nr, vector<dirs_t>(nc));
        for (lli ir = 0; ir < nr; ir++) {
            for (lli ic = 0; ic < nc; ic++) {
                cin >> ch;
                grid[ir][ic] = cellmap[ch];
                if (grid[ir][ic] == cell::human) st = {ir, ic};
            }
        }
    }

    bool validPos(lli ir, lli ic) const {
        if (!(0 <= ir and ir < nr)) return false;
        if (!(0 <= ic and ic < nc)) return false;
        return true;
    }
    void bfs() {
        deque<pii> humanPos, monsterPos;
        for (lli ir = 0; ir < nr; ir++) {
            for (lli ic = 0; ic < nc; ic++) {
                if (grid[ir][ic] == cell::human) humanPos.emplace_back(ir, ic);
                else if (grid[ir][ic] == cell::monster) monsterPos.emplace_back(ir, ic);
            }
        }
        while (!humanPos.empty()) {
            const auto mpSize = monsterPos.size();
            const auto hpSize = humanPos.size();
            for (lli i = 0; i < mpSize; i++) {
                auto [ir, ic] = monsterPos.front();
                monsterPos.pop_front();
                for (auto [dr, dc]: dirs) {
                    auto jr = ir+dr, jc = ic+dc;
                    if (!validPos(jr, jc)) continue;
                    if (grid[jr][jc] == cell::wall || grid[jr][jc] == cell::monster) continue;
                    grid[jr][jc] = cell::monster;
                    monsterPos.emplace_back(jr, jc);
                }
            }
            for (lli i = 0; i < hpSize; i++) {
                auto [ir, ic] = humanPos.front();
                humanPos.pop_front();
                for (auto [dr, dc]: dirs) {
                    auto jr = ir+dr, jc = ic+dc;
                    if (!validPos(jr, jc)) {
                        // we have reached goal.
                        fl = {ir, ic};
                        return;
                    }
                    if (grid[jr][jc] != cell::floor) continue;
                    grid[jr][jc] = cell::human;
                    humanPos.emplace_back(jr, jc);
                    route[jr][jc] = {dr, dc};
                }
            }
        }
    }
    void solve() {
        bfs();
        if (fl.first == -1) {
            cout << "NO\n";
            return;
        }
        map<dirs_t, char> dirMap = {
            {{-1, 0}, 'U'},
            {{1, 0}, 'D'},
            {{0, -1}, 'L'},
            {{0, 1}, 'R'},
        };
        string path;
        while (fl != st) {
            auto [dr, dc] = route[fl.first][fl.second];
            path.push_back(dirMap[{dr, dc}]);
            fl.first -= dr;
            fl.second -= dc;
        }
        ranges::reverse(path);
        cout << "YES\n" << path.size() << '\n' << path << '\n';
    }
    void run() {
        readInput();
        solve();
    }
};

int main(int argc, char const *argv[]) {
    init();
    auto s = Monsters();
    s.run();
}
