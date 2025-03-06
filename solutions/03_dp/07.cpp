#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;
using lli = long long int;

struct book {
    int price, page;
};

bool cmp(const book& b1, const book& other) {
    if (other.price != b1.price) return b1.price < other.price;
    return b1.page >= other.page;
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    if (getenv("CP_DEBUG") != nullptr) {
        freopen("/Users/nascarsayan/Code/cses/input.txt", "r", stdin);
    }
    cin.tie(nullptr);

    lli n, money;
    cin >> n >> money;
    vector<book> books(n, book());
    // for (auto &[price, _]: books) cin >> price;
    // for (auto &[_, page]: books) cin >> page;
    for (auto& book : books) {
        cin >> book.price;
    }
    for (auto& book : books) {
        cin >> book.page;
    }
    // TODO: Check why sort is failing with E BADACCESS in the comparator this->
    // Even though, sort not needed here, this is good to check.
    // sort(books.begin(), books.end(), cmp);
    vector dp(2, vector<lli>(money+1, 0));
    for (lli i = 0; i < books.size(); i++) {
        auto [price, page] = books[i];
        for (lli m = 0; m <= money; m++) {
            dp[i % 2][m] = dp[(i+1) % 2][m];
            if (price > m) continue;
            dp[i % 2][m] = max(dp[i % 2][m], dp[(i+1) % 2][m-price] + page);
        }
    }
    cout << dp[(books.size()-1) % 2][money] << '\n';
    return 0;
}
