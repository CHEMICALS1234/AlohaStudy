#include <bits/stdc++.h>

using namespace std;

int N;
const int MAX_N = 20 + 5;
const int MAX_H = 100;

int h[MAX_N], joy[MAX_N];
int dp[MAX_N][MAX_H + 1];

int main() {
  scanf("%d", &N);
  h[0] = joy[0] = 0;

  for (int i = 1; i <= N; i++) {
    scanf("%d", &h[i]);
  }
  for (int i = 1; i <= N; i++) {
    scanf("%d", &joy[i]);
  }

  for (int k = 1; k <= N; k++) {
    for (int w = 1; w <= MAX_H; w++) {
      if (w - h[k] > 0) {
        dp[k][w] = max(dp[k - 1][w - h[k]] + joy[k], dp[k - 1][w]);
      } else {
        dp[k][w] = dp[k - 1][w];
      }
    }
  }

  printf("%d\n", dp[N][MAX_H]);

  return 0;
}