#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using node_t = int;
using dist_t = ll;
using vi = vector<int>;
using vll = vector<ll>;

#define all(x) (x).begin(), (x).end()

#define endl "\n"
#define INF 2e18
#define MOD 1'000'000'007
#define MAXSIZE 32005

int N, M;
int cnt[MAXSIZE] = {};
vector<node_t> graph[MAXSIZE];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    node_t a, b;
    cin >> a >> b;

    cnt[b]++;
    graph[a].push_back(b);
  }

  queue<node_t> q;
  for (node_t i = 1; i <= N; i++) {
    if (cnt[i] == 0)
      q.push(i);
  }

  while (!q.empty()) {
    node_t currNode = q.front();
    q.pop();

    cout << currNode << " ";

    for (node_t nextNode : graph[currNode]) {
      cnt[nextNode]--;

      if (cnt[nextNode] == 0)
        q.push(nextNode);
    }
  }

  cout << endl;

  return 0;
}