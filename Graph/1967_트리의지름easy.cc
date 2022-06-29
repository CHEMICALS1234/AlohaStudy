#include <bits/stdc++.h>

#define FAST                         \
  ios_base ::sync_with_stdio(false); \
  cin.tie(NULL);                     \
  cout.tie(NULL);

#define endl "\n"

using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<long long>;
using vpi = vector<pair<int, int>>;

#define MAX_V 10'005

vpi graph[MAX_V];
bool visited[MAX_V] = {
    false,
};
int V;
int maxDist = 0, maxNode = 0;

void DFS(int start, int dist) {
  if (visited[start])
    return;

  if (maxDist < dist) {
    maxDist = dist;
    maxNode = start;
  }

  visited[start] = true;

  for (int i = 0; i < graph[start].size(); i++) {
    int next = graph[start][i].first;
    int nextDist = graph[start][i].second;
    DFS(next, dist + nextDist);
  }
}

int main() {
  FAST;

  cin >> V;
  for (int i = 0; i < V - 1; i++) {
    int start, end, dist;
    cin >> start >> end >> dist;

    graph[start].push_back({end, dist});
    graph[end].push_back({start, dist});
  }

  DFS(1, 0);
  fill(visited, visited + MAX_V, false);

  maxDist = 0;
  DFS(maxNode, 0);

  cout << maxDist << endl;

  return 0;
}