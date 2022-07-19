#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using node_t = double;
using dist_t = double;
using vi = vector<int>;
using vll = vector<ll>;
using point_t = pair<node_t, node_t>;
using edge_t = tuple<dist_t, int, int>;

#define all(x) (x).begin(), (x).end()

#define endl "\n"
#define INF 2e18
#define MOD 1'000'000'007
#define MAX_N 105

vector<point_t> stars(MAX_N);
int parent[MAX_N] = {};

int N;

int find(int node) {
  if (node == parent[node])
    return node;
  return parent[node] = find(parent[node]);
}

void uni(int a, int b) {
  a = find(a);
  b = find(b);

  parent[b] = a;
}

double calcDistance(const point_t& p1, const point_t& p2) {
  return (sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2)));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  priority_queue<edge_t, vector<edge_t>, greater<edge_t>> pq;

  cin >> N;
  for (int i = 0; i < N; i++) {
    parent[i] = i;
  }
  for (int i = 0; i < N; i++) {
    cin >> stars[i].first >> stars[i].second;
  }

  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      pq.push({calcDistance(stars[i], stars[j]), i, j});
    }
  }

  dist_t ans = 0;

  while (!pq.empty()) {
    edge_t e = pq.top();
    pq.pop();

    int nodeFrom, nodeTo;
    dist_t weight;

    tie(weight, nodeFrom, nodeTo) = e;

    if (find(nodeFrom) != find(nodeTo)) {
      uni(nodeFrom, nodeTo);
      ans += weight;
    }
  }

  cout << fixed;
  cout.precision(2);
  cout << ans << endl;

  return 0;
}