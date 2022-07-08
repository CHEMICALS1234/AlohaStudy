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

#define MAX_N 42

ll N, S;
vll nums(MAX_N);
vll leftArr, rightArr;

void makeTable(ll i, ll last, ll sum, vll& v) {
  if (i == last) {
    v.push_back(sum);
    return;
  }
  // 계속 더함.
  makeTable(i + 1, last, sum + nums[i], v);

  // 다음으로 넘어감.
  makeTable(i + 1, last, sum, v);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> S;
  for (int i = 0; i < N; i++) {
    cin >> nums[i];
  }
  makeTable(0, N / 2, 0, leftArr);
  makeTable(N / 2, N, 0, rightArr);

  sort(all(rightArr));

  ll ans = 0;
  for (ll i : leftArr) {
    auto l = lower_bound(all(rightArr), S - i);
    auto u = upper_bound(all(rightArr), S - i);
    ans += u - l;
  }

  if (S == 0) {
    ans--;
  }

  cout << ans << endl;

  return 0;
}