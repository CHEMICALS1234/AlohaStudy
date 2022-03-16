#include <bits/stdc++.h>

using namespace std;

const int N_MAX = 1'000 + 50;
int N, M;
int parent[N_MAX], sex[N_MAX];

typedef tuple<int, int, int> Edge;
priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

void init() {
  for (int i = 0; i < N_MAX; i++) {
    parent[i] = i;
    sex[i] = -1;
  }
}

int find(int node) {
  return (node == parent[node]) ? node : (parent[node] = find(parent[node]));
}

void uni(int a, int b) { parent[find(a)] = find(b); }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  scanf("%d %d", &N, &M);

  init();

  for (int i = 1; i <= N; i++) {
    char temp;
    cin >> temp;
    switch (temp) {
      case 'M':
        sex[i] = 0;
        break;

      default:
        sex[i] = 1;
        break;
    }
  }

  for (int i = 0; i < M; i++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    if (sex[a] == sex[b])
      continue;  // 최종 결과에 같은 성별끼리 연결된 간선은 포함되지 않는다.

    pq.push(make_tuple(c, a, b));
  }

  int cnt = N, net_cost = 0;

  while (!pq.empty()) {
    int a, b, c;
    tie(c, a, b) = pq.top();
    pq.pop();

    if (find(a) != find(b)) {
      uni(a, b);
      net_cost += c;
      cnt--;
    }
  }

  if (cnt != 1) {
    printf("-1\n");
  } else {
    printf("%d\n", net_cost);
  }

  return 0;
}