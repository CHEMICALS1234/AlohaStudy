#include <bits/stdc++.h>

#include <cmath>

using namespace std;

using ll = long long;
using node_t = ll;
using dist_t = ll;
using vi = vector<int>;
using vll = vector<ll>;

#define all(x) (x).begin(), (x).end()

#define endl "\n"
#define INF 2e18
#define MOD 1'000'000'007
#define MAX_N 10'005

int N;
vll xs(MAX_N);
vll ys(MAX_N);

double getArea() {
  double sum = 0;
  for (int i = 0; i < N; i++) {
    sum += xs[i] * ys[(i + 1) % N] - xs[(i + 1) % N] * ys[i];
  }
  sum /= 2;

  return abs(sum);
}

// val을 소숫점 아래 rad 까지 반올림.
double rnd(double val, int rad) {
  ll tens = pow(10, rad);
  return round(val * tens) / tens;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> xs[i] >> ys[i];
  }

  cout << fixed;
  cout.precision(1);
  cout << rnd(getArea(), 1) << endl;

  return 0;
}