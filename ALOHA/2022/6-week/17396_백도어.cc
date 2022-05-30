#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

using node_t = int;
using dist_t = int;
using Edge = pair<dist_t, node_t>;

constexpr int MAX_V = 100'000 + 10;
constexpr int INF = 987654321;

int N, M;

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
  int isVisible[MAX_V];

  scanf("%d %d", &N, &M);

  for (int i = 0; i < N; i++) {
    scanf("%d", &isVisible[i]);
  }

  for (int i = 0; i < M; i++) {
    int start, end, distance;
    scanf("%d %d %d", &start, &end, &distance);

    if (isVisible[start] || isVisible[end]) {
      if (start != N - 1 && end != N - 1) {
        continue;
      }
    }

    graph[start].push_back({distance, end});
    graph[end].push_back({distance, start});
  }

  Dijkstra(0);
  printf("%d\n", (dist[N - 1] == INF) ? -1 : dist[N - 1]);

  return 0;
}