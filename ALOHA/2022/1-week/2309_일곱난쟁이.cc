#include <bits/stdc++.h>

using namespace std;

constexpr int SIZE = 9;
int arr[SIZE];

int main() {
  int x = 0;
  for (int i = 0; i < 9; i++) {
    scanf("%d", &arr[i]);
    x += arr[i];
  }
  x -= 100;

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < i; j++) {
      if (arr[i] + arr[j] == x) {
        arr[i] = 0;
        arr[j] = 0;

        sort(arr, arr + 9);
        for (int k = 2; k < 9; k++) {
          printf("%d\n", arr[k]);
        }
        return 0;
      }
    }
  }

  return 0;
}