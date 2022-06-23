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

int N;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
  FAST;
  cin >> N;

  for (int i = 0; i < N; i++) {
    int c;
    cin >> c;

    pq.push(c);
  }

  int cnt = 0;
  while (!pq.empty()) {
    int n1, n2;
    n1 = pq.top();
    pq.pop();

    if (pq.empty()) {
      break;
    }

    n2 = pq.top();
    pq.pop();

    cnt += (n1 + n2);

    if (pq.empty()) {
      break;
    }

    pq.push(n1 + n2);
  }

  cout << cnt << endl;

  return 0;
}