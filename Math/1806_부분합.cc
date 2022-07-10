#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using node_t = ll;
using dist_t = ll;
using vi = vector<int>;
using vll = vector<ll>;

#define all(x) (x).begin(), (x).end()

#define endl "\n"
#define INF 987654321
#define MOD 1'000'000'007
#define MAX_N 100'005

int N, S;
vi nums(MAX_N);

void solve() {
  int s = 0, e = 0;
  int ans = INF, sum = nums[0];

  while (s <= e && e < N) {
    if (sum >= S) {
      ans = min(ans, e - s + 1);
      sum -= nums[s];
      s++;
    }
    else {
      sum += nums[e + 1];
      e++;
    }
  }

  if (ans > N)
    ans = 0;

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> S;
  for (int i = 0; i < N; i++) {
    cin >> nums[i];
  }
  solve();

  return 0;
}