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

    lli n, target, val;
    cin >> n >> target;
    size_t res = 0;
    lli agg = 0;
    map<lli, lli> aggCount;
    aggCount[0] = 1;
    for (size_t i = 0; i < n; i++) {
        cin >> val;
        agg += val;
        res += aggCount[agg-target];
        aggCount[agg]++;
    }
    cout << res << '\n';
    return 0;
}
