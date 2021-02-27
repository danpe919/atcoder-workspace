#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
template <class T>
using V = vector<T>;

// 最大フローの算出
template <class T>
class FordFulkerson {
 public:
  struct Edge {
    int to;
    T cap;
    int rev;
    Edge(int t, T c, int r) : to(t), cap(c), rev(r) {}
  };
  const ll INF = 1e9;
  V<V<Edge>> g;
  V<int> used;

  Graph(int n_ = 0) : g(n_), used(n_) {}
  void add_edge(int from, int to, T cap = 1) {
    g[from].push_back(Edge(to, cap, g[to].size()));
    g[to].push_back(Edge(from, 0, g[from].size() - 1));
  }
  T max_flow(int s, int t) {
    T ret = 0;
    while (true) {
      fill(used.begin(), used.end(), 0);
      T f = dfs(s, t, INF);
      if (f == 0) break;
      ret += f;
    }
    return ret;
  }
  T dfs(int v, int t, T flow) {
    if (v == t) return flow;
    used[v] = 1;
    for (Edge& e : g[v]) {
      if (used[e.to] || e.cap <= 0) continue;
      auto ret = dfs(e.to, t, min(flow, e.cap));
      if (ret > 0) {
        e.cap -= ret;
        g[e.to][e.rev].cap += ret;
        return ret;
      }
    }
    return 0;
  }
};
