#include <bits/stdc++.h>

using namespace std;

#define INF 1987654321
#define V_MAX 1'000'005

#define endl "\n"

using ll = long long;
using node_t = ll;

vector<ll> graph[V_MAX];
bool visited[V_MAX] = {
    false,
};

void dfs(node_t start) {
  visited[start] = true;
  cout << start << " ";

  for (node_t nextNode : graph[start]) {
    if (visited[nextNode])
      continue;
    dfs(nextNode);
  }
}

void bfs(node_t start) {
  queue<node_t> q;
  visited[start] = true;
  q.push(start);

  while (!q.empty()) {
    node_t currNode = q.front();
    cout << currNode << " ";
    q.pop();

    for (node_t nextNode : graph[currNode]) {
      if (visited[nextNode])
        continue;
      visited[nextNode] = true;
      q.push(nextNode);
    }
  }
}

ll N, M, V;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M >> V;

  for (int i = 0; i < M; i++) {
    ll a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  for (auto& i : graph) {
    sort(i.begin(), i.end());
  }

  dfs(V);
  cout << endl;

  return 0;
}