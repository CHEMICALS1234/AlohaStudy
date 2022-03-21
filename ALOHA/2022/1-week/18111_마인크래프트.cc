#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 500 + 10;
constexpr int MAX_M = 500 + 10;
constexpr int INF = 987654321;

int N, M, B;
int maps[MAX_N][MAX_M];

int main() {
  int mininum = INF, maximum = 0;

  scanf("%d %d %d", &N, &M, &B);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%d", &maps[i][j]);

      mininum = min(mininum, maps[i][j]);
      maximum = max(maximum, maps[i][j]);
    }
  }

  pair<int, int> res(INF, 0);

  for (int k = 0; k <= 256; k++) {
    int time = 0;
    int inven = B;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (maps[i][j] > k) {
          time += (maps[i][j] - k) * 2;
          inven += (maps[i][j] - k);
        } else if (maps[i][j] < k) {
          time += (k - maps[i][j]);
          inven -= (k - maps[i][j]);
        }
      }
    }
    if (inven >= 0) {
      if (time < res.first) {
        res = {time, k};
      }
      if (time == res.first) {
        if (k > res.second) {
          res = {time, k};
        }
      }
    }
  }

  printf("%d %d\n", res.first, res.second);

  return 0;
}