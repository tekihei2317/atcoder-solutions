#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
const int LINF = 1e18;

ll calc(int A, int B, int C) {
  // Ax = B(mod C)の答え
  // Ax + Cy = Bを満たす(x, y)を求める
}

ll solve(int X, int Y, int P, int Q) {
  // 1. (2X+2Y)n+X <= T < (2X+2Y)n+X+Y
  // 2. (P+Q)k+P <= T < (P+Q)k+P+Q
  // 答えは区間の始点になるので、1の始点の場合と、2の始点の場合に分けて解く

  int answer = LINF;
  // 1の始点の場合
  for (int r = P; r < P + Q; r++) {
    // (2X+2Y)n+X = r(mod P+Q)
    int n = calc(2 * X + 2 * Y, r - X, P + Q);
    answer = min(answer, (2 * X + 2 * Y) * n + X);
  }

  // 2の始点の場合
  for (int r = X; r < X + Y; r++) {
    // (P+Q)k+P = r(mod 2X+2Y)
    int k = calc(P + Q, r - P, 2 * X + 2 * Y);
    answer = min(answer, (P + Q) * k + P);
  }

  return answer;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    int X, Y, P, Q;
    cin >> X >> Y >> P >> Q;
    cout << solve(X, Y, P, Q) << endl;
  }
}