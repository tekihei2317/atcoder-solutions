#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

struct Edge {
  int to, cost;
};
using Graph = vector<vector<Edge>>;
using pint = pair<int, int>;

const int INF = 1e9;

vector<int> dijkstra(Graph graph, int s) {
  int n = graph.size();
  vector<int> dist(n, INF);
  dist[s] = 0;
  priority_queue<pint, vector<pint>, greater<pint>> que;
  que.push({0, s});

  while (!que.empty()) {
    int d = que.top().first;
    int v = que.top().second;
    que.pop();

    if (d > dist[v]) continue;

    for (auto e : graph[v]) {
      if (dist[e.to] > dist[v] + e.cost) {
        dist[e.to] = dist[v] + e.cost;
        que.push({dist[e.to], e.to});
      }
    }
  }
  return dist;
}

int main() {
  int N, M;
  cin >> N >> M;

  Graph graph = Graph(N);
  Graph rev_graph = Graph(N);

  rep(i, M) {
    int a, b, c;
    cin >> a >> b >> c;
    graph[a - 1].push_back({b - 1, c});
    rev_graph[b - 1].push_back({a - 1, c});
  }

  int ans = INF;
  rep(i, N) {
    auto dist_from_i = dijkstra(graph, i);
    auto dist_to_i = dijkstra(rev_graph, i);

    // 他の頂点を通らない場合
    int ans = INF;
    for (auto e : graph[i])
      if (e.to == i) ans = min(ans, e.cost);

    // 他の頂点を通る場合
    rep(j, N) if (i != j) { ans = min(ans, dist_from_i[j] + dist_to_i[j]); }

    cout << (ans == INF ? -1 : ans) << endl;
  }
}