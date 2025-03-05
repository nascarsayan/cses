#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using lli = long long int;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    if (getenv("CP_DEBUG") != nullptr) {
        freopen("/Users/nascarsayan/Code/cses/input.txt", "r", stdin);
    }
    cin.tie(nullptr);

    lli n, t;
    cin >> n >> t;
    vector<lli> machines(n);
    for (auto &m: machines) {
        cin >> m;
    }

    ranges::sort(machines);

    lli lo = machines[0], hi = t * machines[0];

    auto check = [&] (const lli maxTime) {
        lli produced = 0;
        for (const auto m: machines) {
            produced += maxTime / m;
            if (produced >= t) return true;
        }
        return false;
    };

    while (lo < hi) {
        const auto mid = (lo + hi) / 2;
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid+1;
        }
    }
    cout << lo << '\n';
    return 0;
}
