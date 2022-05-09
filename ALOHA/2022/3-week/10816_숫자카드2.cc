#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

int N, M;

int binSearch(const vi& arr, int val) {
  int start = 0, end = arr.size() - 1;

  while (start <= end) {
    int mid = (start + end) / 2;

    if (val == arr[mid]) return mid;

    if (val > arr[mid]) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }

  return -1;
}

int main() {
  vi arr;

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    int n;
    scanf("%d", &n);

    arr.push_back(n);
  }

  sort(arr.begin(), arr.end());

  scanf("%d", &M);
  for (int i = 0; i < M; i++) {
    int temp;
    scanf("%d", &temp);

    int loc = binSearch(arr, temp);

    if (loc == -1) {
      printf("0 ");
      continue;
    }

    int num = upper_bound(arr.begin(), arr.end(), temp) -
              lower_bound(arr.begin(), arr.end(), temp);

    printf("%d ", num);
  }
  return 0;
}