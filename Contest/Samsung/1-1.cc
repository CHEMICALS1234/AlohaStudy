#include <bits/stdc++.h>

#include <cstdio>

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

int parent[MAXN * MAXN];

int arr[MAXN][MAXN];

void printArr(bool arr[][MAXN]) {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}

bool isValid(int y, int x, int l) {
  return (0 < x && x <= N && 0 < y && y <= N && arr[y][x] > l);
}

int find(int node) {
  if (node == parent[node])
    return node;

  return parent[node] = find(parent[node]);
}

// a에 b를 편입. 즉, b의 부모를 a의 부모와 같게 설정.
void uni(int a, int b) { parent[find(b)] = find(a); }

int solve() {
  cin >> N;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> arr[i][j];
    }
  }
  int ans = 0;
  for (int l = 1; l <= 100; l++) {
    for (int i = 1; i <= N * N; i++) {
      parent[i] = i;
    }

    set<int> s;

    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        if (arr[i][j] <= l)
          continue;

        for (int k = 0; k < 4; k++) {
          int nextI = i + dy[k];
          int nextJ = j + dx[k];
          if (isValid(nextI, nextJ, l)) {
            int currVal = (i - 1) * N + j;
            int nextVal = (nextI - 1) * N + nextJ;
            if (find(currVal) == find(nextVal))
              continue;

            if (currVal < nextVal) {
              uni(currVal, nextVal);
            }
            else {
              uni(nextVal, currVal);
            }
          }
        }
      }
    }

    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        if (arr[i][j] <= l)
          continue;

        s.insert(parent[(i - 1) * N + j]);
      }
    }

    ans = max(ans, (int)s.size());
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("./input.txt", "r", stdin);
  // freopen("./output.txt", "w", stdout);

  cin >> T;
  for (int i = 1; i <= T; i++) {
    cout << "#" << i << " " << solve() << endl;
  }

  return 0;
}