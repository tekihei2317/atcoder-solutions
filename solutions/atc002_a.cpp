#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

// clang-format off
template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return 1; } return 0; }
// clang-format on

vector<vector<int>> bfs(vector<string> grid, int sy, int sx) {
  const int dy[] = {-1, 0, 0, 1};
  const int dx[] = {0, -1, 1, 0};
  const int INF = 1e9;

  int H = grid.size();
  int W = grid[0].size();
  vector<vector<int>> dist(H, vector<int>(W, INF));
  dist[sy][sx] = 0;
  queue<pair<int, int>> que;
  que.push({sy, sx});

  while (!que.empty()) {
    int y = que.front().first;
    int x = que.front().second;
    que.pop();

    rep(k, 4) {
      int ny = y + dy[k];
      int nx = x + dx[k];
      if (ny < 0 || ny >= H || nx < 0 || nx >= W || grid[ny][nx] == '#') continue;

      if (chmin(dist[ny][nx], dist[y][x] + 1)) que.push({ny, nx});
    }
  }

  return dist;
}

int main() {
  int H, W;
  cin >> H >> W;
  int sy, sx, gy, gx;
  cin >> sy >> sx >> gy >> gx;
  sy--, sx--;
  gy--, gx--;
  vector<string> grid(H);
  rep(i, H) cin >> grid[i];

  auto dist = bfs(grid, sy, sx);
  cout << dist[gy][gx] << endl;
}