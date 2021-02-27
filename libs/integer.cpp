
template <typename T>
int digits(T n) {
  int ret = 1;
  while (n >= 10) {
    ret++;
    n /= 10;
  }
  return ret;
}

/**
 * nのiビット目を返す
 */
template <typename T>
int bit(T n, int i) {
  return n >> i & 1;
}
