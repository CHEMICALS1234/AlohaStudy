#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using node_t = ll;
using dist_t = ll;
using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int, int>;
using vpi = vector<pi>;

#define all(x) (x).begin(), (x).end()

#define endl "\n"
#define INF 2e18
#define MOD 1'000'000'007

int N, K;
vi bags;
vpi gems;

priority_queue<int, vector<int>, less<int>> maxheap;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // mass, value of gem
  int m, v;
  // capacity of bag
  int c;

  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    cin >> m >> v;
    gems.push_back({m, v});
  }

  for (int i = 0; i < K; i++) {
    cin >> c;
    bags.push_back(c);
  }

  // sort both vector in ascending order
  sort(bags.begin(), bags.end());
  sort(gems.begin(), gems.end());

  // Fill the bag with the least capacity first.
  ll res = 0;
  int gemidx = 0;
  for (int i = 0; i < K; i++) {
    // Push capable gems in pq.
    while (gemidx < N && gems[gemidx].first <= bags[i]) {
      maxheap.push(gems[gemidx].second);
      gemidx++;
    }

    if (!maxheap.empty()) {
      res += maxheap.top();
      maxheap.pop();
    }
  }

  cout << res << "\n";
  return 0;
}