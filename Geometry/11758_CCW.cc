#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct Point {
  ll x, y;

  Point() : x(0), y(0) {}
};

ll ccw(const Point& p1, const Point& p2, const Point& p3) {
  ll op = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y -
          (p2.x * p1.y + p3.x * p2.y + p1.x * p3.y);

  if (op > 0)
    return 1;
  else if (op < 0)
    return -1;
  else
    return 0;
}

int main() {
  Point p1, p2, p3;
  scanf("%lld %lld", &p1.x, &p1.y);
  scanf("%lld %lld", &p2.x, &p2.y);
  scanf("%lld %lld", &p3.x, &p3.y);

  printf("%lld\n", ccw(p1, p2, p3));
}