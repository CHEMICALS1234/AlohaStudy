#include <bits/stdc++.h>

using namespace std;

int N;
int main() {
  int s = 0, two = 0;

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    int a;
    scanf("%d", &a);
    s += a;
    two += (a / 2);
  }

  if (s % 3 != 0) {
    printf("NO\n");
    return 0;
  }

  if (two >= (s / 3))
    printf("YES\n");
  else
    printf("NO\n");

  return 0;
}