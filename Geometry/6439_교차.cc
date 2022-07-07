#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using node_t = ll;
using dist_t = ll;

#define endl "\n"
#define INF 2e18
#define MOD 1'000'000'007

struct Point {
  ll x, y;

  Point(ll x = 0, ll y = 0) : x(x), y(y) {}
  Point(const Point& p) {
    x = p.x;
    y = p.y;
  }

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

struct Line {
  Point start, end;

  Line(Point _start, Point _end) : start(_start), end(_end) {}
};

ll ccw(const Point& p1, const Point& p2, const Point& p3) {
  ll res = (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y -
            (p2.x * p1.y + p3.x * p2.y + p1.x * p3.y));
  return (res == 0) ? 0 : (res > 0) ? 1 : -1;
}

int T;

bool isCross(Line& l1, Line& l2) {
  ll res1 = ccw(l1.start, l1.end, l2.start) * ccw(l1.start, l1.end, l2.end);
  ll res2 = ccw(l2.start, l2.end, l1.start) * ccw(l2.start, l2.end, l1.end);

  if (!res1 && !res2) {
    if (l1.end < l1.start) {
      swap(l1.start, l1.end);
    }
    if (l2.end < l2.start) {
      swap(l2.start, l2.end);
    }

    return (l1.start <= l2.end) && (l2.start <= l1.end);
  }

  if ((res1 <= 0) && (res2 <= 0)) {
    return true;
  }

  return false;
}

bool inRectangle(const Point& s, const Point& r1, const Point& r3) {
  return (min(r1.x, r3.x) <= s.x && s.x <= max(r1.x, r3.x) &&
          min(r1.y, r3.y) <= s.y && s.y <= max(r1.y, r3.y));
}

void solve() {
  Point s1, s2, r1, r3;
  cin >> s1.x >> s1.y >> s2.x >> s2.y >> r1.x >> r1.y >> r3.x >> r3.y;

  if (inRectangle(s1, r1, r3) && inRectangle(s2, r1, r3)) {
    cout << "T" << endl;
    return;
  }

  Point r2(r1.x, r3.y), r4(r3.x, r1.y);
  Line lmain(s1, s2);
  Line lr1(r1, r2), lr2(r2, r3), lr3(r3, r4), lr4(r4, r1);

  if (isCross(lmain, lr1) || isCross(lmain, lr2) || isCross(lmain, lr3) ||
      isCross(lmain, lr4)) {
    cout << "T" << endl;
    return;
  }

  cout << "F" << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  while (T--) {
    solve();
  }

  return 0;
}