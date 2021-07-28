#include <iostream>
#define FAST                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);

using namespace std;

const int modulo = 1'000'000'007;
const int ARR_MAX = 4'000'000 + 10;

long long fact[ARR_MAX];

void init() {
  for (int i = 0; i < ARR_MAX; i++) {
    if (i == 0)
      fact[i] = 1;
    else
      fact[i] = ((fact[i - 1] % modulo) * (i % modulo)) % modulo;
  }
}

long long fastPow(long long base, int exp) {
  long long result = 1;
  for (; exp; exp >>= 1, base = (base % modulo * base % modulo) % modulo) {
    if (exp & 1) result = (result * base) % modulo;
    // cout << "base : " << base << " result : " << result << "\n";
  }
  return result;
}

int main() {
  FAST;

  int n, k, m;
  cin >> m;

  init();

  while (m--) {
    cin >> n >> k;

    long long den = (fact[k] * fact[n - k]) % modulo;
    long long result = (fact[n] * fastPow(den, modulo - 2)) % modulo;

    cout << result << "\n";
  }

  return 0;
}