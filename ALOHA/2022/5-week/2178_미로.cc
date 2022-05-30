#include <bits/stdc++.h>
#define MAX_N 110
#define INF 987654321
#define endl '\n'

using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using Point = pair<int, int>;

int N, M;
bool check[MAX_N][MAX_N];
int maps[MAX_N][MAX_N];
int length[MAX_N][MAX_N];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void BFS(int startX, int startY) {
  queue<Point> q;
  q.push({startY, startX});
  length[startY][startX] = 1;
  check[startY][startX] = true;

  while (!q.empty()) {
    int x = q.front().second;
    int y = q.front().first;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int nextX = x + dx[i];
      int nextY = y + dy[i];

      if (nextX < 0 || nextY < 0)
        continue;
      if (nextX > M || nextY > N)
        continue;
      if (maps[nextY][nextX] == 0 || check[nextY][nextX] == true)
        continue;

      length[nextY][nextX] = length[y][x] + 1;
      check[nextY][nextX] = true;
      q.push({nextY, nextX});
    }
  }
}

int main() {
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%1d", &maps[i][j]);
    }
  }
  BFS(0, 0);
  printf("%d\n", length[N - 1][M - 1]);
  return 0;
}