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

#define MAXSIZE 30 + 5

int arr[MAXSIZE][MAXSIZE] = {};
// bool visited[MAXSIZE][MAXSIZE] = {false};
int n, m;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void printArr() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}

void find(int i, int j) {
  if (i <= 0 || i > n || j <= 0 || j > m) {
    return;
  }
  if (arr[i][j] == 0) {
    return;
  }

  arr[i][j] = 0;

  for (int k = 0; k < 4; k++) {
    find(i + dx[k], j + dy[k]);
  }

  return;
}

int main() {
  FAST;

  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> arr[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int a;
      int& b = arr[i][j];
      cin >> a;

      b = (a == b) ? 0 : 1;
    }
  }

  int i = 1, j = 1;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      if (arr[i][j] == 1) {
        goto nextPoint;
      }
    }
  }

nextPoint:
  if (i == (n + 1) && j == (m + 1)) {
    cout << "YES" << endl;
  }

  find(i, j);

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (arr[i][j] == 1) {
        cout << "NO" << endl;
        return 0;
      }
    }
  }

  cout << "YES" << endl;

  return 0;
}