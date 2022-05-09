#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

vi height;

int main() {
  while (true) {
    height.clear();
    int n;
    scanf("%d", &n);
    if (n == 0) return;

    for (int i = 0; i < n; i++) {
      int temp;
      scanf("%d", &temp);
      height.push_back(temp);
    }
  }
  return 0;
}