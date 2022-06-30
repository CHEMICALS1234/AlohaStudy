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

int before[MAXSIZE][MAXSIZE] = {};
int after[MAXSIZE][MAXSIZE] = {};
bool visited[MAXSIZE][MAXSIZE] = {
    false,
};

int N, M;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void printArr(int arr[MAXSIZE][MAXSIZE]) {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}

void find(int startY, int startX) {
  if (!(0 < startX && startX <= M) || !(0 < startY && startY <= N))
    return;

  queue<pair<int, int>> q;
  int& bs = before[startY][startX];
  int& as = after[startY][startX];

  visited[startY][startX] = true;
  q.push({startY, startX});

  while (!q.empty()) {
    int currX, currY, nextX, nextY;
    tie(currY, currX) = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      nextY = currY + dy[i];
      nextX = currX + dx[i];

      int& bn = before[nextY][nextX];

      if (0 < nextX && nextX <= M && 0 < nextY && nextY <= N) {
        if (!visited[nextY][nextX] && (bn == bs)) {
          bn = as;
          visited[nextY][nextX] = true;
          q.push({nextY, nextX});
        }
      }
    }
  }
}

int main() {
  FAST;

  cin >> N >> M;

  for (int n = 1; n <= N; n++) {
    for (int m = 1; m <= M; m++) {
      cin >> before[n][m];
    }
  }

  for (int n = 1; n <= N; n++) {
    for (int m = 1; m <= M; m++) {
      cin >> after[n][m];
    }
  }

  bool flag = true;
  for (int n = 1; n <= N; n++) {
    for (int m = 1; m <= M; m++) {
      if ((before[n][m] != after[n][m]) && flag) {
        find(n, m);
        before[n][m] = after[n][m];
        flag = false;
      }
    }
  }

  for (int n = 1; n <= N; n++) {
    for (int m = 1; m <= M; m++) {
      if (before[n][m] != after[n][m]) {
        cout << "NO" << endl;
        return 0;
      }
    }
  }

  cout << "YES" << endl;
  return 0;
}