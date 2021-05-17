#include <iostream>
#include <algorithm>
#include <tuple>

using namespace std;
typedef tuple<int, int, int> Edge;

const int N_MAX = 550;
const int M_MAX = 6009;
const int INF = 987654321;

int N, M;
long long dist[N_MAX];

Edge edges[M_MAX];

bool bellmanFord(int start)
{
  int a, b, w;
  fill(dist, dist + N_MAX, INF);
  dist[start] = 0;

  for (int v = 1; v <= N - 1; v++)
  {
    for (Edge e : edges)
    {
      tie(a, b, w) = e;
      dist[b] = min(dist[b], dist[a] + w);
    }
  }

  for (Edge e : edges)
  {
    tie(a, b, w) = e;
    if (dist[b] > dist[a] + w)
      return true;
  }

  return false;
}

int main()
{
  scanf("%d %d", &N, &M);

  for (int m = 0; m < M; m++)
  {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    edges[m] = make_tuple(a, b, c);
  }

  bool result = bellmanFord(1);

  if (result)
  {
    printf("-1");
  }
  else
  {
    for (int i = 2; i <= N; i++)
    {
      printf("%lld\n", (dist[i] == INF) ? -1 : dist[i]);
    }
  }
  return 0;
}