/* DYNAMIC PROGRAMMING
   (n,k) = (n-1,k-1) + (n-1,k) */

#include <iostream>
#define FAST                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);

using namespace std;

const int ARR_MAX = 1'000 + 10;
const int modulo = 10'007;
int pascal[ARR_MAX][ARR_MAX];

void init() {
  for (int i = 0; i < ARR_MAX; i++) {
    for (int j = 0; j <= i; j++) {
      if (i == 0 || j == 0 || j == i)
        pascal[i][j] = 1;
      else
        pascal[i][j] = 0;
    }
  }
}

int getCombination(int n, int k) {
  if (pascal[n][k] != 0) return (pascal[n][k] % modulo);
  return pascal[n][k] = ((getCombination(n - 1, k - 1) % modulo) +
                         (getCombination(n - 1, k) % modulo)) %
                        modulo;
}

int main() {
  FAST;

  init();
  int n, k;
  cin >> n >> k;

  if (2 * k > n) k = n - k;

  cout << getCombination(n, k) << "\n";
}