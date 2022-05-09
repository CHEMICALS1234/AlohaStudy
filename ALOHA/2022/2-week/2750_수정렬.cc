#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 1'000 + 10;
int n;
int arr[MAX_SIZE];

void merge(int left, int mid, int right) {
  int size_left = mid - left + 1;
  int size_right = right - mid;

  int temp_arr_left[size_left], temp_arr_right[size_right];  // 임시 array 생성

  for (int i = 0; i < size_left; i++) {
    temp_arr_left[i] = arr[left + i];
  }

  for (int i = 0; i < size_right; i++) {
    temp_arr_right[i] = arr[mid + 1 + i];
  }

  for (int i = 0, j = 0, k = left; k < left + size_left + size_right; k++) {
    if (i >= size_left)
      arr[k] = temp_arr_right[j++];

    else if (j >= size_right)  // i < size_left && j >= size_right 일 때
      arr[k] = temp_arr_left[i++];

    else {
      if (temp_arr_left[i] < temp_arr_right[j])
        arr[k] = temp_arr_left[i++];

      else
        arr[k] = temp_arr_right[j++];
    }
  }
}

void merge_sort(int left, int right) {
  if (left >= right) return;
  int mid = (left + right) / 2;

  merge_sort(left, mid);
  merge_sort(mid + 1, right);
  merge(left, mid, right);
}

int main() {
  scanf("%d", &n);

  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

  merge_sort(0, n - 1);

  for (int i = 0; i < n; i++) printf("%d\n", arr[i]);

  return 0;
}