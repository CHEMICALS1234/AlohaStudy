#include <bits/stdc++.h>

using namespace std;

const int N_MAX = 50'000 + 50;
int N, M;
int parent[N_MAX], in[N_MAX];

vector<int> graph[N_MAX];
vector<int> temp_vec;
queue<pair<int, int>> q;
queue<int> tq;

int find(int node) {
  return (node == parent[node]) ? node : (parent[node] = find(parent[node]));
}

void uni(int a, int b) { parent[find(a)] = find(b); }

void init() {
  for (int i = 0; i < N_MAX; i++) {
    parent[i] = i;
    in[i] = 0;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  scanf("%d %d", &N, &M);

  init();

  int node_size = N;

  for (int i = 0; i < M; i++) {
    int k, l;
    char temp;
    cin >> k >> temp >> l;

    if (temp == '=') {
      if (find(k) != find(l)) {
        uni(k, l);
        node_size--;
      }
    } else {
      q.push(make_pair(k, l));
    }
  }

  bool flag = true;

  while (!q.empty()) {
    int k, l;
    tie(k, l) = q.front();
    int fk = find(k), fl = find(l);

    if (fk == fl) {
      flag = false;
      break;
    }

    graph[fk].push_back(fl);
    in[fl]++;

    q.pop();
  }

  for (int i = 0; i < N; i++) {
    if (i != find(i)) continue;
    if (in[i] == 0) tq.push(i);
  }

  while (!tq.empty()) {
    int temp = tq.front();
    temp_vec.push_back(temp);
    tq.pop();

    for (int i = 0; i < graph[temp].size(); i++) {
      if (--in[graph[temp][i]] == 0) tq.push(graph[temp][i]);
    }
  }

  if (temp_vec.size() != node_size) flag = false;  // cycle exsits

  if (flag) {
    printf("consistent\n");
  } else {
    printf("inconsistent\n");
  }

  return 0;
}
