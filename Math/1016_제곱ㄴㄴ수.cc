#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  long long min, max;
  cin >> min >> max;

  long long ans = max - min + 1;

  vector<bool> sieve(max - min + 1, false);
  long long i = 2;

  while (i * i <= max) {
    long long sNum = min / (i * i);
    if (min % (i * i) != 0)
      sNum += 1;

    while (sNum * (i * i) <= max) {
      if (sieve[sNum * (i * i) - min] == false) {
        sieve[sNum * (i * i) - min] = true;
        ans -= 1;
      }
      sNum += 1;
    }
    i += 1;
  }

  cout << ans;
  return 0;
}