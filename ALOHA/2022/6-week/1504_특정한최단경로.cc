#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

using ll = long long;
using node_t = ll;
using dist_t = ll;
using Edge = pair<dist_t, node_t>;

constexpr ll MAX_V = 800 + 10;
constexpr ll INF = 1e18;

ll N, E, v1, v2;

vector<vector<Edge>> graph(MAX_V);
dist_t dist[MAX_V];

void Dijkstra(ll start) {
  fill(dist, dist + MAX_V, INF);
  priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
  pq.push({0, start});

  while (!pq.empty()) {
    node_t nodeCurr, nodeNext;
    dist_t distCurr, distNext;
    tie(distCurr, nodeCurr) = pq.top();
    pq.pop();

    if (dist[nodeCurr] < INF)
      continue;
    dist[nodeCurr] = distCurr;

    for (Edge nextEdge : graph[nodeCurr]) {
      tie(distNext, nodeNext) = nextEdge;

      if (dist[nodeNext] < INF)
        continue;

      pq.push({distCurr + distNext, nodeNext});
    }
  }
}

dist_t getMinDist(ll start, ll end) {
  Dijkstra(start);
  return (dist[end] == INF) ? -INF : dist[end];
}

int main() {
  scanf("%lld %lld", &N, &E);

  for (ll i = 0; i < E; i++) {
    ll start, end, distance;
    scanf("%lld %lld %lld", &start, &end, &distance);

    graph[start].push_back({distance, end});
    graph[end].push_back({distance, start});
  }

  scanf("%lld %lld", &v1, &v2);

  dist_t dist1 = getMinDist(1, v1) + getMinDist(v1, v2) + getMinDist(v2, N);
  dist_t dist2 = getMinDist(1, v2) + getMinDist(v2, v1) + getMinDist(v1, N);

  if (dist1 < 0 && dist2 < 0) {
    printf("-1\n");
  }
  else {
    printf("%lld\n", min(dist1, dist2));
  }

  return 0;
}