#include <bits/stdc++.h>
using namespace std;

int dp[5000 + 10];

int N;

int main() {
  scanf("%d", &N);

  dp[3] = dp[5] = 1;

  for (int i = 6; i <= N; i++) {
    if (dp[i - 3]) {
      dp[i] = dp[i - 3] + 1;
    }
    if (dp[i - 5]) {
      dp[i] = dp[i] ? min(dp[i], dp[i - 5] + 1) : dp[i - 5] + 1;
    }
  }

  printf("%d\n", (dp[N] ? dp[N] : -1));

  return 0;
}