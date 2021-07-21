#include <iostream>
#include <algorithm>

using namespace std;

using Point = pair<int, int>;
using Line = pair<Point, Point>;

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