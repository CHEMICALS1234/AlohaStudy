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

ll N, S;
vll nums(22);
ll ans;

void makeTable(ll i, ll last, ll sum) {
  if (i == last) {
    if (sum == S) {
      ans++;
    }
    return;
  }
  makeTable(i + 1, last, sum + nums[i]);
  makeTable(i + 1, last, sum);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> S;
  for (int i = 0; i < N; i++) {
    cin >> nums[i];
  }

  makeTable(0, N, 0);

  if (S == 0) {
    ans--;
  }

  cout << ans << endl;

  return 0;
}