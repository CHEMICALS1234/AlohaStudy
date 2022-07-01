#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using node_t = ll;
using dist_t = ll;

#define endl "\n"
#define INF 2e18

#define MAXSIZE 15

int T;
int dp[MAXSIZE] = {0, 1, 2, 4};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (int i = 4; i < MAXSIZE; i++) {
    dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
  }
  cin >> T;

  while (T--) {
    int N;
    cin >> N;
    cout << dp[N] << endl;
  }

  return 0;
}
