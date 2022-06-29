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

using node_t = int;
using dist_t = int;
using edge_t = pair<node_t, dist_t>;
using graphNode_t = vector<edge_t>;

#define MAXSIZE 100'000
#define INF 987654321

int N, K;
bool visited[MAXSIZE];
int cnt;

dist_t bfs(int start) {
  bool isFirst = false;
  dist_t dist = 0;
  queue<node_t> q;
  visited[start] = true;
  q.push(start);

  while (!q.empty()) {
    node_t currNode, nextNode;
    currNode = q.front();
    q.pop();

    if (currNode == K) {
      isFirst = true;
      cnt++;
    }

    nextNode = currNode * 2;
    if (nextNode <= MAXSIZE && !visited[nextNode]) {
      visited[nextNode] = true;
      q.push(nextNode);
    }

    nextNode = currNode + 1;
    if (nextNode <= MAXSIZE && !visited[nextNode]) {
      visited[nextNode] = true;
      q.push(nextNode);
    }

    nextNode = currNode - 1;
    if (nextNode >= 0 && !visited[nextNode]) {
      visited[nextNode] = true;
      q.push(nextNode);
    }

    if (!isFirst)
      dist++;
  }

  return dist;
}

int main() {
  FAST;

  cin >> N >> K;

  cout << bfs(N) << endl;
  cout << cnt << endl;

  return 0;
}