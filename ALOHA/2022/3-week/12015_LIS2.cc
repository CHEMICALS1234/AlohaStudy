#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

int N;
vi dp;

int main() {
  scanf("%d", &N);

  for (int i = 0; i < N; i++) {
    int temp;
    scanf("%d", &temp);

    int index = (lower_bound(dp.begin(), dp.end(), temp) - dp.begin());

    if (index == dp.size()) {
      dp.push_back(temp);
    } else {
      dp[index] = temp;
    }
  }

  printf("%ld\n", dp.size());

  return 0;
}