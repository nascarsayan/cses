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

    lli n, dead, res = 0;
    cin >> n;
    vector<lli> durations(n);
    for (auto &du: durations) {
        cin >> du;
        cin >> dead;
        res += dead;
    }
    ranges::sort(durations);
    for (lli i = 0; i < durations.size(); i++) {
        res -= (durations.size()-i)*durations[i];
    }
    cout << res << '\n';
    return 0;
}
