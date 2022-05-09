#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 20 + 5;
const int MAX_W = 1000000;
int cost[MAX_N], cus[MAX_N];
int dp[MAX_W];

int main() {
  int C, N;
  scanf("%d %d", &C, &N);

  for (int i = 1; i <= N; i++) {
    scanf("%d %d", &cost[i], &cus[i]);
  }

  int minCost = INT_MAX;

  for (int k = 1; k <= N; k++) {
    for (int w = 1; w <= MAX_W; w++) {
      if (w - cost[k] >= 0) {
        dp[w] = max(dp[w], dp[w - cost[k]] + cus[k]);
      }

      if (C <= dp[w]) {
        minCost = min(minCost, w);
      }
    }
  }

  printf("%d\n", minCost);

  return 0;
}