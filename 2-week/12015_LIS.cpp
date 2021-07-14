#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  vector<int> LIS;
  int n;
  cin >> n;
  int v[n];
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  for (int i = 0; i < n; i++) {
    int idx = (lower_bound(LIS.begin(), LIS.end(), v[i]) - LIS.begin());
    if (idx == LIS.size()) {
      LIS.push_back(v[i]);
    } else {
      LIS[idx] = v[i];
    }
  }
  cout << LIS.size() << "\n";
  return 0;
}