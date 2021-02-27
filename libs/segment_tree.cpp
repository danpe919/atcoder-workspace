#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
template <class T>
using V = vector<T>;

template <class T>
class SegmentTree {
 public:
  int n;
  vector<T> data;
  SegmentTree(int n_, T val = T()) : n(1) {
    while (n < n_) n *= 2;
    data.resize(2 * n + 1);
    for (auto &x : data) x = val;
  }

  void update(ll i, T x) {
    i += n - 1;
    data[i] = x;
    while (i > 0) {
      i = (i - 1) / 2;
      data[i] = min(data[i * 2 + 1], data[i * 2 + 2]);
    }
  }

  // [l,r)の最小値を求める
  T query(int a, int b) { return query_sub(a, b, 0, 0, n); }
  T query_sub(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) {
      return T();
    } else if (a <= l && r <= b) {
      return data[k];
    } else {
      T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
      T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
      return min(vl, vr);
    }
  }
};
