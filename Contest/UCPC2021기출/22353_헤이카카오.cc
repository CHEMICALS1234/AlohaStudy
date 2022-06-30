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
using vpi = vector<pair<int, int>>;

#define MAXSIZE 10000
int A, D, K;
double winPercent[MAXSIZE] = {};

void makeTable() {
  winPercent[1] = D;
  for (int i = 2; i < MAXSIZE; i++) {
    winPercent[i] = winPercent[i - 1] + winPercent[i - 1] * K / 100;

    if (winPercent[i] >= 100) {
      winPercent[i] = 100;
    }
  }
}

void printArr() {
  for (int i = 1; i < 10; i++) {
    cout << winPercent[i] << " ";
  }
  cout << endl;
}

int main() {
  FAST;

  cin >> A >> D >> K;

  makeTable();

  double ans = 0;
  double prevLost = 100;

  for (int i = 1; i < MAXSIZE; i++) {
    ans += (i * A * (winPercent[i] / 100) * (prevLost / 100));
    prevLost *= (100 - winPercent[i]) / 100;

    if (winPercent[i] == 100) {
      break;
    }
  }

  cout.precision(16);
  cout << ans << endl;
  return 0;
}