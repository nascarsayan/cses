// Sum of Three Values
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;
using lli = long long int;

const auto impossible = "IMPOSSIBLE";

void solve(vector<pair<lli, size_t>> nums, const lli target) {
    ranges::sort(nums);
    if (nums.size() < 3) {
        cout << impossible << '\n';
        return;
    }
    for (size_t mid = 1; mid < nums.size() - 1; mid++) {
        size_t lo = 0, hi = nums.size() - 1;
        while (lo < mid and mid < hi) {
            const auto res = nums[lo].first + nums[mid].first + nums[hi].first;
            if (res == target) {
                cout << nums[lo].second << " " << nums[mid].second << " " << nums[hi].second << '\n';
                return;
            }
            if (res < target) lo++;
            else hi--;
        }
    }
    cout << impossible << '\n';
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
