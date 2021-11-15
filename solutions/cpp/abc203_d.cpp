#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
  int N, K;
  cin >> N >> K;
  vector<vector<int>> a(N, vector<int>(N));
  rep(i, N) rep(j, N) cin >> a[i][j];

  auto check = [=](int x) {
    vector<vector<int>> sum(N + 1, vector<int>(N + 1, 0));
    rep(i, N) rep(j, N) {
      sum[i + 1][j + 1] =
          sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + (a[i][j] <= x);
    }
    rep(i, N - K + 1) rep(j, N - K + 1) {
      int countNoMoreThanX =
          sum[i + K][j + K] - sum[i][j + K] - sum[i + K][j] + sum[i][j];
      if (countNoMoreThanX >= (K * K + 1) / 2) return true;
    }
    return false;
  };

  int ng = -1, ok = 1e9;
  while (ok - ng > 1) {
    int mid = (ng + ok) / 2;
    if (check(mid))
      ok = mid;
    else
      ng = mid;
  }
  cout << ok << endl;
}