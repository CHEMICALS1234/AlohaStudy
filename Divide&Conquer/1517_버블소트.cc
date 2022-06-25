#include <bits/stdc++.h>

#define FAST                         \
  ios_base ::sync_with_stdio(false); \
  cin.tie(NULL);                     \
  cout.tie(NULL);

#define endl "\n"

using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<long long>;

#define MAXSIZE 500'000

vi arr(MAXSIZE + 10);
vi sorted(MAXSIZE + 10);

ll ans;

void merge(int left, int mid, int right) {
  int i = left;
  int j = mid + 1;
  int k = left;

  while (i <= mid && j <= right) {
    if (arr[i] <= arr[j]) {
      sorted[k++] = arr[i++];
    }
    else {
      sorted[k++] = arr[j++];
      ans += ((ll)mid - i + 1);
    }
  }

  while (i <= mid) {
    sorted[k++] = arr[i++];
  }
  while (j <= right) {
    sorted[k++] = arr[j++];
  }

  for (int t = left; t <= right; t++) {
    arr[t] = sorted[t];
  }
}

void mergeSort(int left, int right) {
  if (left >= right)
    return;

  int mid = (left + right) / 2;
  mergeSort(left, mid);
  mergeSort(mid + 1, right);
  merge(left, mid, right);
}

int main() {
  FAST;

  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  mergeSort(0, N - 1);

  cout << ans << endl;
  return 0;
}