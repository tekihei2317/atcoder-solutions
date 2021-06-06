#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

using Graph = vector<vector<int>>;
using lint = long long;

vector<int> calc_depth(Graph graph) {
  int size = graph.size();
  vector<int> depth(size, 0);

  function<void(int, int)> dfs = [&](int v, int parent) {
    for (int u : graph[v])
      if (u != parent) {
        depth[u] = depth[v] + 1;
        dfs(u, v);
      }
  };
  dfs(0, -1);

  return depth;
}

vector<lint> add_to_children(Graph graph, vector<lint> &sum) {
  int size = graph.size();

  function<void(int, int)> dfs = [&](int v, int parent) {
    for (int u : graph[v])
      if (u != parent) {
        sum[u] += sum[v];
        dfs(u, v);
      }
  };
  dfs(0, -1);

  return sum;
}

int main() {
  int N;
  cin >> N;
  Graph graph = Graph(N);
  vector<pair<int, int>> edges(N - 1);
  rep(i, N - 1) {
    int a, b;
    cin >> a >> b;
    graph[a - 1].push_back(b - 1);
    graph[b - 1].push_back(a - 1);
    edges[i] = {a - 1, b - 1};
  }

  vector<int> depth = calc_depth(graph);
  int Q;
  cin >> Q;
  vector<lint> sum(N, 0);
  while (Q--) {
    int t, e, x;
    cin >> t >> e >> x;
    int a, b;
    tie(a, b) = edges[e - 1];
    if (t == 2) swap(a, b);

    if (depth[a] > depth[b]) {
      sum[a] += x;
    } else {
      sum[0] += x;
      sum[b] -= x;
    }
  }

  sum = add_to_children(graph, sum);
  rep(i, N) cout << sum[i] << endl;
}