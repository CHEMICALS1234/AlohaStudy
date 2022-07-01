#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using node_t = ll;
using dist_t = ll;

#define endl "\n"
#define INF 2e18

int R, C;
vector<bool> visited(30, false);
vector<string> arr(25);

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int ans;

void printPnt(pair<int, int>& pnt) {
  cout << "( " << pnt.first << " , " << pnt.second << " )\n";
}

void dfs(pair<int, int> pnt, int dist) {
  ans = max(ans, dist);

  auto [y, x] = pnt;

  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (ny <= 0 || ny > R || nx <= 0 || nx > C)
      continue;

    if (!visited[arr[ny][nx] - 'A']) {
      visited[arr[ny][nx] - 'A'] = true;
      dfs({ny, nx}, dist + 1);
      visited[arr[ny][nx] - 'A'] = false;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> R >> C;

  for (int i = 1; i <= R; i++) {
    cin >> arr[i];
    arr[i].insert(0, 1, 0);
  }

  visited[arr[1][1] - 'A'] = true;
  dfs({1, 1}, 1);

  cout << ans << endl;

  return 0;
}