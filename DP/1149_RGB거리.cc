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

#define MAXSIZE 1005

vi costR(MAXSIZE), costG(MAXSIZE), costB(MAXSIZE);
int N;

int main() {
  FAST;

  cin >> N;

  for (int i = 1; i <= N; i++) {
    int r, g, b;
    cin >> r >> g >> b;

    costR[i] = min(costG[i - 1], costB[i - 1]) + r;
    costG[i] = min(costR[i - 1], costB[i - 1]) + g;
    costB[i] = min(costG[i - 1], costR[i - 1]) + b;
  }

  cout << min(costR[N], min(costG[N], costB[N])) << endl;

  return 0;
}