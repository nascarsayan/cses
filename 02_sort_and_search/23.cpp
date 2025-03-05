#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <vector>

using namespace std;
using lli = long long int;

lli solve(vector<lli> &durations) {
    if (durations.size() == 1) return 2 * durations[0];
    ranges::sort(durations);
    lli acc = accumulate(durations.begin(), durations.end()-1, 0LL);
    lli last = *durations.rbegin();
    if (acc >= last) return acc + last;
    return last * 2;
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    if (getenv("CP_DEBUG") != nullptr) {
        freopen("/Users/nascarsayan/Code/cses/input.txt", "r", stdin);
    }
    cin.tie(nullptr);

    lli n;
    cin >> n;
    vector<lli> durations(n);
    for (auto &d: durations) {
        cin >> d;
    }
    cout << solve(durations) << '\n';
    return 0;
}
