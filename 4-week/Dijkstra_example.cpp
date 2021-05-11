#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

const int INF = 2'000'000'009;
const int V_MAX = 1'000'006;

typedef pair<int, int> Edge;
vector<Edge> edges[V_MAX];
int dist[V_MAX];

void Dijkstra(int start)
{
  fill(dist, dist + V_MAX, INF);
  priority_queue<Edge> PQ;
  PQ.push({0, start});

  while (!PQ.empty())
  {
    int u, v, d, w;
    tie(d, u) = PQ.top();
    PQ.pop();

    if (dist[u] < INF)
      continue;
    dist[u] = -d;

    for (Edge e : edges[u])
    {
      tie(v, w) = e;
      if (dist[v] < INF)
        continue;
      PQ.push({d - w, v});
    }
  }
}