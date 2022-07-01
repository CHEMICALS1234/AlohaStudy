#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using node_t = ll;
using dist_t = ll;

#define endl "\n"
#define INF 2e18

#define V_MAX 100'000

node_t parent[V_MAX];

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

using edge_t = tuple<dist_t, node_t, node_t>;

// MST의 length를 반환.
dist_t kruskal(priority_queue<edge_t, vector<edge_t>, greater<edge_t>>& pq) {
  dist_t ans = 0;

  while (!pq.empty()) {
    edge_t e = pq.top();
    pq.pop();

    node_t nodeFrom, nodeTo;
    dist_t weight;

    tie(weight, nodeFrom, nodeTo) = e;

    if (find(nodeFrom) != find(nodeTo)) {
      uni(nodeFrom, nodeTo);
      ans += weight;
    }
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}