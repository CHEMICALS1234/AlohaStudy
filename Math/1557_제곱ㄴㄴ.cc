#include <bits/stdc++.h>

#define FAST                         \
  ios_base ::sync_with_stdio(false); \
  cin.tie(NULL);                     \
  cout.tie(NULL);

#define endl "\n"

using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<long long>;

#define MAXRANGE 50000

vll mu(MAXRANGE);

void setup() {
  mu[1] = 1;
  for (int i = 1; i < MAXRANGE; i++) {
    for (int j = 2 * i; j < MAXRANGE; j += i) {
      mu[j] -= mu[i];
    }
  }
}

ll findSQNum(ll n) {
  ll res = 0;
  for (ll i = 1; i * i <= n; i++) {
    res += mu[i] * n / (i * i);
  }

  return res;
}

int main() {
  FAST;
  setup();

  ll K;

  cin >> K;

  ll low = 0, high = K * 2, mid;

  while (low < high - 1) {
    mid = (low + high) / 2;
    ll num = findSQNum(mid);
    if (num < K) {
      low = mid;
    }
    else {
      high = mid;
    }
  }

  cout << high << endl;

  return 0;
}