#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_RANGE = 7980 + 10;
constexpr int E_MAX = 15, S_MAX = 28, M_MAX = 19;

int main() {
  int E, S, M;
  scanf("%d %d %d", &E, &S, &M);

  for (int i = 1; i < MAX_RANGE; i++) {
    E %= E_MAX;
    S %= S_MAX;
    M %= M_MAX;

    if (i % E_MAX == E && i % S_MAX == S && i % M_MAX == M) {
      printf("%d\n", i);
      return 0;
    }
  }
  return 0;
}