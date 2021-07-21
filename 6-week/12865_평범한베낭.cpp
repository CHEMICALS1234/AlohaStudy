#include <bits/stdc++.h>

using namespace std;

const int N_MAX = 100 + 10;
const int W_MAX = 100'000 + 10;

int dp[N_MAX][W_MAX];

int main() {
  int N, W;
  scanf("%d %d", &N, &W);

  int _w[N_MAX], c[N_MAX];

  for (int i = 1; i <= N; i++) {
    scanf("%d %d", &_w[i], &c[i]);
  }

  for (int k = 1; k <= N; k++) {
    for (int w = 0; w <= W; w++) {
      if (w >= _w[k])
        dp[k][w] = max(dp[k - 1][w], dp[k - 1][w - _w[k]] + c[k]);
      else
        dp[k][w] = dp[k - 1][w];
    }
  }

  printf("%d\n", dp[N][W]);

  return 0;
}