#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define N_MAX 1001;

using namespace std;

void bfs(int start, vector<int> graph[], bool check[])
{
  queue<int> q;

  q.push(start);
  check[start] = true;

  while (!q.empty())
  {
    int tmp = q.front();
    q.pop();
    // cout << tmp << "\n";
    for (int i = 0; i < graph[tmp].size(); i++)
    {
      if (check[graph[tmp][i]] == false)
      {
        q.push(graph[tmp][i]);
        check[graph[tmp][i]] = true;
      }
    }
  }
}

int main()
{
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);

  int n, m, start, count = 0;
  cin >> n >> m;
  vector<int> graph[1001];
  bool check[1001] = {
      false,
  };

  for (int i = 0; i < m; ++i)
  {
    int s, e;
    cin >> s >> e;
    graph[s].push_back(e);
    graph[e].push_back(s);
  }

  for (int i = 1; i <= n; i++)
    sort(graph[i].begin(), graph[i].end());

  while (1)
  {
    bool temp_check = false;
    for (int i = 1; i <= n; i++)
    {
      if (check[i] == false)
      {
        start = i;
        // cout << "start : " << start << "\n";
        temp_check = true;
        break;
      }
    }
    // cout << "temp_check : " << temp_check << "\n";
    if (temp_check == true)
    {
      bfs(start, graph, check);
      count++;
    }
    else
    {
      cout << count << "\n";
      break;
    }
  }

  return 0;
}