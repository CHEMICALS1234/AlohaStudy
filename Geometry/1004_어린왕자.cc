#include <bits/stdc++.h>

using namespace std;

const int ARR_MAX = 50 + 5;

using Point = pair<int, int>;
using Circle = pair<Point, int>;
using Array = vector<pair<Point, int>>;

bool isIn(const Point& point, const Circle& circle) {
  int xCent{circle.first.first}, yCent{circle.first.second}, xPos{point.first},
      yPos{point.second}, r{circle.second};

  return ((xCent - xPos) * (xCent - xPos) + (yCent - yPos) * (yCent - yPos) <
          r * r);
}

int main() {
  int T;
  scanf("%d", &T);

  for (int i = 0; i < T; i++) {
    Array arr;
    Point start, end;
    int a, b, c, d;

    scanf("%d %d %d %d", &a, &b, &c, &d);
    start = make_pair(a, b);
    end = make_pair(c, d);

    int n;
    scanf("%d", &n);

    int ans = 0;

    for (int j = 0; j < n; j++) {
      int x, y, r;
      scanf("%d %d %d", &x, &y, &r);
      arr.push_back(make_pair(make_pair(x, y), r));

      if (isIn(start, arr[j]) != isIn(end, arr[j])) ans++;
    }
    printf("%d\n", ans);
  }
}