#include <bits/stdc++.h>

using namespace std;

const int V_MAX = 10'000 + 50;
const int E_MAX = 100'000 + 50;

int V, E;
int parent[V_MAX];

typedef tuple<int, int, int> Edge;
priority_queue<Edge, vector<Edge>, greater<Edge>> edge;

int ans = 0;

void init() {
  for (int i = 0; i < V_MAX; i++) {
    parent[i] = i;
  }
}

int find(int node) {
  return (node == parent[node]) ? node : (parent[node] = find(parent[node]));
}

void uni(int a, int b) { parent[find(b)] = find(a); }

int main() {
  scanf("%d %d", &V, &E);

  init();

  for (int e = 0; e < E; e++) {
    int start, end, cost;
    scanf("%d %d %d", &start, &end, &cost);
    edge.push(make_tuple(cost, start, end));
  }

  while (!edge.empty()) {
    Edge e = edge.top();
    edge.pop();

    int start, end, cost;
    tie(cost, start, end) = e;

    if (find(start) != find(end)) {
      uni(start, end);
      ans += cost;
    }
  }

  printf("%d\n", ans);

  return 0;
}