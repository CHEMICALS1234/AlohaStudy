#include <bits/stdc++.h>

using namespace std;

#define INF 1987654321
#define V_MAX 1'000'005
#define E_MAX 20'000'005

using ll = long long;
using node_t = ll;
using dist_t = ll;
using edge_t = tuple<dist_t, node_t, node_t>;

edge_t edges[E_MAX];
dist_t dist[V_MAX];
ll V, E;

bool bellmanFord(node_t start) {
  fill(dist, dist + V_MAX, INF);
  dist[start] = 0;

  node_t nodeFrom, nodeTo;
  dist_t weight;

  // 최단거리 갱신
  for (ll v = 1; v <= V - 1; v++) {
    for (edge_t e : edges) {
      tie(weight, nodeFrom, nodeTo) = e;
      dist[nodeTo] = min(dist[nodeTo], dist[nodeFrom] + weight);
    }
  }

  // 음수 사이클 파악
  for (edge_t e : edges) {
    tie(weight, nodeFrom, nodeTo) = e;
    if (dist[nodeTo] > dist[nodeFrom] + weight)
      return true;
  }

  return false;
}
