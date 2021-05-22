#include <bits/stdc++.h>

using namespace std;

const int MAX = 1'000'000 + 50;
int N, M, cnt;
int parent[MAX], rgt[MAX];

void init() {
  for (int i = 1; i <= N; i++) {
    parent[i] = i;
    rgt[i] = i + 1;
  }
}

int find(int node) {
  return (node == parent[node]) ? node : (parent[node] = find(parent[node]));
}

void uni(int a, int b) {
  // for (int i = a; i <= b; i++) {  // 이렇게 하면 시간초과!
  //   if (find(a) != find(i)) {
  //     parent[find(i)] = find(a);
  //     cnt--;
  //   }
  // }
  parent[find(a)] = find(b);
}

int main() {
  scanf("%d %d", &N, &M);
  cnt = N;

  init();
  rgt[N] = -1;

  for (int i = 0; i < M; i++) {
    int x, y;  // x<y;
    scanf("%d %d", &x, &y);
    while (find(x) != find(y)) {  // 이미 부순 벽은 다시 부수지 말자.
      cnt--;
      rgt[x] = rgt[find(x)];
      uni(x, y);
      x = rgt[x];
    }
  }

  printf("%d\n", cnt);

  return 0;
}