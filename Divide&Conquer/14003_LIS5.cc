#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using node_t = ll;
using dist_t = ll;

#define endl "\n"
#define INF 2e18

#define MAXSIZE 1'000'005
int a[MAXSIZE];
// index 저장
int dp[MAXSIZE];

vector<int> v;
stack<int> ans;

int N;
int lastIndex = 0;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
  }

  v.push_back(a[1]);

  for (int i = 2; i <= N; i++) {
    if (v[lastIndex] < a[i]) {
      v.push_back(a[i]);
      lastIndex++;
      dp[i] = lastIndex;

      continue;
    }

    int pos = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
    v[pos] = a[i];
    dp[i] = pos;
  }

  for (int i = N; i >= 0; i--) {
    if (dp[i] == lastIndex) {
      ans.push(a[i]);
      lastIndex--;
    }
  }

  cout << ans.size() << endl;
  while (!ans.empty()) {
    cout << ans.top() << " ";
    ans.pop();
  }
  cout << endl;
  return 0;
}