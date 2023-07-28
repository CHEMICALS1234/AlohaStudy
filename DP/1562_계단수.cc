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
#define MOD 1'000'000'000

int N;
int dp[100 + 5][10][1 << 10];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  // Exclude number starting with 0.
  // Therefore, start from 1.
  for (int i = 1; i < 10; i++) {
    dp[1][i][1 << i] = 1;
  }

  for (int len = 0; len < N; len++) {
    for (int lastnum = 0; lastnum < 10; lastnum++) {
      for (int bit = 0; bit < (1 << 10); bit++) {
        int nextbit;
        int currdp = dp[len][lastnum][bit];

        // Check if lastnum is not 9.
        if (lastnum < 9) {
          nextbit = bit | (1 << (lastnum + 1));
          int& nextdp = dp[len + 1][lastnum + 1][nextbit];

          nextdp += currdp;
          nextdp %= MOD;
        }

        // Check if lastnum is not 0.
        if (lastnum > 0) {
          nextbit = bit | (1 << (lastnum - 1));
          int& nextdp = dp[len + 1][lastnum - 1][nextbit];

          nextdp += currdp;
          nextdp %= MOD;
        }

        // Pass for 0, 9 case.
      }
    }
  }

  int ans = 0;
  for (int lastnum = 0; lastnum < 10; lastnum++) {
    // Only calc for 111...111 case.
    ans += dp[N][lastnum][1023];
    ans %= MOD;
  }

  cout << ans << "\n";

  return 0;
}