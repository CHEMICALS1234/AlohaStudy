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

#define MAXSIZE 505

string str;

// dp[i][j]는 str[i, j]의 최대 KOI 유전자 길이
int dp[MAXSIZE][MAXSIZE];
char tb['z'] = {};

void solve() {
  for (int l = 1; l < str.length(); l++) {
    for (int i = 0; i + l < str.length(); i++) {
      int j = i + l;
      if ((str[i] == 'a' || str[i] == 'g') && (str[j] == tb[str[i]])) {
        dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + 2);
      }

      for (int k = i; k < j; k++) {
        dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j]);
      }
    }
  }
}

int main() {
  FAST;
  tb['a'] = 't';
  tb['g'] = 'c';

  cin >> str;

  solve();
  cout << dp[0][str.length() - 1] << endl;

  return 0;
}