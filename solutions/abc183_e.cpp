#include <bits/stdc++.h>

#include <atcoder/modint>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

using mint = atcoder::modint1000000007;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> s(H + 1);
  // 1-indexed
  for (int i = 1; i <= H; i++) {
    cin >> s[i];
    s[i] = '.' + s[i];
  }

  vector<vector<mint>> dp, L, U, X;
  dp = L = U = X = vector<vector<mint>>(H + 1, vector<mint>(W + 1, 0));

  dp[1][1] = U[1][1] = L[1][1] = X[1][1] = 1;
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      if (i == 1 && j == 1) continue;

      if (s[i][j] == '.') {
        dp[i][j] = L[i][j - 1] + U[i - 1][j] + X[i - 1][j - 1];
        L[i][j] = L[i][j - 1] + dp[i][j];
        U[i][j] = U[i - 1][j] + dp[i][j];
        X[i][j] = X[i - 1][j - 1] + dp[i][j];
      } else {
        dp[i][j] = L[i][j] = U[i][j] = X[i][j] = 0;
      }
    }
  }
  cout << dp[H][W].val() << endl;
}