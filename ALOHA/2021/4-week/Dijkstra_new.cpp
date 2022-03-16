#include <iostream>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

constexpr int INF = 987654321;
constexpr int MAX_NODE = 20'000 + 50;

using Edge = pair<int, int>;
vector<Edge> edges[MAX_NODE];
int dist[MAX_NODE];

void Dijkstra(int start) {
  fill(dist, dist + MAX_NODE, INF);
  priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

  dist[start] = 0;

  pq.push({0, start});

  while (!pq.empty()) {
    int curr_dist = pq.top().first;
    int current = pq.top().second;
    pq.pop();

    if (curr_dist > dist[current]) continue;

    for (Edge next_edge : edges[current]) {
      int next = next_edge.first;
      int next_dist = curr_dist + next_edge.second;

      if (next_dist < dist[next]) {
        dist[next] = next_dist;
        pq.push({next_dist, next});
      }
    }
  }
}

int V, E, K;

int main() {
  int a, b, w;
  scanf("%d %d %d", &V, &E, &K);
  for (int e = 1; e <= E; e++) {
    scanf("%d %d %d", &a, &b, &w);
    edges[a].push_back({b, w});
  }

  Dijkstra(K);

  for (int v = 1; v <= V; v++) {
    if (dist[v] == INF)
      printf("INF\n");
    else
      printf("%d\n", dist[v]);
  }
  return 0;
}