#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using node_t = ll;
using dist_t = ll;

#define endl "\n"
#define INF 2e18
#define MOD 1'000'000'007

int T;

int calc(int cnt) { return cnt * (cnt + 1) / 2; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  while (T--) {
    string s;
    int cnt = 0;
    int ans = 0;
    cin >> s;
    for (char c : s) {
      if (c == 'X') {
        ans += calc(cnt);
        cnt = 0;
      }
      else {
        cnt++;
      }
    }
    ans += calc(cnt);
    cout << ans << endl;
  }

  return 0;
}