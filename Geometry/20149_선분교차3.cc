#include <bits/stdc++.h>

#define FAST                         \
  ios_base ::sync_with_stdio(false); \
  cin.tie(NULL);                     \
  cout.tie(NULL);

#define endl "\n"

using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<long long>;

template <typename T>
struct Point {
  T x, y;

  bool operator<(const Point& p) {
    if (x == p.x) {
      return (y < p.y);
    }
    else {
      return (x < p.x);
    }
  }

  bool operator<=(const Point& p) {
    if (x == p.x) {
      return (y <= p.y);
    }
    else {
      return (x <= p.x);
    }
  }

  bool operator==(const Point& p) { return (x == p.x) && (y == p.y); }

  void print() { cout << "( " << x << " , " << y << " )" << endl; }
};

template <typename T>
ll ccw(const Point<T>& p1, const Point<T>& p2, const Point<T>& p3) {
  T res = (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y -
           (p2.x * p1.y + p3.x * p2.y + p1.x * p3.y));
  return (res == 0) ? 0 : (res > 0) ? 1 : -1;
}

int main() {
  FAST;

  Point<ll> a, b, c, d;

  cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;

  ll abc = ccw(a, b, c);
  ll abd = ccw(a, b, d);
  ll cda = ccw(c, d, a);
  ll cdb = ccw(c, d, b);

  ll res1 = (ccw(a, b, c) * ccw(a, b, d));
  ll res2 = (ccw(c, d, a) * ccw(c, d, b));

  bool check;

  if (!res1 && !res2) {
    if (b < a)
      swap(a, b);
    if (d < c)
      swap(c, d);
    check = (a <= d) && (c <= b);
  }
  else if ((res1 <= 0) && (res2 <= 0)) {
    check = 1;
  }
  else {
    check = 0;
  }

  cout << check << endl;

  if (check) {
    Point<double> sol;

    if (!abc && !abd && !cda && !cdb) {
      // 한 직선 위에 있고, 교차한다면 (현재는 a<b, c<d 인 상황)

      if (b == c) {
        sol.x = b.x;
        sol.y = b.y;
      }
      else if (a == d) {
        sol.x = a.x;
        sol.y = a.y;
      }
      else {
        return 0;
      }
    }
    else {
      double m1 = ((double)b.y - a.y) / (b.x - a.x);
      double m2 = ((double)d.y - c.y) / (d.x - c.x);
      // 만약 기울기가 무한이라면?
      if (a.x == b.x) {
        sol.x = a.x;
        sol.y = m2 * (a.x - c.x) + c.y;
      }
      else if (c.x == d.x) {
        sol.x = c.x;
        sol.y = m1 * (c.x - a.x) + a.y;
      }
      else {
        sol.x = (c.y - a.y + m1 * a.x - m2 * c.x) / (m1 - m2);
        sol.y = m1 * (sol.x - a.x) + a.y;
      }
    }

    cout.precision(16);
    cout << fixed << sol.x << " " << sol.y << endl;
  }

  return 0;
}