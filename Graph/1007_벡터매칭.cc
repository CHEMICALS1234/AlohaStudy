#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using node_t = ll;
using dist_t = ll;
using vi = vector<int>;
using vll = vector<ll>;
using point_t = pair<ll, ll>;

#define all(x) (x).begin(), (x).end()

#define endl "\n"
#define INF 2e18
#define MOD 1'000'000'007

int T;
int N;
int half;

vector<point_t> pnts(22);
vector<bool> visited(22, false);

double dfs(int index, int depth) {
  if (depth == half) {
    ll x = 0, y = 0;
    for (int i = 0; i < N; i++) {
      // + 할 점
      if (visited[i]) {
        x += pnts[i].first;
        y += pnts[i].second;
      }
      else {
        x -= pnts[i].first;
        y -= pnts[i].second;
      }
    }

    double dist = sqrt(x * x + y * y);
    return dist;
  }

  double res = 1029320340912830.0;
  for (int i = index; i < N; i++) {
    // backtracking
    visited[i] = true;
    res = min(res, dfs(i + 1, depth + 1));
    visited[i] = false;
  }

  return res;
}

void solve() {
  cin >> N;
  half = N / 2;
  for (int i = 0; i < N; i++) {
    cin >> pnts[i].first >> pnts[i].second;
  }

  cout << setprecision(18) << dfs(0, 0) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  while (T--) {
    fill(all(visited), false);
    solve();
  }

  return 0;
}