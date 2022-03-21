#include <bits/stdc++.h>

using namespace std;

int N;
int main() {
  scanf("%d", &N);

  for (int n = 0; n < N; n++) {
    bool isSucceed = false;
    int K;
    scanf("%d", &K);

    if (K & 1) {  // 홀수면 무조건 right
      printf("Gazua\n");
      continue;
    }

    for (int i = 3; (i * (i + 1)) / 2 <= K; i++) {
      if (i & 1) {
        if (K % i == 0) {
          isSucceed = true;
          break;
        }
      } else {
        if ((K % i) * 2 == i) {
          isSucceed = true;
          break;
        }
      }
    }

    (isSucceed) ? printf("Gazua\n") : printf("GoHanGang\n");
  }

  return 0;
}