#include <bits/stdc++.h>

using namespace std;

const int INF = 2'000'000'009;
const int V_MAX = 1'000'006;

typedef pair<int, int> Edge;
vector<Edge> edges[V_MAX];
int dist[V_MAX];

void Dijkstra(int start) {
  fill(dist, dist + V_MAX, INF);
  priority_queue<Edge> PQ;
  PQ.push({0, start});

  while (!PQ.empty()) {
    int u, v, d, w;
    tie(d, u) = PQ.top();
    PQ.pop();

    if (dist[u] < INF) continue;
    dist[u] = -d;

    for (Edge e : edges[u]) {
      tie(v, w) = e;
      if (dist[v] < INF) continue;
      PQ.push({d - w, v});
    }
  }
}

int V, E, K;

int main() {
  int a, b, w, x;
  scanf("%d %d", &V, &E);
  for (int e = 1; e <= E; e++) {
    scanf("%d %d %d", &a, &b, &w);
    edges[a].push_back({b, w});
  }
  scanf("%d", &x);

  Dijkstra(1);
  int dist_x = dist[x];
  Dijkstra(x);

  for (int v = 1; v <= V; v++) {
    if (dist[v] == INF)
      printf("-1 ");
    else
      printf("%d ", dist[v] + dist_x);
  }
  return 0;
}