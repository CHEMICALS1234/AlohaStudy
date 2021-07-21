#include <iostream>
#include <algorithm>

using namespace std;
using Point = pair<int, int>;
using Line = pair<Point, Point>;

const int N_MAX = 3'000 + 50;

int parent[N_MAX];
Line lines[N_MAX];

int ccw(Point a, Point b, Point c) {
  int op = a.first * b.second + b.first * c.second + c.first * a.second -
           (a.second * b.first + b.second * c.first + c.second * a.first);

  if (op > 0)
    return 1;
  else if (op == 0)
    return 0;
  else
    return -1;
}

bool isIntersect(Line x, Line y) {
  auto a = x.first;
  auto b = x.second;
  auto c = y.first;
  auto d = y.second;

  int ab = ccw(a, b, c) * ccw(a, b, d);
  int cd = ccw(c, d, a) * ccw(c, d, b);

  if (ab == 0 && cd == 0) {
    if (a > b) swap(a, b);
    if (c > d) swap(c, d);

    return c <= b && a <= d;
  }

  return ab <= 0 && cd <= 0;
}

void init() {
  for (int i = 0; i < N_MAX; i++) {
    parent[i] = -1;
  }
}

int find(int node) {
  return (parent[node] < 0) ? node : (parent[node] = find(parent[node]));
}

void uni(int a, int b) {
  int pa = find(a), pb = find(b);

  if (pa == pb) return;

  if (parent[pa] <= parent[pb]) {
    parent[pa] += parent[pb];
    parent[pb] = pa;
  } else {
    parent[pb] += parent[pa];
    parent[pa] = pb;
  }
}

int main() {
  int n;
  scanf("%d", &n);
  int cnt = n;

  init();

  for (int i = 1; i <= n; i++) {
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    lines[i] = make_pair(make_pair(x1, y1), make_pair(x2, y2));
  }

  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (isIntersect(lines[i], lines[j])) {
        if (find(i) != find(j)) {
          cnt--;
          uni(i, j);
        }
      }
    }
  }

  printf("%d\n", cnt);
  printf("%d\n", -(*min_element(parent + 1, parent + n + 1)));
}