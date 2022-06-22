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

#define MAXSIZE 500 + 5

int dp[MAXSIZE][MAXSIZE] = {};
vector<pair<int, int>> matrix;

int makeTable(int start, int end) {
  if (start == end) {
    return 0;
  }
  if (end == start + 1) {
    return dp[start][end] = (matrix[start].first * matrix[start].second *
                             matrix[end].second);
  }
  if (dp[start][end]) {
    return dp[start][end];
  }

  int res = 0;
  for (int i = start; i < end; i++) {
    res = makeTable(start, i) + makeTable(i + 1, end) +
          (matrix[start].first * matrix[i].second * matrix[end].second);

    if (!dp[start][end] || res < dp[start][end])
      dp[start][end] = res;
  }

  return dp[start][end];
}

int main() {
  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    int r, c;
    cin >> r >> c;

    matrix.push_back({r, c});
  }

  cout << makeTable(0, N - 1) << endl;

  return 0;
}