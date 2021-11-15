#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

using lint = long long;

int main() {
  int N;
  cin >> N;
  vector<int> x(N), y(N);
  rep(i, N) cin >> x[i] >> y[i];

  int M;
  cin >> M;
  vector<lint> a, b, c, d, e, f;
  a = b = c = d = e = f = vector<lint>(M + 1);
  a[0] = 1;
  e[0] = 1;
  rep(i, M) {
    int type, p;
    cin >> type;
    if (type >= 3) cin >> p;

    a[i + 1] = a[i];
    b[i + 1] = b[i];
    c[i + 1] = c[i];
    d[i + 1] = d[i];
    e[i + 1] = e[i];
    f[i + 1] = f[i];
    if (type == 1) {
      a[i + 1] = d[i];
      b[i + 1] = e[i];
      c[i + 1] = f[i];
      d[i + 1] = -a[i];
      e[i + 1] = -b[i];
      f[i + 1] = -c[i];
    } else if (type == 2) {
      a[i + 1] = -d[i];
      b[i + 1] = -e[i];
      c[i + 1] = -f[i];
      d[i + 1] = a[i];
      e[i + 1] = b[i];
      f[i + 1] = c[i];
    } else if (type == 3) {
      a[i + 1] = -a[i];
      b[i + 1] = -b[i];
      c[i + 1] = -c[i] + 2 * p;
      d[i + 1] = d[i];
      e[i + 1] = e[i];
      f[i + 1] = f[i];
    } else {
      a[i + 1] = a[i];
      b[i + 1] = b[i];
      c[i + 1] = c[i];
      d[i + 1] = -d[i];
      e[i + 1] = -e[i];
      f[i + 1] = -f[i] + 2 * p;
    }
  }

  int Q;
  cin >> Q;
  while (Q--) {
    int cnt, index;
    cin >> cnt >> index;
    index--;

    cout << a[cnt] * x[index] + b[cnt] * y[index] + c[cnt] << ' '
         << d[cnt] * x[index] + e[cnt] * y[index] + f[cnt] << endl;
  }
}