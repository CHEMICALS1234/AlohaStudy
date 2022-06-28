#include <bits/stdc++.h>

#include <cmath>

#define FAST                         \
  ios_base ::sync_with_stdio(false); \
  cin.tie(NULL);                     \
  cout.tie(NULL);

#define endl "\n"
#define INF 987654321

using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<long long>;

double V;
int N;

double calcVolume(double a, double b, double h) {
  double dx = 0.0000005;
  double x = 0;
  double ans = 0;

  while (x < h) {
    ans += (M_PI * pow((a * pow(M_E, -(x * x)) + b * sqrt(x)), 2)) * dx;
    x += dx;
  }

  return ans;
}

int main() {
  FAST;

  cin >> V >> N;

  double minus = INF;
  int index = 0;

  for (int i = 0; i < N; i++) {
    double a, b, h;
    cin >> a >> b >> h;

    double res = calcVolume(a, b, h);

    // cout.precision(10);
    // cout << res << endl;

    if (abs(V - res) > minus)
      continue;

    index = i;
    minus = abs(V - res);
  }

  cout << index << endl;

  return 0;
}
