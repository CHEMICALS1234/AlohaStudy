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
graphNode_t graph[MAXSIZE + 5];
dist_t dist[MAXSIZE + 5];
bool visited[MAXSIZE];

dist_t bfs(node_t start) {
  priority_queue<edge_t, vector<edge_t>, greater<edge_t>> pq;
  pq.push({0, start});

  visited[start] = true;

  while (!pq.empty()) {
    dist_t distCurr, distNext;
    node_t nodeCurr, nodeNext;

    tie(distCurr, nodeCurr) = pq.top();
    pq.pop();

    if (nodeCurr == K) {
      return distCurr;
    }

    nodeNext = 2 * nodeCurr;
    distNext = distCurr;
    if (nodeNext <= MAXSIZE && !visited[nodeNext]) {
      visited[nodeNext] = true;
      pq.push({distNext, nodeNext});
    }

    nodeNext = 1 + nodeCurr;
    distNext = 1 + distCurr;
    if (nodeNext <= MAXSIZE && !visited[nodeNext]) {
      visited[nodeNext] = true;
      pq.push({distNext, nodeNext});
    }

    nodeNext = -1 + nodeCurr;
    distNext = 1 + distCurr;
    if (nodeNext >= 0 && !visited[nodeNext]) {
      visited[nodeNext] = true;
      pq.push({distNext, nodeNext});
    }
  }
}

int main() {
  FAST;

  cin >> N >> K;

  cout << bfs(N) << endl;

  return 0;
}