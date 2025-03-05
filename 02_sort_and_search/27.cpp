#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;
using lli = long long int;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    if (getenv("CP_DEBUG") != nullptr) {
        freopen("/Users/nascarsayan/Code/cses/input.txt", "r", stdin);
    }
    cin.tie(nullptr);

    size_t n;
    lli target;
    cin >> n >> target;
    vector<lli> pre(n+1);
    pre[0] = 0;
    for (size_t i=1; i<=n; i++) {
        cin >> pre[i];
    }
    for (size_t i=1; i<=n; i++) {
        pre[i] += pre[i-1];
    }
    size_t res = 0;
    for (size_t lo=0; lo < pre.size()-1; lo++) {
        const auto sum1 = pre[lo];
        auto it = lower_bound(pre.begin()+lo+1, pre.end(), target+sum1);
        if (it!=pre.end() && *it == target+sum1) {
            res++;
        }
    }
    cout << res << '\n';
    return 0;
}
