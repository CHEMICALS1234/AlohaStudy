#include <iostream>

using namespace std;
const int MAX_CHAP = 500 + 10;
const int INF = 987654321;

int dp[MAX_CHAP][MAX_CHAP];
int sum[MAX_CHAP] = {
    0,
};
int arr[MAX_CHAP];

void makeDP(int n) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j + i <= n; j++) {
      int jj = j + i;
      dp[j][jj] = INF;

      for (int k = j; k < jj; k++) {
        dp[j][jj] =
            min(dp[j][jj], dp[j][k] + dp[k + 1][jj] + sum[jj] - sum[j - 1]);
      }
    }
  }
}

void init() {
  for (int i = 0; i < MAX_CHAP; i++) {
    for (int j = 0; j < MAX_CHAP; j++) {
      dp[i][j] = 0;
    }
  }
}

int main() {
  int T;
  scanf("%d", &T);

  for (int t = 0; t < T; t++) {
    init();

    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
      scanf("%d", &arr[i]);
      sum[i] = sum[i - 1] + arr[i];
    }

    makeDP(n);
    printf("%d\n", dp[1][n]);
  }

  return 0;
}