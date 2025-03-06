#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;
using lli = long long int;

struct segment {
  lli l, r, i;

  bool operator<(const segment& other) const {
    if (l != other.l)
      return l < other.l;
    return r > other.r;
  }
};

template <typename T>
class Fenwick {
  vector<T> tree;
  lli len;
  static inline lli LSB(const lli index) { return index & -index; }

 public:
  explicit Fenwick(lli s) : len(s) { tree.resize(s + 1, T()); }

  explicit Fenwick(const vector<T>& arr) : len(arr.size()) {
    tree.resize(arr.size() + 1, T());
    for (lli i = 0; i < arr.size(); i++) {
      tree[i + 1] = arr[i];
    }
    for (lli i = 1; i <= arr.size(); i++) {
      if (i + LSB(i) < tree.size()) {
        tree[i + LSB(i)] += tree[i];
      }
    }
  }
  T prefixSum(lli index) {
    T sum = T();
    index = min(index, (lli)(tree.size()-2));
    for (++index; index > 0; index -= LSB(index)) {
      sum += tree[index];
    }
    return sum;
  }
  T rangeSum(const lli lo, const lli hi) {
    return prefixSum(hi) - (lo > 0 ? prefixSum(lo - 1) : T());
  }
  void add(lli index, const T& delta) {
    for (++index; index < tree.size(); index += LSB(index)) {
      tree[index] += delta;
    }
  }

  void print() {
    for (lli i = 0; i < tree.size(); i++) {
      cout << tree[i] << " ";
    }
    cout << '\n';
  }
};

template<typename T>
class SparseArray {
  map<T, lli> orig2Compressed;
  set<T> orig;
public:
  void insert(T val) {
    orig.insert(val);
  }
  void build() {
    lli idx = 0;
    for (auto val: orig) {
      orig2Compressed[val] = idx++;
    }
  }
  lli getCompressed(T orig) {
    return orig2Compressed[orig];
  }
};

int main(int argc, char const *argv[])
{
  auto sp = SparseArray<lli>();

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //freopen("/Users/nascarsayan/Code/cses/02_sort_and_search/input.txt", "r", stdin);
  lli n;
  cin >> n;
  vector<segment> ranges(n);
  for (lli i = 0; i < n; i++) {
    auto& range = ranges[i];
    cin >> range.l;
    cin >> range.r;
    sp.insert(range.l);
    sp.insert(range.r);
    range.i = i;
  }
  sp.build();
  for (lli i = 0; i < n; i++) {
    ranges[i].l = sp.getCompressed(ranges[i].l);
    ranges[i].r = sp.getCompressed(ranges[i].r);
  }
  sort(ranges.begin(), ranges.end());
  vector<lli> contains(n, 0), contained(n, 0);
  const auto mx = 2 * n;
  auto bit = Fenwick<lli>(mx);
  for (const auto rng : ranges) {
    const auto val = bit.rangeSum(rng.r, mx);
    contained[rng.i] += val;
    bit.add(rng.r, 1);
  }
  bit = Fenwick<lli>(mx);
  for (lli i = ranges.size() - 1; i >= 0; i--) {
    const auto rng = ranges[i];
    const auto val = bit.prefixSum(rng.r);
    contains[rng.i] += val;
    bit.add(rng.r, 1);
  }
  for (const auto v : contains)
    cout << v << " ";
  cout << '\n';
  for (const auto v : contained)
    cout << v << " ";
  cout << '\n';
  return 0;
}
