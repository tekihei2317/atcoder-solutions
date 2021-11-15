#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

using lint = long long;

vector<int> calc_left(vector<lint> a) {
  int N = a.size();
  // left[i] := j < i かつ a_j < a[i]となる最大のj(存在しない場合は-1)
  vector<int> left(N);

  // indexes := 右に自分以下の値が存在しないような添字の集合
  // (i < j かつ a_i >= a_jとなるようなjが存在しないiの集合)
  vector<int> indexes = {-1};  // 番兵
  rep(i, N) {
    while (indexes.size() > 1 && a[indexes.back()] >= a[i]) {
      indexes.pop_back();
    }
    left[i] = indexes.back();
    indexes.push_back(i);
  }
  return left;
}

template <typename T>
T largest_rectangle(vector<T> a) {
  // オーバーフローに注意
  int N = a.size();

  vector<int> left, right;
  rep(loop, 2) {
    (loop == 0 ? left : right) = calc_left(a);
    reverse(a.begin(), a.end());
  }
  reverse(right.begin(), right.end());
  rep(i, N) right[i] = N - 1 - right[i];

  T ans = 0;
  rep(i, N) ans = max(ans, a[i] * (right[i] - left[i] - 1));
  return ans;
}

int main() {
  int N;
  cin >> N;
  vector<lint> a(N);
  rep(i, N) cin >> a[i];

  cout << largest_rectangle(a) << endl;
}