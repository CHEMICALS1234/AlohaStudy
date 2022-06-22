#include <algorithm>
#include <iostream>
#include <stack>

#define FAST                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);

using namespace std;
using ll = long long;

const ll N_MAX = 100'000 + 10;

struct Point {
  ll x, y;

  Point() {}
  Point(ll x, ll y) : x(x), y(y) {}
};

Point pArray[N_MAX];

bool compX(const Point& p1, const Point& p2) {
  return (p1.x == p2.x) ? (p1.y < p2.y) : (p1.x < p2.x);
}

ll ccw(const Point& p1, const Point& p2, const Point& p3) {
  return p1.x * p2.y + p2.x * p3.y + p3.x * p1.y -
         (p1.y * p2.x + p2.y * p3.x + p3.y * p1.x);
  // if (op > 0)
  //   return 1;
  // else if (op == 0)
  //   return 0;
  // else
  //   return -1;
}

bool compCCW(const Point& p1, const Point& p2) {
  ll cc = ccw(pArray[0], p1, p2);

  if (cc != 0)
    return cc > 0;
  else
    return (p1.x + p1.y < p2.x + p2.y);
}

int main() {
  FAST;

  ll n;
  cin >> n;

  for (ll i = 0; i < n; i++) {
    cin >> pArray[i].x >> pArray[i].y;
  }
  sort(pArray, pArray + n, compX);
  sort(pArray + 1, pArray + n, compCCW);

  stack<Point> pStack;
  pStack.push(pArray[0]);
  pStack.push(pArray[1]);

  for (ll i = 2; i < n; i++) {
    while (pStack.size() >= 2) {
      Point first, second;
      second = pStack.top();
      pStack.pop();
      first = pStack.top();

      // 볼록 다각형 (<= 180도) 이므로, 좌회전만 고려하면 된다.
      if (ccw(first, second, pArray[i]) > 0) {
        pStack.push(second);  // 다시 넣어주고
        break;                // i 넣으러 탈출
      }
    }
    // 만일, 좌회전이 아니면 second가 빠지고 새로운 i가 들어선다.
    pStack.push(pArray[i]);
  }

  cout << pStack.size() << "\n";

  return 0;
}