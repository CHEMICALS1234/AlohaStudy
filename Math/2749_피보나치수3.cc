#include <bits/stdc++.h>

using namespace std;

const int MOD = 1'000'000;
const int MAX = 1'500'000;
long long arr[MAX + 50];

void fibo() {
  arr[0] = 0;
  arr[1] = 1;
  for (int i = 0; i < MAX; i++) {
    arr[i + 2] = (arr[i] + arr[i + 1]) % MOD;
  }
}

int main() {
  long long n;
  scanf("%lld", &n);
  fibo();
  printf("%lld", arr[n % MAX]);
  return 0;
}