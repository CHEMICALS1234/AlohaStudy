#include <bits/stdc++.h>

using namespace std;

const int MAX = 1'000'000 + 50;
bool arr[MAX] = {
    false,
};

int findSqn(long long minValue, long long maxValue) {
  for (long long i = 2; i * i < maxValue; i++) {
    for (long long j = (minValue) / (i * i); j * i * i < maxValue; j++) {
      long long val = j * i * i;
      if (val > minValue) {
        arr[val - minValue] = true;
      }
    }
  }

  long long len = maxValue - minValue + 1;
  int count = 0;

  for (int i = 0; i < len; i++) {
    if (!arr[i]) count++;
  }

  return count;
}

int main() {
  long long minValue, maxValue;
  scanf("%lld %lld", &minValue, &maxValue);

  printf("%d\n", findSqn(minValue, maxValue));

  return 0;
}
