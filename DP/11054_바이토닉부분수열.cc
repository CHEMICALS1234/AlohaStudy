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

#define MAXSIZE (1000 + 10)

int LIS[MAXSIZE], LDS[MAXSIZE], arr[MAXSIZE];
int N;

int makeTable() {
  int m = 0;
  for (int i = 0; i < N; i++) {
    LIS[i] = 1;
    for (int j = 0; j < i; j++) {
      if (arr[j] < arr[i]) {
        LIS[i] = max(LIS[i], LIS[j] + 1);
      }
    }
  }

  for (int i = N - 1; i >= 0; i--) {
    LDS[i] = 1;
    for (int j = N - 1; j > i; j--) {
      if (arr[j] < arr[i]) {
        LDS[i] = max(LDS[i], LDS[j] + 1);
      }
    }
  }

  for (int i = 0; i < N; i++) {
    m = max(m, LIS[i] + LDS[i] - 1);
  }

  return m;
}

int main() {
  FAST;

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  cout << makeTable() << endl;

  return 0;
}