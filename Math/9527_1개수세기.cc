#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using node_t = ll;
using dist_t = ll;
using vi = vector<int>;
using vll = vector<ll>;

#define all(x) (x).begin(), (x).end()

#define endl "\n"
#define INF 2e18
#define MOD 1'000'000'007

#define MAXSIZE 55

ll A, B;
vll dp(MAXSIZE);

ll getNum(ll n) {
  ll ans = n & 1;
  for (int i = MAXSIZE - 1; i > 0; i--) {
    if (n & (1LL << 1)) {
      ans += dp[i - 1];
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> A >> B;

  dp[0] = 1;
  for (int i = 1; i < 55; i++) {
    dp[i] = dp[i - 1] + dp[i - 1] + (1LL << i);
  }

  cout << getNum(B) - getNum(A - 1) << endl;

  return 0;
}