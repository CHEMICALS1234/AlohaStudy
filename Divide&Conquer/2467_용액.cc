#include <bits/stdc++.h>

#define FAST                         \
  ios_base ::sync_with_stdio(false); \
  cin.tie(NULL);                     \
  cout.tie(NULL);

#define endl "\n"
#define INF 123987654321LL

using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<long long>;
using vpi = vector<pair<int, int>>;

vll nums;
int N;

int main() {
  FAST;

  cin >> N;
  for (int i = 0; i < N; i++) {
    ll a;
    cin >> a;
    nums.push_back(a);
  }

  ll ans = INF;
  ll minCurr = 0, minNum = 0;
  for (int i = 0; i < N; i++) {
    ll curr = -nums[i];

    int highIndex = upper_bound(nums.begin(), nums.end(), curr) - nums.begin();

    int nextIndex;
    if (highIndex == N) {
      nextIndex = highIndex - 1;
    }
    else if (highIndex == 0) {
      nextIndex = highIndex;
    }
    else {
      nextIndex =
          (abs(nums[highIndex] - curr) < abs(nums[highIndex - 1] - curr))
              ? highIndex
              : highIndex - 1;
    }

    if (nextIndex == i)
      continue;

    if (abs(nums[nextIndex] - curr) < ans) {
      ans = abs(nums[nextIndex] - curr);
      minCurr = -curr;
      minNum = nums[nextIndex];
    }
  }

  if (minCurr <= minNum) {
    cout << minCurr << " " << minNum << endl;
  }
  else {
    cout << minNum << " " << minCurr << endl;
  }

  return 0;
}