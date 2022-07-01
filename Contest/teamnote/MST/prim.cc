#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using node_t = ll;
using dist_t = ll;
using edge_t = pair<dist_t, node_t>;

#define endl "\n"
#define INF 2e18
#define V_MAX 100'005

vector<edge_t> graph[V_MAX];
vector<bool> visited(V_MAX, false);
dist_t dist[V_MAX];

dist_t prim(node_t start) {
  dist_t ans = 0;

  priority_queue<edge_t, vector<edge_t>, greater<edge_t>> pq;
  pq.push({0, start});

  while (!pq.empty()) {
    dist_t weight;
    node_t currNode;

    tie(weight, currNode) = pq.top();
    pq.pop();

    if (visited[currNode])
      continue;

    visited[currNode] = true;
    ans += weight;

    for (edge_t e : graph[currNode]) {
      node_t nextNode;
      dist_t nextDist;

      tie(nextDist, nextNode) = e;

      if (visited[nextNode])
        continue;

      pq.push({nextDist, nextNode});
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