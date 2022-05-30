#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;

const int MAX_N = 1'000 + 10;

int N, M, V;

vvi adj(MAX_N);

void DFS(int start, vector<bool>& visited) {
  visited[start] = true;
  printf("%d ", start);

  for (int i = 0; i < adj[start].size(); i++) {
    int next = adj[start][i];
    if (visited[next]) continue;
    DFS(next, visited);
  }
}

void BFS(int start, vector<bool>& visited) {
  queue<int> q;
  visited[start] = true;
  q.push(start);

  while (!q.empty()) {
    int curr = q.front();
    printf("%d ", curr);
    q.pop();

    for (auto& node : adj[curr]) {
      if (visited[node]) continue;
      visited[node] = true;
      q.push(node);
    }
  }
}

int main() {
  vector<bool> visited(MAX_N, false);

  scanf("%d %d %d", &N, &M, &V);

  for (int i = 0; i < M; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for (auto& i : adj) {
    sort(i.begin(), i.end());
  }

  DFS(V, visited);
  printf("\n");

  fill(visited.begin(), visited.end(), false);

  BFS(V, visited);
  printf("\n");

  return 0;
}