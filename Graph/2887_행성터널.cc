#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using node_t = ll;
using dist_t = ll;
using vi = vector<int>;
using vll = vector<ll>;
using edge_t = tuple<dist_t, node_t, node_t>;
using point_t = pair<node_t, int>;

#define all(x) (x).begin(), (x).end()

#define endl "\n"
#define INF 2e18
#define MOD 1'000'000'007
#define V_MAX 100'005

node_t parent[V_MAX];

vector<point_t> X, Y, Z;
vector<edge_t> graph;

node_t find(node_t node) {
  if (node == parent[node])
    return node;
  return parent[node] = find(parent[node]);
}

void uni(node_t nodeA, node_t nodeB) {
  node_t rootA = find(nodeA);
  node_t rootB = find(nodeB);

  parent[rootB] = rootA;
}

int N;

dist_t kruskal() {
  dist_t res = 0;

  for (edge_t e : graph) {
    node_t start, end;
    dist_t dist;
    tie(dist, start, end) = e;

    if (find(start) != find(end)) {
      uni(start, end);
      res += dist;
    }
  }

  return res;
}

void printVec() {
  for (auto e : graph) {
    cout << get<0>(e) << " " << get<1>(e) << " " << get<2>(e) << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  for (node_t i = 0; i < N; i++) {
    parent[i] = i;
  }

  for (int i = 0; i < N; i++) {
    node_t x, y, z;
    cin >> x >> y >> z;

    X.push_back({x, i});
    Y.push_back({y, i});
    Z.push_back({z, i});
  }

  // 각각 x,y,z 좌표 오름차순으로 정렬.
  sort(all(X));
  sort(all(Y));
  sort(all(Z));

  for (int i = 0; i < N - 1; i++) {
    graph.push_back(
        {X[i + 1].first - X[i].first, X[i].second, X[i + 1].second});
    graph.push_back(
        {Y[i + 1].first - Y[i].first, Y[i].second, Y[i + 1].second});
    graph.push_back(
        {Z[i + 1].first - Z[i].first, Z[i].second, Z[i + 1].second});
  }

  sort(all(graph));
  // 이미 정렬됨. -> pq 쓸 필요 없음.

  cout << kruskal() << endl;

  return 0;
}
