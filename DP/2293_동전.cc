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

#define MAX_MONEY 100'000 + 10

int dp[MAX_MONEY];
vi nums;

int main() {
  FAST;
  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    nums.push_back(a);
  }

  dp[0] = 1;

  for (int i = 0; i < n; i++) {
    for (int j = nums[i]; j <= k; j++) {
      dp[j] += dp[j - nums[i]];
    }
  }

  cout << dp[k] << endl;

  return 0;
}