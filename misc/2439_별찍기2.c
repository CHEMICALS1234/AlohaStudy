#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);

  for (int i = N - 1; i >= 0; i--) {
    int j = 0;
    for (j = 0; j < i; j++) {
      printf(" ");
    }
    for (; j < N; j++) {
      printf("*");
    }
    printf("\n");
  }
  return 0;
}
