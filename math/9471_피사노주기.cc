#include <bits/stdc++.h>

using namespace std;

int period(int M) {
  vector<int> fisano{1, 1};
  for (int i = 0;; i++) {
    fisano.push_back((fisano[i] + fisano[i + 1]) % M);
    if (fisano[i + 1] == 1 && fisano[i + 2] == 1) {
      return (i + 1);
    }
  }
}

int main() {
  int P, N, M;

  scanf("%d", &P);

  for (int i = 0; i < P; i++) {
    scanf("%d %d", &N, &M);
    printf("%d %d\n", N, period(M));
  }
}