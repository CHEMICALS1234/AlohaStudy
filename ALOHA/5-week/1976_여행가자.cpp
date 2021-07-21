#include <iostream>
#include <algorithm>

using namespace std;

const int N_MAX = 200 + 50;
const int M_MAX = 1000 + 50;

int N, M;
int parent[N_MAX];

void init() {
  for (int i = 1; i <= N; i++) {
    parent[i] = i;
  }
}

int find(int node) {
  if (node == parent[node]) {
    return node;
  }
  return parent[node] = find(parent[node]);
}

void uni(int a, int b) {
  int root_a = find(a);
  int root_b = find(b);

  parent[root_b] = root_a;
}

int main() {
  scanf("%d %d", &N, &M);

  init();

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      int temp;
      scanf("%d", &temp);
      if (temp) {
        if (find(i) != find(j)) {
          uni(i, j);
        }
      }
    }
  }

  bool flag = true;
  int path_root[M_MAX];

  for (int i = 0; i < M; i++) {
    int temp;
    scanf("%d", &temp);
    path_root[i] = find(temp);

    if (i == 0) continue;

    if (path_root[i] != path_root[i - 1]) flag = false;
  }

  if (flag)
    printf("YES\n");
  else
    printf("NO\n");

  return 0;
}