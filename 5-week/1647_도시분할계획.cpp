#include <bits/stdc++.h>

using namespace std;

const int N_MAX = 100'000 + 50;
int N, M;
int parent[N_MAX];

typedef tuple<int, int, int> Edge;
priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

int find(int node) {
  return (node == parent[node]) ? node : (parent[node] = find(parent[node]));
}

void uni(int a, int b) { parent[find(a)] = find(b); }

void init() {
  for (int i = 0; i < N_MAX; i++) parent[i] = i;
}

int main() {
  scanf("%d %d", &N, &M);

  init();

  for (int i = 0; i < M; i++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    pq.push(make_tuple(c, a, b));
  }

  int ans = 0, max_cost = 0;
  while (!pq.empty()) {
    int a, b, c;
    tie(c, a, b) = pq.top();
    pq.pop();

    if (find(a) != find(b)) {
      uni(a, b);
      ans += c;
      max_cost = max(c, max_cost);
    }
  }

  ans -= max_cost;

  printf("%d\n", ans);
  return 0;
}
