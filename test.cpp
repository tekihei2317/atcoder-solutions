#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

ll extGCD(ll a, ll b, ll &x, ll &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  ll d = extGCD(b, a % b, y, x);
  y -= a / b * x;
  return d;
}

int main() {
  ll a = 5, b = 7;
  ll x, y;
  extGCD(a, b, x, y);
  cout << x << ' ' << y << endl;
}