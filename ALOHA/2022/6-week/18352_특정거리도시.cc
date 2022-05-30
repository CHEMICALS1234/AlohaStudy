#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

#define MAX_N 300'010

using namespace std;

using dist_t = int;
using node_t = int;

int N, M, K, X;

vector<vector<node_t>> graph(MAX_N);

void BFS() {
  bool visit[MAX_N] = {
      false,
  };
  vector<node_t> result;
  queue<pair<dist_t, node_t>> q;

  q.push({0, X});

  while (!q.empty()) {
    dist_t distance = q.front().first;
    node_t current = q.front().second;
    q.pop();

    if (visit[current])
      continue;
    visit[current] = true;

    if (distance == K) {
      result.push_back(current);
      // 이것과 붙어있는 다음 노드들은 방문할 필요 없음.
      continue;
    }

    for (auto& next : graph[current]) {
      if (visit[next])
        continue;
      q.push({distance + 1, next});
    }
  }

  if (result.size() == 0) {
    printf("-1\n");
  }
  else {
    sort(result.begin(), result.end());
    for (node_t node : result) {
      printf("%d\n", node);
    }
  }
}

int main() {
  scanf("%d %d %d %d", &N, &M, &K, &X);

  for (int i = 0; i < M; i++) {
    node_t a, b;
    scanf("%d %d", &a, &b);
    graph[a].push_back(b);
  }

  BFS();
  return 0;
}