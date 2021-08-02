#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

struct Point {
  ll x, y;
  Point(ll x, ll y) : x(x), y(y) {}

  void print() const { cout << x << " " << y << "\n"; }
};

vector<Point> convexHull;

bool compX(const Point& p1, const Point& p2) {
  return (p1.x == p2.x) ? (p1.y < p2.y) : (p1.x < p2.x);
}

int ccw(const Point& p1, const Point& p2, const Point& p3) {
  ll op = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y -
          (p1.y * p2.x + p2.y * p3.x + p3.y * p1.x);
  if (op > 0)
    return 1;
  else if (op == 0)
    return 0;
  else
    return -1;
}

bool compCCW(const Point& p1, const Point& p2) {
  return ccw(convexHull[0], p1, p2) > 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  while (n--) {
    ll x, y;
    char c;
    cin >> x >> y >> c;
    if (c == 'Y') convexHull.push_back(Point(x, y));
  }
  sort(convexHull.begin(), convexHull.end(), compX);
  sort(convexHull.begin(), convexHull.end(), compCCW);

  int idx = 0;
  for (int i = convexHull.size() - 1; i > 0; i--) {
    if (ccw(convexHull[0], convexHull[i], convexHull[i - 1]) != 0) {
      idx = i;
      break;
    }
  }

  reverse(convexHull.begin() + idx, convexHull.end());

  cout << convexHull.size() << "\n";
  for (const auto& p : convexHull) {
    p.print();
  }

  return 0;
}