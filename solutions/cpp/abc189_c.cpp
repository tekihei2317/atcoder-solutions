#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  rep(i, N) cin >> a[i];
  a.push_back(0);

  // 右に自分より小さい値が存在しないような添字の集合
  vector<int> indexes = {-1};
  int ans = 0;
  rep(i, N + 1) {
    while (indexes.size() > 1 and a[indexes.back()] > a[i]) {
      // 小さい値が出てきた場合
      int l = indexes[indexes.size() - 2] + 1;
      ans = max(ans, a[indexes.back()] * (i - l));
      indexes.pop_back();
    }
    indexes.push_back(i);
  }
  cout << ans << endl;
}