#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

using node_t = int;
using dist_t = int;
using Edge = pair<dist_t, node_t>;

constexpr int MAX_V = 20'000 + 10;
constexpr int INF = 987654321;

int V, E, K;

vector<vector<Edge>> graph(MAX_V);
dist_t dist[MAX_V];

void Dijkstra(int start) {
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

int main() {
  scanf("%d %d %d", &V, &E, &K);

  for (int i = 0; i < E; i++) {
    int start, end, distance;
    scanf("%d %d %d", &start, &end, &distance);

    graph[start].push_back({distance, end});
  }

  Dijkstra(K);

  for (int i = 1; i <= V; i++) {
    if (dist[i] == INF)
      printf("INF\n");
    else
      printf("%d\n", dist[i]);
  }

  return 0;
}