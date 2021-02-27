#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
template <class T>
using V = vector<T>;

template <class T>
class Matrix {
 public:
  int h, w;
  V<V<T>> data;
  Matrix(int h_, int w_ = 0, T v = 0) {
    h = h_;
    w = (w != 0) ? w_ : h;
    data.resize(h);
    rep(i, h) data[i].resize(w, v);
  }
  Matrix(const V<V<T>>& data_)
      : h(data_.size()), w(data_[0].size), data(data_) {}
  Matrix(initializer_list<initializer_list<T>> list) {
    data.resize(list.size());
    int cnt = 0;
    for (auto row : list) data[cnt++] = V<T>(row);
    h = data.size(), w = data[0].size();
  }
  Matrix(const Matrix& a) : h(a.h), w(a.w), data(a.data) {}
  Matrix& operator=(const Matrix& a) {
    h = a.h, w = a.w, data = a.data;
    return *this;
  }
  V<T>& operator[](int n) { return data[n]; }
  Matrix& operator*=(Matrix& a) {
    V<V<T>> res(h, V<T>(a.w));
    rep(i, h) rep(j, a.w) {
      rep(k, w) res[i][j] += data[i][k] * a[k][j];
    }
    swap(data, res);
    w = a.w;
    return *this;
  }
  Matrix operator*(Matrix& a) { return Matrix(*this) *= a; }
  Matrix& operator+=(Matrix& a) {
    rep(i, h) rep(j, w) data[i][j] += a[i][j];
    return *this;
  }
  string str() {
    ostringstream oss;
    rep(i, h) {
      rep(j, w) oss << data[i][j] << " ";
      if (i != h - 1) oss << "\n";
    }
    return oss.str();
  }
};
