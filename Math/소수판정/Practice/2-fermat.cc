#include <iostream>
#include <random>

using namespace std;

int modPow(int base, int exp, int mod) {
  int result = 1;
  for (; exp; exp >>= 1, base = ((base % mod) * (base % mod)) % mod) {
    if (exp & 1) result = (result * base) % mod;
  }
  return result;
}

bool isPrimeFermat(int n, int iterNum = 10) {
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<int> dis(2, n - 2);

  if (n < 4) return n == 2 || n == 3;
  for (int i = 0; i < iterNum; i++) {
    int a = dis(gen);
    if (modPow(a, n - 1, n) != 1) return false;
  }
  return true;
}

int main() {
  int n;
  cin >> n;
  cout << isPrimeFermat(n) << "\n";
  return 0;
}