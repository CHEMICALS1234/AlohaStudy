#include <bits/stdc++.h>

using namespace std;

const int N_MAX = 100;
const int W_MAX = 100'000;

int main() {
  ;
  int N, W;
  int _w[N_MAX + 1], c[N_MAX];

  int dp[N_MAX + 1][W_MAX + 1];

  for (int k = 0; k < N; k++) {
    for (int w = 0; w < W; w++) {
      if (w >= _w[k])
        dp[k + 1][w] = max(dp[k][w], dp[k][w - _w[k]] + c[k]);
      else
        dp[k + 1][w] = dp[k][w];
    }
  }
  return 0;
}