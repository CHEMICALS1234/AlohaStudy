#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000 + 50;

int dp[MAX], arr[MAX];
int N;

int makeTable() {
  int m = 0;
  for (int i = 0; i < N; i++) {
    dp[i] = 1;
    for (int j = 0; j < i; j++) {
      if (arr[j] < arr[i]) {
        dp[i] = max(dp[i], dp[j] + 1);
        m = max(m, dp[i]);
      }
    }
  }
  return m;
}

void printArr() {
  for (int i = 0; i < N; i++) {
    printf("%d ", dp[i]);
  }
  printf("\n");
}

int main() {
  scanf("%d", &N);

  for (int i = 0; i < N; i++) {
    scanf("%d", &arr[i]);
  }
  printf("%d\n", makeTable());
  return 0;
}