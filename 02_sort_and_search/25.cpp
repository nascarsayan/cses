#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;
using lli = long long int;

const auto impossible = "IMPOSSIBLE\n";

void solve(vector<pair<lli, size_t>> nums, lli target) {
    if (nums.size() < 4) {
        cout << impossible;
        return;
    }
    ranges::sort(nums);
    auto len = nums.size();

    for (size_t i = 0; i < len; i++) {
        for (size_t j = i+1; j < len; j++) {
            size_t lo = j+1, hi = len-1;
            while (lo < hi) {
                const auto val = nums[i].first + nums[j].first + nums[lo].first + nums[hi].first;
                if (val == target) {
                    cout << nums[i].second << ' '<< nums[j].second << ' '<< nums[lo].second << ' '<< nums[hi].second << '\n';
                    return;
                }
                if (val < target) lo++;
                else hi--;
            }
        }
    }
    cout << impossible;
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    if (getenv("CP_DEBUG") != nullptr) {
        freopen("/Users/nascarsayan/Code/cses/input.txt", "r", stdin);
    }
    cin.tie(nullptr);

    lli n, target;
    cin >> n >> target;
    vector<pair<lli, size_t>> nums(n);
    size_t i = 1;
    for (auto &[num, idx]: nums) {
        cin >> num;
        idx = i++;
    }
    solve(nums, target);
    return 0;
}
