#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using node_t = ll;
using dist_t = ll;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;

#define all(x) (x).begin(), (x).end()

#define endl "\n"
#define INF 987654321
#define MOD 1'000'000'007

#define MAXN 105

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

int T;
int N;

void printArr(bool arr[][MAXN]) {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}

void bfs(int Y, int X, int arr[][MAXN], bool visited[][MAXN], int level) {
  if (!(0 < X && X <= N) || !(0 < Y && Y <= N))
    return;

  if (arr[Y][X] <= level)
    return;

  queue<pair<int, int>> q;
  visited[Y][X] = true;
  q.push({Y, X});

  while (!q.empty()) {
    int currY, currX;
    tie(currY, currX) = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int nextY, nextX;
      nextY = currY + dy[i];
      nextX = currX + dx[i];

      if (nextX <= 0 || nextX > N || nextY <= 0 || nextY > N)
        continue;

      if (arr[nextY][nextX] <= level)
        continue;

      if (visited[nextY][nextX])
        continue;

      visited[nextY][nextX] = true;
      q.push({nextY, nextX});
    }
  }
}

int solve() {
  cin >> N;

  int arr[MAXN][MAXN];
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> arr[i][j];
    }
  }
  int ans = 0;
  for (int l = 0; l <= 100; l++) {
    int num = 0;
    bool visited[MAXN][MAXN] = {
        false,
    };
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        if (arr[i][j] <= l)
          continue;

        if (visited[i][j])
          continue;

        bfs(i, j, arr, visited, l);
        num++;
      }
    }
    ans = max(ans, num);
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./input.txt", "r", stdin);

  cin >> T;
  for (int i = 1; i <= T; i++) {
    cout << "#" << i << " " << solve() << endl;
  }

  return 0;
}