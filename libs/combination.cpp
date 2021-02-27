#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
template <class T>
using V = vector<T>;

const ll mod = 1e9 + 7;

/**
 * @brief nCk mod Mを求めるクラス
 * @note 前処理 O(n), クエリ O(1)
 */
class Chooser {
  V<ll> fac, finv, inv;
  ll MOD;

 public:
  Chooser(int n_, ll mod = 1e9 + 7) : fac(n_), finv(n_), inv(n_), MOD(mod) {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < n_; i++) {
      fac[i] = fac[i - 1] * i % MOD;
      inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
      finv[i] = finv[i - 1] * inv[i] % MOD;
    }
  }
  ll choose(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
  }
};

/**
 * @brief nCkを求めるクラス
 * @note 前処理 O(n^2), クエリ O(1)
 */
class Chooser {
 public:
  int n;
  vector<vector<ll>> comb;
  Chooser(int n_) : n(n_ + 1) {
    init();
  }
  ll choose(int n, int k) {
    return comb[n][k];
  }

 private:
  void init() {
    comb.assign(n, vector<ll>(n));
    comb[0][0] = 1;
    for (int i = 1; i < n; i++) {
      comb[i][0] = 1;
      for (int j = 1; j < n; j++) {
        comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
      }
    }
  }
};
