#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

const int ROOT = 1;
const int MAX = 500 + 50;
const int BUS_MAX = 6000 + 60;
const int INF = 987654321;

// typedef struct {
//   int A, B, C;
// } Edge;
typedef tuple<int, int, int> Edge;

int N, M;
long long dist[MAX];
Edge edges[BUS_MAX];

void init(void) {
  for (int i = 0; i < MAX; i++) {
    dist[i] = INF;
  }
}

// BellmanFord
void printDistance(void) {
  bool cycle = false;
  dist[ROOT] = 0;

  for (int n = 1; n <= N; n++) {
    for (Edge e : edges) {
      int a, b, c;
      tie(a, b, c) = e;

      if (dist[a] == INF) {
        continue;
      }

      if (dist[b] <= dist[a] + c) {
        continue;
      }

      dist[b] = dist[a] + c;

      if (n == N) {
        cycle = true;
      }
    }
  }

  if (cycle) {
    cout << -1 << "\n";

    return;
  }

  for (int n = 2; n <= N; n++) {
    if (dist[n] == INF) {
      cout << -1 << "\n";

      continue;
    }

    cout << dist[n] << "\n";
  }
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;

  for (int m = 0; m < M; m++) {
    int a, b, c;
    cin >> a >> b >> c;
    edges[m] = make_tuple(a, b, c);
  }

  init();

  printDistance();

  return 0;
}