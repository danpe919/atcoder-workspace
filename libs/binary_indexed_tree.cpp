#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Binary Indexed Tree
 * @note 0-indexed
 */
template <typename T>
class BinaryIndexdTree {
 public:
  int n;
  vector<T> data;
  BinaryIndexdTree(int n_) : n(n_), data(n_ + 1, 0) {}
  // i 番目に x を加算
  void add(int i, T x) {
    for (; i < n; i |= i + 1) data[i] += x;
  }
  // [left, right) の和
  T sum(int left, int right) { return sum(right) - sum(left); }
  // [0, i) の和
  T sum(int i) {
    T ret(0);
    for (i--; i >= 0; i = (i & (i + 1)) - 1) {
      ret += data[i];
    }
    return ret;
  }
};
