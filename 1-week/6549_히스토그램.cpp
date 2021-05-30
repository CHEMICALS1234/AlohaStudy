#include <bits/stdc++.h>

using namespace std;

const int N_MAX = 100'000 + 50;
int n;
long long h[N_MAX];

long long histo();

int main() {
  while (true) {
    scanf("%d", &n);
    if (!n) break;

    for (int i = 0; i < n; i++) {
      scanf("%lld", &h[i]);
    }

    histo();
  }
  return 0;
}