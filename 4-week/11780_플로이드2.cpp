#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
const int N_MAX = 102;
const int INF = 987654321;
int dist[N_MAX][N_MAX];
vector<int> path[N_MAX][N_MAX];

void floyd()
{
  for (int k = 1; k <= n; k++)
  {
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        if (dist[i][k] + dist[k][j] > dist[i][j])
          continue;

        dist[i][j] = dist[i][k] + dist[k][j];

        vector<int> tempVec = path[k][j];

        path[i][j].clear();
        path[i][j] = path[i][k];

        for (int m = 1; m < tempVec.size(); m++) // k가 중복되므로, m = 1부터 시작한다.
          path[i][j].push_back(tempVec[m]);
      }
    }
  }
}

int main()
{
  scanf("%d %d", &n, &m);

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      dist[i][j] = (i == j) ? 0 : INF;
      path[i][j].push_back(i);
      path[i][j].push_back(j);
    }
  }

  for (int i = 0; i < m; i++)
  {
    int start, end, cost;
    scanf("%d %d %d", &start, &end, &cost);
    dist[start][end] = min(dist[start][end], cost);
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      printf("%d ", (dist[i][j] == INF) ? 0 : dist[i][j]);
    }
    printf("\n");
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      printf("%d ", path[i][j].size());
      for (int k = 0; k < path[i][j].size(); k++)
      {
        printf("%d ", path[i][j][k]);
      }
      printf("\n");
    }
  }
  return 0;
}