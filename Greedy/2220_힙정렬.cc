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

#define MAXSIZE (100'000 + 10)

struct Heap {
  int lastIndex;
  int arr[MAXSIZE];

  Heap() {
    lastIndex = 0;
    for (int i = 0; i < MAXSIZE; i++) {
      arr[i] = 0;
    }
  }

  void print() {
    for (int i = 1; i <= lastIndex; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }

  void push(int n) {
    lastIndex++;

    if (lastIndex == 1) {
      arr[lastIndex] = n;
      return;
    }

    arr[lastIndex] = arr[lastIndex - 1];

    int index = lastIndex - 1;

    while ((index != 1) && (n > arr[index >> 1])) {
      arr[index] = arr[index >> 1];
      index >>= 1;
    }
    arr[index] = n;
  }

  void pop() {
    if (lastIndex == 0)
      return;

    if (lastIndex == 1) {
      arr[lastIndex] = 0;
      lastIndex--;
      return;
    }

    int lastData = arr[lastIndex];

    int parentIndex = 1;
    int childIndex = 2;

    while (childIndex <= lastIndex) {
      childIndex =
          (arr[childIndex] > arr[childIndex ^ 1]) ? childIndex : childIndex ^ 1;

      if (lastData >= arr[childIndex])
        break;

      arr[parentIndex] = arr[childIndex];
      parentIndex = childIndex;
      childIndex <<= 1;
    }

    arr[parentIndex] = lastData;
    arr[lastIndex] = 0;
    lastIndex--;
  }
};

int main() {
  FAST;

  Heap h;
  int N;
  cin >> N;

  for (int i = 1; i <= N; i++) {
    h.push(i);
  }

  h.print();
  return 0;
}