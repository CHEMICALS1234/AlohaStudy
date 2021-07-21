#include <iostream>
#include <algorithm>

using namespace std;

using Point = pair<int, int>;

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

int main() {
  Point p[4];
  for (int i = 0; i < 4; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    p[i] = make_pair(x, y);
  }

  if (ccw(p[0], p[2], p[1]) * ccw(p[0], p[3], p[1]) < 0)
    printf("1\n");
  else
    printf("0\n");
  return 0;
}