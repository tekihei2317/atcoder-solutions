#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int largest_rectangle(vector<int> a) {
  // 番兵
  a.insert(a.begin(), {-1});
  a.insert(a.end(), {-1});

  int n = a.size();
  // indexes := 右に自分以下の値が存在しないような添字の集合
  // (i < j かつ a_i >= a_jとなるようなjが存在しないiの集合)
  vector<int> indexes;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    while (indexes.size() > 1 && a[indexes.back()] >= a[i]) {
      int center = indexes.back();
      // right := j > center かつ a_j <= a_centerとなるような最小のj
      int right = i;
      // left := j < centerかつ a_j < a_centerとなるような最大のj
      int left = indexes[indexes.size() - 2];
      ans = max(ans, a[center] * (right - left - 1));
      indexes.pop_back();
    }
    indexes.push_back(i);
  }
  return ans;
}

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  rep(i, N) cin >> a[i];

  cout << largest_rectangle(a) << endl;
}