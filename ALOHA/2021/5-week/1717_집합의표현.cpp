#include <iostream>

using namespace std;

const int N_MAX = 1'000'000 + 50;

int n, m;
int parents[N_MAX];

void init() {
  for (int i = 0; i <= n; i++) {
    parents[i] = i;
  }
}

int find(int node) {
  if (node == parents[node]) {
    return node;
  }
  return parents[node] = find(parents[node]);
}

void uni(int a, int b) {
  int root_a = find(a);
  int root_b = find(b);

  parents[root_b] = root_a;
}

int main() {
  scanf("%d %d", &n, &m);

  init();

  for (int i = 0; i < m; i++) {
    int act, a, b;
    scanf("%d %d %d", &act, &a, &b);

    if (act) {
      if (find(a) == find(b)) {
        printf("YES\n");
      } else {
        printf("NO\n");
      }
    } else {
      uni(a, b);
    }
  }

  return 0;
}