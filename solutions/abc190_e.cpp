#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

using pint = pair<int, int>;
using Graph = vector<vector<int>>;
const int INF = 1e9;

vector<vector<int>> calc_dist(Graph graph, vector<int> c) {
  // dist[i][j]:= c_iからjまでの最短距離
  vector<vector<int>> dist(c.size(), vector<int>(graph.size(), INF));

  // BFS
  rep(i, c.size()) {
    queue<int> que;
    que.push(c[i]);
    dist[i][c[i]] = 0;
    while (!que.empty()) {
      int v = que.front();
      que.pop();

      for (int u : graph[v]) {
        if (dist[i][u] == INF) {
          dist[i][u] = dist[i][v] + 1;
          que.push(u);
        }
      }
    }
  }

  return dist;
}

int main() {
  int N, M;
  cin >> N >> M;
  Graph graph(N);

  rep(i, M) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  int K;
  cin >> K;
  vector<int> c(K);
  rep(i, K) cin >> c[i], c[i]--;

  auto dist = calc_dist(graph, c);

  // dp[bit][i]:=
  // 現在置いた石の集合がbitで、最後にc_iを置いた場合の個数の最小値
  vector<vector<int>> dp(1 << K, vector<int>(K, INF));
  rep(i, K) dp[1 << i][i] = 1;
  rep(bit, 1 << K) rep(i, K) {
    if (dp[bit][i] == INF) continue;

    // dp[bit][i]からの遷移
    rep(j, K) if (~bit >> j & 1) {
      if (dist[i][c[j]] == INF) continue;
      dp[bit | (1 << j)][j] =
          min(dp[bit | (1 << j)][j], dp[bit][i] + dist[i][c[j]]);
    }
  }

  int ans = INF;
  rep(i, K) { ans = min(ans, dp[(1 << K) - 1][i]); }
  cout << (ans == INF ? -1 : ans) << endl;
}
