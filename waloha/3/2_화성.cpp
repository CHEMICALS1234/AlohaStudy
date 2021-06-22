#include <bits/stdc++.h>

using namespace std;

const int V_MAX = 20'000 + 50;
const int E_MAX = 100'000 + 50;

int N, M, a, b;
int parent[V_MAX];

typedef tuple<int, int, int> Edge;
priority_queue<Edge, vector<Edge>, greater<Edge>> edge;
vector<tuple<int, int, int, int>> v;

int ans = 0;

void init() {
  for (int i = 0; i < V_MAX; i++) {
    parent[i] = i;
  }
}

int find(int node) {
  return (node == parent[node]) ? node : (parent[node] = find(parent[node]));
}

void uni(int a_, int b_) { parent[find(b_)] = find(a_); }

int main() {
  scanf("%d %d", &N, &M);

  init();

  for (int e = 0; e < M; e++) {
    int start, end, ci, vi;
    scanf("%d %d %d %d", &start, &end, &ci, &vi);
    v.push_back(make_tuple(start, end, ci, vi));
    // edge.push(make_tuple(cost, start, end));
  }

  scanf("%d %d", &a, &b);

  for (int e = 0; e < M; e++) {
    int p, q, ci, vi;
    tie(p, q, ci, vi) = v[e];
    int cost =
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