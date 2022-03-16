#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
const int N_MAX = 102;
const int INF = 987654321;
int dist[N_MAX][N_MAX];

void floyd()
{
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main()
{
  scanf("%d %d", &n, &m);

  for (int i = 0; i < N_MAX; i++)
  {
    for (int j = 0; j < N_MAX; j++)
    {
      dist[i][j] = (i == j) ? 0 : INF;
    }
  }

  for (int i = 0; i < m; i++)
  {
    int start, end, cost;
    scanf("%d %d %d", &start, &end, &cost);
    dist[start][end] = min(dist[start][end], cost);
  }

  floyd();

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      printf("%d ", (dist[i][j] == INF) ? 0 : dist[i][j]);
    }
    printf("\n");
  }

  return 0;
}