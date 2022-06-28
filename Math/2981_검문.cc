#include <bits/stdc++.h>

#define FAST                         \
  ios_base ::sync_with_stdio(false); \
  cin.tie(NULL);                     \
  cout.tie(NULL);

#define endl "\n"
#define INF 1'987'654'321

using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<long long>;

vi nums;
vi ans;
int N;

void printVec(const vi& v) {
  for (int i : v) {
    cout << i << " ";
  }
  cout << endl;
}

int main() {
  FAST;
  cin >> N;

  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    nums.push_back(a);
  }

  sort(nums.begin(), nums.end());

  int Mlike = nums[1] - nums[0];
  for (int i = 2; i < N; i++) {
    Mlike = gcd(Mlike, nums[i] - nums[i - 1]);
  }

  for (int i = 2; i * i <= Mlike; i++) {
    if (Mlike % i == 0) {
      ans.push_back(i);

      if (i != (Mlike / i)) {
        ans.push_back(Mlike / i);
      }
    }
  }
  ans.push_back(Mlike);

  sort(ans.begin(), ans.end());

  printVec(ans);

  return 0;
}