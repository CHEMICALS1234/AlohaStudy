#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

int N, M;

int binSearch(const vi& arr, int val) {
  int start = 0, end = arr.size() - 1;

  while (start <= end) {
    int mid = (start + end) / 2;

    if (val == arr[mid]) return 1;

    if (val > arr[mid]) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }

  return 0;
}

int main() {
  vi arr;
  scanf("%d", &N);

  for (int i = 0; i < N; i++) {
    int temp;
    scanf("%d", &temp);
    arr.push_back(temp);
  }

  sort(arr.begin(), arr.end());

  scanf("%d", &M);
  for (int i = 0; i < M; i++) {
    int m;
    scanf("%d", &m);

    printf("%d\n", binSearch(arr, m));
  }

  return 0;
}