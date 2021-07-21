// #include <bits/stdc++.h>

// using namespace std;

// const int MAX = 1'000'000 + 50;
// bool arr[MAX] = {
//     false,
// };

// int findSqn(long long minValue, long long maxValue) {
//   for (long long i = 2; i * i < maxValue; i++) {
//     for (long long j = (minValue) / (i * i); j * i * i <= maxValue; j++) {
//       long long val = j * i * i;
//       if (val >= minValue) {
//         arr[val - minValue] = true;
//       }
//     }
//   }

//   long long len = maxValue - minValue + 1;
//   int count = 0;

//   for (int i = 0; i < len; i++) {
//     if (!arr[i]) count++;
//   }

//   return count;
// }

// int main() {
//   long long minValue, maxValue;
//   scanf("%lld %lld", &minValue, &maxValue);

//   printf("%d\n", findSqn(minValue, maxValue));

//   return 0;
// }

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
    if (min % (i * i) != 0) sNum += 1;

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