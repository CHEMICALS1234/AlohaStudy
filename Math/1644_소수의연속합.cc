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
#define MAX_N 4'000'002

int N;
vector<bool> isPrime(MAX_N, true);
vi primes;

void makeTable() {
  for (int i = 2; i * i <= N; i++) {
    if (!isPrime[i])
      continue;
    for (int j = 2 * i; j <= N; j += i) {
      isPrime[j] = false;
    }
  }

  for (int i = 2; i <= N; i++) {
    if (isPrime[i])
      primes.push_back(i);
  }
}

void solve() {
  makeTable();
  int start = 0, end = 0;
  int ans = 0, sum = 0;

  for (;;) {
    if (sum > N) {
      sum -= primes[start];
      start++;
      continue;
    }

    if (sum == N) {
      ans++;
    }

    if (end >= primes.size())
      break;

    // 짜피 나중에 처리하면 됨.
    sum += primes[end];
    end++;
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  solve();
  return 0;
}