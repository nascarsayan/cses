#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;
using lli = long long int;

struct project {
    lli start, end, reward;
};

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    if (getenv("CP_DEBUG") != nullptr) {
        freopen("/Users/nascarsayan/Code/cses/input.txt", "r", stdin);
    }
    cin.tie(nullptr);

    lli n;
    cin >> n;
    vector<project> projects(n);
    map<lli, lli> compressed;
    for (auto &p: projects) {
        cin >> p.start >> p.end >> p.reward;
        // This is to make sure that we are treating
        // [1, 3] [4, 5] as [1, 4], [4, 6]
        // so that from range's start X
        // we can map to get DP of ranges ending at most with X.
        p.end++; // important and nice trick.
        compressed[p.start];
        compressed[p.end];
    }

    lli coords = 0;
    for (auto &[k, v]: compressed) {
        v = coords++;
    }

    vector<vector<pair<lli, lli>>> ends_with_ranges(coords);
    for (auto p: projects) {
         ends_with_ranges[compressed[p.end]].emplace_back(compressed[p.start], p.reward);
    }

    vector<lli> dp(coords, 0);
    for (lli end = 0; end < coords; end++) {
        if (end > 0) dp[end] = dp[end-1];
        for (auto [start, reward]: ends_with_ranges[end]) {
            dp[end] = max(dp[end], dp[start]+reward);
        }
    }
    cout << dp[coords-1] << '\n';
    return 0;
}
