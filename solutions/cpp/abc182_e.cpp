#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

void update(bool& is_reach, char square, int& ok) {
  if (square == 'L') {
    is_reach = true;
    ok = true;
  } else if (square == 'B') {
    is_reach = false;
  } else {
    ok = ok || (is_reach == true);
  }
}

int main() {
  int H, W, N, M;
  cin >> H >> W >> N >> M;
  vector<string> grid(H, string(W, '.'));
  rep(i, N) {
    int y, x;
    cin >> y >> x;
    grid[y - 1][x - 1] = 'L';
  }
  rep(i, M) {
    int y, x;
    cin >> y >> x;
    grid[y - 1][x - 1] = 'B';
  }

  // ok[i][j] := (i, j)に光が届くかどうか
  // vector<vector<bool>>使うとなんか怒られたのでintで...
  vector<vector<int>> ok(H, vector<int>(W, 0));

  rep(i, H) {
    bool is_reach = false;
    rep(j, W) { update(is_reach, grid[i][j], ok[i][j]); }

    is_reach = false;
    for (int j = W - 1; j >= 0; j--) {
      update(is_reach, grid[i][j], ok[i][j]);
    }
  }

  rep(j, W) {
    bool is_reach = false;
    rep(i, H) { update(is_reach, grid[i][j], ok[i][j]); }

    is_reach = false;
    for (int i = H - 1; i >= 0; i--) {
      update(is_reach, grid[i][j], ok[i][j]);
    }
  }

  int answer = 0;
  rep(i, H) rep(j, W) if (ok[i][j]) answer++;
  cout << answer << endl;
}