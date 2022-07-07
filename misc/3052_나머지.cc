#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using node_t = ll;
using dist_t = ll;

#define endl "\n"
#define INF 2e18
#define MOD 42

vector<bool> isMod(MOD, false);
int cnt;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (int i = 0; i < 10; i++) {
    int a;
    cin >> a;

    isMod[a % MOD] = true;
  }

  for (int i = 0; i < MOD; i++) {
    if (isMod[i])
      cnt++;
  }

  cout << cnt << endl;

  return 0;
}