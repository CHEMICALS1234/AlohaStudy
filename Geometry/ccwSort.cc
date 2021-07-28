#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

struct Point {
  int x, y;

  Point() {}
  Point(int x, int y) : x(x), y(y) {}

  ll squareDistanceWith(const Point& p) {
    return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y);
  }

  void print() { cout << "(" << x << "," << y << ")\n"; }
};

Point pArray[4];

int ccw(const Point& p1, const Point& p2, const Point& p3) {
  int op = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y -
           (p1.y * p2.x + p2.y * p3.x + p3.y * p1.x);
  if (op > 0)
    return 1;
  else if (op == 0)
    return 0;
  else
    return -1;
}

bool comp(const Point& left, const Point& right) {
  return ccw(pArray[0], left, right) > 0;
}

int main() {
  pArray[0] = Point(0, 0);
  pArray[1] = Point(1, 1);
  pArray[2] = Point(1, 0);
  pArray[3] = Point(0, 1);

  sort(pArray, pArray + 3, comp);

  pArray[0].print();
  pArray[1].print();
  pArray[2].print();
  pArray[3].print();

  return 0;
}