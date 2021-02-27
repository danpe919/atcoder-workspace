// clang-format off
// #include <atcoder/all>
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep2(i, st, n) for (int i = st; i < (n); ++i)
#define rrep(i, n) for (int i = (n - 1); i >= 0; --i)
#define RREP(i, ed, n) for (int i = (n - 1); i >= (ed); --i)
#define BIT(n, k) ((n >> k) & 1)
#define LEN(s) (int)s.size()
#define popcount(n) __builtin_popcount(n)
#define ALL(a) a.begin(), a.end()
#define RRANGE(a) a.rbegin(), a.rend()
template<class T> bool chmax(T &a, const T &b) {
  if (a < b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) {
  if (b < a) { a=b; return 1; } return 0; }
template<class T> bool bit(T S, int i) { return (S >> i & 1); }
#define dump(x) cout << #x << " = " << x << endl
#define myceil(a, b) (a + (b - 1)) / (b)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T> using V = vector<T>;
constexpr int IINF = 1 << 30;
constexpr ll LINF = 1LL << 62;
constexpr ll mod = 1e9 + 7;
template <class T> T max(const V<T>& v) { return *max_element(ALL(v)); }
template <class T> T min(const V<T>& v) { return *min_element(ALL(v)); }
template <class T> ll sum(const V<T>& v) { return accumulate(ALL(v), 0LL); }
ll intpow(ll i, int n) { ll ret = 1; rep(j, n) ret *= i; return ret; }
template <typename T>
istream& operator>>(istream& i, V<T>& v) {
  rep(j, LEN(v)) i >> v[j];
  return i;
}
istream& operator>>(istream& i, P& p) {
  i >> p.first >> p.second; return i;
}
template <typename T> ostream& operator<<(ostream& o, V<T>& v) {
  rep(i, LEN(v)) o << v[i] << ", ";
  return o;
}
ostream& operator<<(ostream& o, P p) {
  o << p.first << " " << p.second; return o;
}
template <typename T>
V<V<T>> vec2(int n, int m, T v = 0) { V<V<T>> ret(n, V<T>(m, v)); return ret; }
template <typename T>
V<V<V<T>>> vec3(int n, int m, int l, T v = 0) {
  V<V<V<T>>> ret(n, V<V<T>>(m, V<T>(l, v))); return ret;
}
// clang-format on

int main() {
}
