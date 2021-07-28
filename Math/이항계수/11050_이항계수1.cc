#include <iostream>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  if (2 * k > n) k = n - k;

  int result = 1;

  for (int i = 0; i < k; i++) {
    result *= n--;
  }
  while (k) {
    result /= k--;
  }

  cout << result << "\n";

  return 0;
}