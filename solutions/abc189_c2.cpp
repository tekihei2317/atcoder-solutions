#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

vector<int> calc_right_border(vector<int> a) {
  int N = a.size();
  vector<int> right(N, N);

  // 右に自分より小さい値が存在しないような添字の集合
  vector<int> indexes;
  rep(i, N) {
    while (!indexes.empty() && a[indexes.back()] > a[i]) {
      right[indexes.back()] = i;
      indexes.pop_back();
    }
    indexes.push_back(i);
  }

  return right;
}

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  rep(i, N) cin >> a[i];

  vector<int> right = calc_right_border(a);
  reverse(a.begin(), a.end());
  vector<int> left = calc_right_border(a);

  reverse(a.begin(), a.end());
  reverse(left.begin(), left.end());
  rep(i, N) left[i] = (N - 1) - left[i];

  int ans = 0;
  rep(i, N) { ans = max(ans, a[i] * (right[i] - left[i] - 1)); }
  cout << ans << endl;
}