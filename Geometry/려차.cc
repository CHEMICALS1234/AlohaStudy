#include <bits/stdc++.h>
using namespace std;

struct geovector {
  double x, y;
  const double PI = 2.0 * acos(0.0);
  explicit geovector(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}

  geovector& operator=(const geovector& rhs) {
    x = rhs.x;
    y = rhs.y;
    return *this;
  }

  bool operator==(const geovector& rhs) const {
    return x == rhs.x && y == rhs.y;
  }

  bool operator<(const geovector& rhs) const {
    if (y * rhs.x != x * rhs.y)
      return y * rhs.x < x * rhs.y;
    if (x != rhs.x)
      return x < rhs.x;
    return y < rhs.y;
  }

  geovector operator+(const geovector& rhs) {
    return geovector(x + rhs.x, y + rhs.y);
  }

  geovector operator-(const geovector& rhs) {
    return geovector(x - rhs.x, y - rhs.y);
  }

  geovector operator*(double rhs) const { return geovector(x * rhs, y * rhs); }

  double norm() const { return hypot(x, y); }

  geovector normalize() const {
    if (norm() == 0)
      return geovector(0.0, 0.0);
    return geovector(x / norm(), y / norm());
  }

  double polarangle() const {
    // x 축의 양의 방향으로부터 이 벡터까지 반시계 방향으로 잰 각도
    return fmod(atan2(y, x) + 2 * PI, 2 * PI);
  }

  double dotproduct(const geovector& rhs) const {
    return x * rhs.x + y * rhs.y;
  }

  double crossproduct(const geovector& rhs) const {
    return x * rhs.y - y * rhs.x;
  }

  geovector projection(const geovector& rhs) const {
    //이 벡터를 rhs 에 사영한 결과
    geovector ret = rhs.normalize();
    return ret * ret.dotproduct(*this);
  }
};

//원점에서 벡터 b 가 벡터 a 의 반시계 방향이면 양수, 시계 방향 음수, 평행이면 0
double ccw(geovector a, geovector b) { return a.crossproduct(b); }

double normalccw(geovector a, geovector b) {
  geovector x, y;
  x = a.normalize(), y = b.normalize();
  return ccw(x, y);
}

double ccw(geovector p, geovector a, geovector b) { return ccw(a - p, b - p); }

bool comp(geovector& a, geovector& b) {
  return ((a.x != b.x) ? a.x < b.x : a.y < b.y);
}

int N;
vector<geovector> input;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;

  for (int i = 0; i < N; ++i) {
    int s, e;
    char F;

    cin >> s >> e >> F;
    if (F == 'Y')
      input.push_back(geovector(s, e));
  }

  sort(input.begin(), input.end(), comp);

  for (int i = 1; i < input.size(); ++i) {
    input[i] = input[i] - input[0];
  }

  sort(input.begin() + 1, input.end());

  int idx = 0;
  for (int i = input.size() - 1; i > 0; --i) {
    if (ccw(input[i], input[i - 1]) != 0) {
      idx = i;
      break;
    }
  }

  reverse(input.begin() + idx, input.end());

  cout << input.size() << endl;

  for (int i = 0; i < input.size(); ++i) {
    if (i > 0)
      input[i] = input[i] + input[0];
    cout << input[i].x << " " << input[i].y << endl;
  }

  return 0;
}