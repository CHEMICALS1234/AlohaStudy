// using Fermat's Little Theorem

#include <iostream>
#define FAST                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);

using namespace std;

const int modulo = 1'000'000'007;

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

  int n, k;
  cin >> n >> k;

  if (2 * k > n) k = n - k;

  long long num = 1;
  for (int i = 0; i < k; i++) {
    num = (num * n--) % modulo;
  }
  long long den = 1;
  while (k) {
    den = (den * k--) % modulo;
  }
  long long result = (num * fastPow(den, modulo - 2)) % modulo;

  cout << result << "\n";

  return 0;
}