#include <bits/stdc++.h>

using namespace std;

const int N_MAX = 50'000 + 50;
int N, M;
int parent[N_MAX], winner[N_MAX];
// int temp_k[N_MAX], temp_l[N_MAX];

queue<pair<int, int>> q;

int find(int node) {
  return (node == parent[node]) ? node : (parent[node] = find(parent[node]));
}

void uni(int a, int b) { parent[find(a)] = find(b); }

void init() {
  for (int i = 0; i < N_MAX; i++) {
    parent[i] = i;
    winner[i] = -1;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  scanf("%d %d", &N, &M);

  init();

  for (int i = 0; i < M; i++) {
    int k, l;
    char temp;
    cin >> k >> temp >> l;

    if (temp == '=') {
      uni(k, l);
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

    if (fk == winner[fl]) {
      flag = false;
      break;
    }

    winner[fk] = fl;
    q.pop();
  }

  if (flag) {
    printf("consistent\n");
  } else {
    printf("inconsistent\n");
  }

  return 0;
}
