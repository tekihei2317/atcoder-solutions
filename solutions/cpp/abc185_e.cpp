#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

const int INF = 1e9;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> a(N), b(M);
  rep(i, N) cin >> a[i];
  rep(i, M) cin >> b[i];

  // dp[i][j] := A[0, i)とB[0, j)に対する答え
  vector<vector<int>> dp(N + 1, vector<int>(M + 1, INF));
  rep(i, N + 1) dp[i][0] = i;
  rep(j, M + 1) dp[0][j] = j;

  rep(i, N) rep(j, M) {
    if (a[i] == b[j]) {
      dp[i + 1][j + 1] = dp[i][j];
    } else {
      // 両方使う場合(dx = 0, dy = 1)
      dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + 1);
      // a_iだけ使う場合(dx = 1)
      dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i + 1][j] + 1);
      // b_iだけ使う場合(dx = 1)
      dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j + 1] + 1);
    }
  }
  cout << dp[N][M] << endl;
}