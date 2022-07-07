#include <bits/stdc++.h>

#include <cmath>

using namespace std;

using ll = long long;
using node_t = ll;
using dist_t = ll;

#define endl "\n"
#define INF 2e18
#define MOD 1'000'000'007

struct vector2D {
  double x, y;
  const double PI = M_PI;
  explicit vector2D(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}

  vector2D& operator=(const vector2D& rhs) {
    x = rhs.x;
    y = rhs.y;
    return *this;
  }

  bool operator==(const vector2D& rhs) const {
    return x == rhs.x && y == rhs.y;
  }

  // x에 대해 오름차순 정렬하고, 같으면 y에 대해 오름차순으로 정렬.
  bool operator<(const vector2D& rhs) const {
    return ((x != rhs.x) ? x < rhs.x : y < rhs.y);
  }

  vector2D operator+(const vector2D& rhs) const {
    return vector2D(x + rhs.x, y + rhs.y);
  }

  vector2D operator-(const vector2D& rhs) const {
    return vector2D(x - rhs.x, y - rhs.y);
  }

  vector2D operator*(double rhs) const { return vector2D(x * rhs, y * rhs); }

  double norm() const { return hypot(x, y); }

  vector2D normalize() const {
    if (norm() == 0)
      return vector2D(0.0, 0.0);
    return vector2D(x / norm(), y / norm());
  }

  double polarangle() const {
    // x 축의 양의 방향으로부터 이 벡터까지 반시계 방향으로 잰 각도
    return fmod(atan2(y, x) + 2 * PI, 2 * PI);
  }

  double dotproduct(const vector2D& rhs) const { return x * rhs.x + y * rhs.y; }

  double crossproduct(const vector2D& rhs) const {
    return x * rhs.y - y * rhs.x;
  }

  vector2D projection(const vector2D& rhs) const {
    //이 벡터를 rhs 에 사영한 결과
    vector2D ret = rhs.normalize();
    return ret * ret.dotproduct(*this);
  }
};

// 원점을 기준으로 ccw
int ccw(const vector2D& a, const vector2D& b) {
  double res = a.crossproduct(b);
  if (res > 0) {
    return 1;
  }
  else if (res == 0) {
    return 0;
  }
  else {
    return -1;
  }
}

// 점 p를 기준으로 ccw
int ccw(const vector2D& p, const vector2D& a, const vector2D& b) {
  return ccw(a - p, b - p);
}

// ccw에 대해 정렬.
bool compCCW(const vector2D& a, const vector2D& b) {
  int res = ccw(a, b);

  // ccw 한 것이 0이 아니면, 반시계 방향으로 정렬.
  if (res) {
    return (res > 0);
  }
  // 만일 0면, x에 대해 오름차순.
  if (a.x != b.x) {
    return a.x < b.x;
  }
  // x좌표도 같다면 y에 대해 오름차순.
  return a.y < b.y;
}

int N;
vector<vector2D> pnts;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  for (int i = 0; i < N; i++) {
    int x, y;
    char c;

    cin >> x >> y >> c;

    if (c == 'Y')
      pnts.push_back(vector2D(x, y));
  }

  // 먼저 x, y에 대해 정렬한다.
  sort(pnts.begin(), pnts.end());

  for (int i = 1; i < pnts.size(); i++) {
    pnts[i] = pnts[i] - pnts[0];
  }

  // pnts[0]에 대하여 ccw 정렬.
  sort(pnts.begin() + 1, pnts.end(), compCCW);

  // 끝부터 탐색했을 때, 일직선 부분이 시작되는 곳.
  int idx = 0;
  for (int i = pnts.size() - 1; i >= 1; i--) {
    if (ccw(pnts[i], pnts[i - 1]) != 0) {
      idx = i;
      break;
    }
  }

  reverse(pnts.begin() + idx, pnts.end());

  cout << pnts.size() << endl;

  for (int i = 0; i < pnts.size(); i++) {
    if (i != 0) {
      pnts[i] = pnts[i] + pnts[0];
    }
    cout << pnts[i].x << " " << pnts[i].y << endl;
  }

  return 0;
}