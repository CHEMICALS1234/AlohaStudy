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

using matrix = vector<vector<long long>>;

#define MOD 1'000'000'007

matrix operator*(const matrix& a, const matrix& b) {
  int n = a.size();
  matrix m(n, vll(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        m[i][j] += a[i][k] * b[k][j];
      }
      m[i][j] %= MOD;
    }
  }

  return m;
}

int main() {
  FAST;

  ll N;
  cin >> N;

  if (N <= 1) {
    cout << 1 << endl;
    return 0;
  }

  matrix ans = {{1, 0}, {0, 1}};
  matrix a = {{1, 1}, {1, 0}};

  while (N > 0) {
    if (N & 1) {
      ans = ans * a;
    }
    a = a * a;
    N >>= 1;
  }

  cout << (ans[0][1] % MOD) << endl;

  return 0;
}