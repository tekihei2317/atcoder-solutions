#include <bits/stdc++.h>

#include <atcoder/modint>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

// clang-format off
template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
// clang-format on

using lint = long long;
using mint = atcoder::modint;
const lint LINF = 5e18;

int solve(int a, int b, int m) {
  // ax = b (mod m)を解く
  int g = __gcd(a, m);
  if (b % g) return -1;

  a /= g, b /= g, m /= g;
  mint::set_mod(m);
  return (mint(b) * mint(a).inv()).val();
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    int X, Y, P, Q;
    cin >> X >> Y >> P >> Q;

    lint ans = LINF;
    // 電車の到着時刻が答えになる場合
    for (int r = P; r < P + Q; r++) {
      int mod = P + Q;
      lint res = solve(2 * X + 2 * Y, ((lint)r - X % mod + mod) % mod, mod);
      if (res >= 0) {
        chmin(ans, (lint)(2 * X + 2 * Y) * res + X);
      }
    }

    // 起きた時間が答えになる場合
    for (int r = X; r < X + Y; r++) {
      int mod = 2 * X + 2 * Y;
      lint res = solve(P + Q, ((lint)r - P % mod + mod) % mod, mod);
      if (res >= 0) {
        chmin(ans, (lint)(P + Q) * res + P);
      }
    }

    if (ans == LINF)
      cout << "infinity" << endl;
    else
      cout << ans << endl;
  }
}