#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

struct mint {
  static ll MOD;
  ll x;
  mint(ll x = 0) : x((x % MOD + MOD) % MOD) {}
  mint operator-() const { return mint(-x); }
  mint& operator+=(const mint a) {
    if ((x += a.x) >= MOD) x -= MOD;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += MOD - a.x) >= MOD) x -= MOD;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= MOD;
    return *this;
  }
  mint operator+(const mint a) const { return mint(*this) += a; }
  mint operator-(const mint a) const { return mint(*this) -= a; }
  mint operator*(const mint a) const { return mint(*this) *= a; }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t >> 1);
    a *= a;
    if (t & 1) a *= *this;
    return a;
  }

  // for prime MOD
  mint inv() const { return pow(MOD - 2); }
  mint& operator/=(const mint a) { return *this *= a.inv(); }
  mint operator/(const mint a) const { return mint(*this) /= a; }
};
ll mint::MOD = 1e9 + 7;
istream& operator>>(istream& is, mint& a) { return is >> a.x; }
ostream& operator<<(ostream& os, const mint& a) { return os << a.x; }

/**
 * @brief a^n mod m を求める
 *
 * @param a
 * @param n
 * @param m
 * @return ll
 * @note 計算量 O(log n)
 */
ll modpow(ll a, ll n, ll m) {
  ll ret = 1;
  while (n > 0) {
    if (n & 1) ret = ret * a % m;
    a = a * a % m;
    n >>= 1;
  }
  return ret;
}
