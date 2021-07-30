#include <iostream>

using namespace std;

long long modPow(long long tempBase, long long exp, long long mod) {
  __int128_t result = 1, base = tempBase % mod;
  while (exp) {
    if (exp & 1) result = (result * base) % mod;
    base = ((base % mod) * (base % mod)) % mod;
    exp >>= 1;
  }
  return result;
}

bool checkComposite(long long n, long long a, long long d, int s) {
  auto x = modPow(a, d, n);
  if (x == 1 || x == n - 1) return false;
  for (int r = 1; r < s; r++) {
    x = static_cast<__int128_t>(x) * x % n;
    if (x == n - 1) return false;
  }
  return true;
}

bool isPrimeMillerRabin(long long x) {
  if (x < 2) return false;
  int r = 0;
  long long d = x - 1;
  while ((d & 1) == 0) {
    d >>= 1;
    r++;
  }
  for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
    if (x == a) return true;
    if (checkComposite(x, a, d, r)) return false;
  }
  return true;
}

int main() {
  long long n;
  cin >> n;
  cout << isPrimeMillerRabin(n) << "\n";
  return 0;
}