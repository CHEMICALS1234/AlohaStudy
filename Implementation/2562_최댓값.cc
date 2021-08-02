#include <iostream>

using namespace std;

int main() {
  int idx = 1;
  int m = 0;
  for (int j = 1; j < 10; j++) {
    int temp;
    cin >> temp;
    if (temp > m) {
      m = temp;
      idx = j;
    }
  }
  cout << m << "\n" << idx << "\n";

  return 0;
}