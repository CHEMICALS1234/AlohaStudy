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
#define MAXSIZE 1'005

ll T;
vll A(MAXSIZE), B(MAXSIZE);
vll aSum, bSum;

void printVec(const vll& v) {
  for (auto& i : v) {
    cout << i << " ";
  }
  cout << endl;
}

void solve() {
  int N, M;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  cin >> M;
  for (int i = 0; i < M; i++) {
    cin >> B[i];
  }

  for (int i = 0; i < N; i++) {
    ll sum = 0;
    for (int j = i; j < N; j++) {
      sum += A[j];
      aSum.push_back(sum);
    }
  }

  for (int i = 0; i < M; i++) {
    ll sum = 0;
    for (int j = i; j < M; j++) {
      sum += B[j];
      bSum.push_back(sum);
    }
  }

  sort(all(bSum));

  ll ans = 0;
  for (ll a : aSum) {
    ans += upper_bound(all(bSum), T - a) - lower_bound(all(bSum), T - a);
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  solve();

  return 0;
}
