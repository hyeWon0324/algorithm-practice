#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 101;
bool light[MAX][MAX];
bool visited[MAX][MAX];
vector<pair<int, int>> v[MAX][MAX];
queue<pair<int, int>> q;
int n, m;
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {-1, 0, 1, 0};
bool cango(int x, int y, int a, int b) {
  memset(visited, false, sizeof(visited));
  queue<pair<int, int>> q2;
  q2.push({x, y});
  visited[x][y] = true;
  while (!q2.empty()) {
    int curX = q2.front().first;
    int curY = q2.front().second;
    q2.pop();
    if (curX == a && curY == b) {
      return true;
    }
    for (int i = 0; i < 4; i++) {
      int nextX = curX + dirX[i];
      int nextY = curY + dirY[i];
      if (nextX < 1 || nextX > n || nextY < 1 || nextY > n) {
        continue;
      }
      if (!light[nextX][nextY] || visited[nextX][nextY]) {
        continue;
      }
      q2.push(make_pair(nextX, nextY));
      visited[nextX][nextY] = true;
    }
  }
  return false;
}
void bfs() {
  while (!q.empty()) {
    int curX = q.front().first;
    int curY = q.front().second;
    q.pop();
    if (!v[curX][curY].empty()) {
      for (int i = 0; i < v[curX][curY].size(); i++) {
        int nextX = v[curX][curY][i].first;
        int nextY = v[curX][curY][i].second;
        if (!light[nextX][nextY]) {
          light[nextX][nextY] = true;
          if (cango(curX, curY, nextX, nextY)) {
            q.push(make_pair(nextX, nextY));
          }
        }
      }
      v[curX][curY].clear();
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  light[1][1] = true;
  for (int i = 0; i < m; i++) {
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    if (x == 1 && y == 1) {
      light[a][b] = true;
      q.push(make_pair(a, b));
    }
    v[x][y].push_back(make_pair(a, b));
  }
  bfs();
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (light[i][j] == true) {
        cnt++;
      }
    }
  }
  cout << cnt;
  return 0;
}