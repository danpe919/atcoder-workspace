#include <bits/stdc++.h>
using namespace std;

template <typename T>
set<T> factorize(T num) {
  set<T> result;
  T d = 2;
  while (d * d <= num) {
    if (num % d == 0) {
      num /= d;
      result.insert(d);
    } else {
      d++;
    }
  }
  if (num != 1) result.insert(num);
  return result;
}

template <typename T>
map<T, int> factorize_num(T num) {
  map<T, int> result;
  T d = 2;
  while (d * d <= num) {
    if (num % d == 0) {
      num /= d;
      result[d]++;
    } else {
      d++;
    }
  }
  if (num != 1) result[num]++;
  return result;
}
