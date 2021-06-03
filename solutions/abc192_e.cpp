#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

struct Edge {
  int to, cost, interval;
};
using Graph = vector<vector<Edge>>;

using lint = long long;
using pint = pair<lint, int>;
const lint LINF = 1e18;

int main() {
  int N, M, X, Y;
  cin >> N >> M >> X >> Y;
  X--;
  Y--;

  Graph graph = Graph(N);
  rep(i, M) {
    int a, b, t, k;
    cin >> a >> b >> t >> k;
    a--;
    b--;
    graph[a].push_back({b, t, k});
    graph[b].push_back({a, t, k});
  }

  vector<lint> dist(N, LINF);
  dist[X] = 0;
  priority_queue<pint, vector<pint>, greater<pint>> que;
  que.push({0, X});

  while (!que.empty()) {
    lint d = que.top().first;
    int v = que.top().second;
    que.pop();

    if (d > dist[v]) continue;

    for (Edge e : graph[v]) {
      lint next_departure =
          (dist[v] + e.interval - 1) / e.interval * e.interval;
      lint next_dist = next_departure + e.cost;
      if (next_dist < dist[e.to]) {
        dist[e.to] = next_dist;
        que.push({next_dist, e.to});
      }
    }
  }
  cout << (dist[Y] == LINF ? -1 : dist[Y]) << endl;
}