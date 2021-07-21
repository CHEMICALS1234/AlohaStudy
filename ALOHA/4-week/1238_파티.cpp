#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>

using namespace std;

const int INF = 987654321;
const int MAX = 1000 + 1;

int N, M, X;
typedef pair<int, int> Edge;
vector<Edge> graph[MAX];

vector<int> dijkstra(int start)
{
  const int vertex = N + 1;
  vector<int> distance(vertex, INF); //distance라는 vector<int>를 만들고, 그것의 vertex 개를 INF로 초기화.
  distance[start] = 0;

  priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
  pq.push({0, start});

  while (!pq.empty())
  {
    int cost = pq.top().first;
    int cur = pq.top().second;
    pq.pop();

    if (distance[cur] < cost)
      continue;

    for (int i = 0; i < graph[cur].size(); i++)
    {
      int neighbor = graph[cur][i].first;
      int neighborDistance = cost + graph[cur][i].second;

      if (distance[neighbor] > neighborDistance)
      {
        distance[neighbor] = neighborDistance;
        pq.push({neighborDistance, neighbor});
      }
    }
  }

  return distance;
}

int main()
{
  scanf("%d %d %d", &N, &M, &X);

  for (int i = 0; i < M; i++)
  {
    int start, end, cost;
    scanf("%d %d %d", &start, &end, &cost);

    graph[start].push_back({end, cost});
  }

  int result = -1;

  for (int i = 1; i <= N; i++)
  {
    // i -> X
    vector<int> temp1 = dijkstra(i);
    // X -> i
    vector<int> temp2 = dijkstra(X);

    if (temp1[X] + temp2[i] >= INF || temp1[X] + temp2[i] < 0)
      continue;

    result = max(result, temp1[X] + temp2[i]);
  }

  printf("%d\n", result);
  return 0;
}