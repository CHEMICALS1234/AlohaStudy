#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);

  int min = 987654321;
  int max = -987654321;
  for (int i = 0; i < N; i++) {
    int a;
    scanf("%d", &a);
    min = (a < min) ? a : min;
    max = (a > max) ? a : max;
  }

  printf("%d %d\n", min, max);

  return 0;
}