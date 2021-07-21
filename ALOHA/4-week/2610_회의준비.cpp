#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
const int N_MAX = 102;
const int INF = 987654321;
int dist[N_MAX][N_MAX];

int main()
{
  scanf("%d %d", &N, &M);

  for (int i = 0; i < N_MAX; i++)
  {
    for (int j = 0; j < N_MAX; j++)
    {
      dist[i][j] = (i == j) ? 0 : INF;
    }
  }

  for (int m = 0; m < M; m++)
  {
    int person1, person2;
    scanf("%d %d", &person1, &person2);
    dist[person1][person2] = dist[person2][person1] = 1;
  }

  return 0;
}