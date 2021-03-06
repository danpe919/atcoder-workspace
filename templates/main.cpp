// clang-format off
#include <bits/stdc++.h>
#define overload3(a, b, c, d, ...) d
#define rep2(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep3(i, st, n) for (int i = st; i < (int)(n); ++i)
#define rep(...) overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)
#define rrep2(i, n) for (int i = (int)(n - 1); i >= 0; --i)
#define rrep3(i, n, st) for (int i = (int)(n - 1); i >= (st); --i)
#define rrep(...) overload3(__VA_ARGS__, rrep3, rrep2, rep1)(__VA_ARGS__)
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
template <class T> using pri_queue = priority_queue<T, V<T>, greater<T>>;
constexpr int IINF = 1 << 30;
constexpr ll LINF = 1LL << 62;
constexpr ll MOD = 1e9 + 7;
template <class T> T max(const V<T>& v) { return *max_element(ALL(v)); }
template <class T> T min(const V<T>& v) { return *min_element(ALL(v)); }
template <class T> ll sum(const V<T>& v) { return accumulate(ALL(v), 0LL); }
template <class T> void sort(V<T>& v) { sort(v.begin(), v.end()); }
template <class T> void reverse(V<T>& v) { reverse(v.begin(), v.end()); }
template <typename T> istream& operator>>(istream& i, V<T>& v) {
  rep(j, LEN(v)) i >> v[j];
  return i;
}
template<typename T, typename ...Args>
auto make_vector(T x, int arg, Args ...args) {
  if constexpr(sizeof...(args) == 0) return vector<T>(arg, x);
  else return vector(arg, make_vector<T>(x, args...));
}
// #include <atcoder/modint>
// using namespace atcoder;
// using mint = atcoder::modint1000000007;
// clang-format on

int main() {
}
