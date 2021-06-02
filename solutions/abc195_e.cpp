#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int N;
string S, X;
int dp[200010][7];

bool rec(int i, int j) {
  if (dp[i][j] >= 0) return dp[i][j];

  if (i == N) {
    return (int)(j == 0);
  }

  int res;
  if (X[i] == 'T') {
    // 遷移先のいずれかがtrueであれば高橋くんの勝利
    res = false;
    if (rec(i + 1, (j * 10) % 7)) res = true;
    if (rec(i + 1, (j * 10 + (S[i] - '0')) % 7)) res = true;
  } else {
    // 遷移先がすべてtrueであれば高橋くんの勝利
    res = true;
    if (!rec(i + 1, (j * 10) % 7)) res = false;
    if (!rec(i + 1, (j * 10 + (S[i] - '0')) % 7)) res = false;
  }
  return dp[i][j] = res;
}

int main() {
  cin >> N;
  cin >> S;
  cin >> X;

  rep(i, N + 1) rep(j, 7) dp[i][j] = -1;
  cout << (rec(0, 0) ? "Takahashi" : "Aoki") << endl;
}