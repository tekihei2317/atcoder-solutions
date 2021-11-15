#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

using Graph = vector<vector<int>>;
const int INF = 2e9;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> a(N);
  rep(i, N) cin >> a[i];

  Graph graph = Graph(N);
  rep(i, M) {
    int x, y;
    cin >> x >> y;
    graph[x - 1].push_back(y - 1);
  }

  // dp[i] := 街iに来るまでに通った街の、価格の最小値
  vector<int> dp(N, INF);
  int ans = -INF;
  rep(i, N) {
    if (dp[i] != INF) {
      ans = max(ans, a[i] - dp[i]);
    }
    for (int j : graph[i]) {
      dp[j] = min(dp[j], min(a[i], dp[i]));
    }
  }
  cout << ans << endl;
}