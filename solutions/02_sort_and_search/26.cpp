#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;
using lli = long long int;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    if (getenv("CP_DEBUG") != nullptr) {
        freopen("/Users/nascarsayan/Code/cses/input.txt", "r", stdin);
    }
    cin.tie(nullptr);

    lli n, val;
    stack<pair<lli, size_t>> st;
    cin >> n;
    for(size_t i = 0; i < n; i++) {
        cin >> val;
        while(!st.empty() and st.top().first >= val) {
            st.pop();
        }
        size_t mn = 0;
        if (!st.empty()) {
            mn = st.top().second;
        }
        cout << mn << ' ';
        st.emplace(val, i+1);
    }
    return 0;
}
