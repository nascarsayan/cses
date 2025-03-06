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
        freopen("/Users/nascarsayan/Code/cses/test_input.txt", "r", stdin);
    }
    cin.tie(nullptr);

    lli n, k;
    cin >> n >> k;
    lli uniq = 0, start = 0, res = 0;
    vector<lli> nums(n);
    unordered_map<lli, lli> count;
    for (lli i = 0; i < n; i++) {
        cin >> nums[i];
        count[nums[i]]++;
        if (count[nums[i]] == 1) uniq++;
        while (uniq > k) {
            count[nums[start]]--;
            if (count[nums[start]] == 0) uniq--;
            start++;
        }
        res += i - start + 1;
    }
    cout << res << '\n';
    return 0;
}
