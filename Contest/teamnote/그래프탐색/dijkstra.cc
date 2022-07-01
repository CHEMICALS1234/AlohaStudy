#include <bits/stdc++.h>

using namespace std;

#define INF 1987654321
#define V_MAX 1'000'005

using ll = long long;
using node_t = ll;
using dist_t = ll;
using edge_t = pair<dist_t, node_t>;

vector<edge_t> graph[V_MAX];
ll dist[V_MAX];

void dijkstra(node_t start) {
  fill(dist, dist + V_MAX, INF);
  priority_queue<edge_t, vector<edge_t>, greater<edge_t>> pq;
  pq.push({0, start});

  while (!pq.empty()) {
    node_t currNode, nextNode;
    dist_t currDist, nextDist;

    tie(currDist, currNode) = pq.top();
    pq.pop();

    if (dist[currNode] < INF) {
      continue;
    }
    dist[currNode] = currDist;

    for (edge_t e : graph[currNode]) {
      tie(nextDist, nextNode) = e;

      if (dist[nextNode] < INF) {
        continue;
      }

      pq.push({currDist + nextDist, nextNode});
    }
  }
}

ll V, E, K;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  scanf("%lld %lld %lld", &V, &E, &K);

  for (int i = 0; i < E; i++) {
    ll start, end, distance;
    scanf("%lld %lld %lld", &start, &end, &distance);

    graph[start].push_back({distance, end});
  }

  dijkstra(K);

  for (int i = 1; i <= V; i++) {
    if (dist[i] == INF)
      printf("INF\n");
    else
      printf("%lld\n", dist[i]);
  }

  return 0;
}