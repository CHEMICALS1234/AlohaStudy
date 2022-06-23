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

struct Point {
  ll x, y;

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
};

ll ccw(const Point& p1, const Point& p2, const Point& p3) {
  ll res = (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y -
            (p2.x * p1.y + p3.x * p2.y + p1.x * p3.y));
  return (res == 0) ? 0 : (res > 0) ? 1 : -1;
}

int main() {
  FAST;

  Point a, b, c, d;

  cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;

  ll res1 = (ccw(a, b, c) * ccw(a, b, d));
  ll res2 = (ccw(c, d, a) * ccw(c, d, b));

  if (!res1 && !res2) {
    if (b < a)
      swap(a, b);
    if (d < c)
      swap(c, d);
    bool check = (a <= d) && (c <= b);

    cout << check << endl;
    return 0;
  }

  if ((res1 <= 0) && (res2 <= 0)) {
    cout << 1 << endl;
  }
  else {
    cout << 0 << endl;
  }

  return 0;
}