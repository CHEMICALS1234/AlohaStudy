#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using ll = long long;

int N, K;
vi arr;

int calcHowmany(ll mid) {
  int howmany = 0;
  for (auto a : arr) {
    howmany += (a / mid);
  }
  return howmany;
}

int paraSearch(int num) {
  ll start = 0, end = INT_MAX;
  while (start <= end) {
    ll mid = (start + end) / 2;

    int howmany = calcHowmany(mid);

    if (howmany > num) {
      start = mid + 1;
    } else if (howmany < num) {
      end = mid - 1;
    } else {
      while (true) {
        if (calcHowmany(mid + 1) < num) return mid;
        mid++;
      }
    }
  }

  return 0;
}

int main() {
  scanf("%d %d", &K, &N);
  for (int i = 0; i < K; i++) {
    int k;
    scanf("%d", &k);
    arr.push_back(k);
  }

  printf("%d\n", paraSearch(N));

  return 0;
}
