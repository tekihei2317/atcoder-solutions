#include <bits/stdc++.h>

#include <atcoder/modint>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

using mint = atcoder::modint;

int solve(int N, int S, int K) {
  // Kx = -S (mod N)を解く

  // Kx mod Nはg = gcd(K, N)の倍数なので、Sがgの倍数であることが必要
  int g = __gcd(K, N);
  if (S % g) return -1;

  K /= g;
  S /= g;
  N /= g;

  mint::set_mod(N);
  mint ans = mint(-S + N) * mint(K).inv();

  return ans.val();
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    int N, S, K;
    cin >> N >> S >> K;
    cout << solve(N, S, K) << endl;
  }
}