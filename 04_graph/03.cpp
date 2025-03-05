#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
using lli = long long int;

class UnionFind {
public:
    struct node {
        lli parent = 0;
        lli rank = 0;
    };
    vector<node> sets;
    explicit UnionFind(const lli size) {
        sets = vector<node>(size+1);
        for (lli i = 1; i <= size; i++) {
            sets[i].parent = i;
        }
    }

    lli find(const lli idx) {
        if (sets[idx].parent != idx) {
            sets[idx].parent = find(sets[idx].parent);
        }
        return sets[idx].parent;
    }

    void union_(const lli idx1, const lli idx2) {
        const lli root1 = find(idx1);
        const lli root2 = find(idx2);
        if (root1 == root2) return;
        if (sets[root2].rank < sets[root1].rank) {
            sets[root2].parent = find(root1);
        } else if (sets[root1].rank < sets[root2].rank) {
            sets[root1].parent = find(root2);
        } else {
            sets[root2].parent = find(root1);
            sets[root1].rank += 1;
        }
    }
};

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    if (getenv("CP_DEBUG") != nullptr) {
        auto _ = freopen("/Users/nascarsayan/Code/cses/input.txt", "r", stdin);
    }
    cin.tie(nullptr);

    lli n_city, n_road, u, v;
    cin >> n_city >> n_road;
    auto uf = UnionFind(n_city);
    for (lli i = 0; i < n_road; i++) {
        cin >> u >> v;
        uf.union_(u, v);
    }
    const lli start = uf.find(1);
    unordered_set<lli> ends;
    for (lli i = 2; i <= n_city; i++) {
        if (auto end = uf.find(i); end != start) ends.insert(end);
    }
    cout << ends.size() << '\n';
    for (const auto end: ends) cout << start << ' ' << end << '\n';

    return 0;
}
