#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  scanf("%d", &N);

  int count = 0;

  for (int i = 1; i <= N; i++) {
    if (i == 1000) break;
    if (i < 100) {
      count++;
    } else {
      if ((i / 100 + i % 10) == 2 * ((i / 10) % 10)) {
        count++;
      }
    }
  }

  printf("%d\n", count);
  return 0;
}