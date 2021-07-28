#include <iostream>
#include <algorithm>
#include <vector>

#define FAST                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);

using namespace std;
using ll = long long;

const int ARR_MAX = 2'000 + 10;

int pascal[ARR_MAX][ARR_MAX];
int modulo;

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

vector<int> getDigit(ll n) {
  vector<int> temp;
  while (n) {
    temp.push_back(n % modulo);
    n /= modulo;
  }
  return temp;
}

int lucas(ll n, ll k) {
  int result = 1;
  vector<int> nDigit = getDigit(n), kDigit = getDigit(k);

  for (int i = 0; i < max(nDigit.size(), kDigit.size()); i++) {
    int nd, kd;
    if (i < nDigit.size())
      nd = nDigit[i];
    else
      nd = 0;

    if (i < kDigit.size())
      kd = kDigit[i];
    else
      kd = 0;

    if (nd < kd) return 0;
    result = (result * getCombination(nd, kd) % modulo) % modulo;
  }
  return result;
}

int main() {
  FAST;
  init();
  ll n, k;
  cin >> n >> k >> modulo;
  cout << lucas(n, k) << "\n";
  return 0;
}