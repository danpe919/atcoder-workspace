#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

struct UnionFind {
  int n;
  vector<int> data;
  UnionFind(int n_) : n(n_), data(n_, -1) {}
  int root(int x) {
    if (data[x] < 0) return x;
    return data[x] = root(data[x]);
  }
  void unite(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    if (rx == ry) return;
    if (data[rx] > data[ry]) swap(rx, ry);
    data[rx] += data[ry];
    data[ry] = rx;
  }
  void remove(int x) {
    int rx = root(x);
  }
  bool same(int x, int y) { return root(x) == root(y); }
  int size(int x) { return -data[root(x)]; }
};
