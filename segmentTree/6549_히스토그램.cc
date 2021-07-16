#include <bits/stdc++.h>

using namespace std;

const int ARR_MAX = 100'000 + 50;

class SegmentTree {
  int h;
  int treeSize;
  int* tree;
  int start, end;

 public:
  SegmentTree(int n) : start(1), end(n) {
    h = static_cast<int>(ceil(log2(n)));
    treeSize = (1 << (h + 1));
    tree = new int[treeSize];
  }

  void init(int* arr, int start, int end, int node = 1) {
    if (start == end) {
      tree[node] = start;
      return;
    }

    int mid = (start + end) / 2;
    init(arr, start, mid, node * 2);
    init(arr, mid + 1, end, node * 2 + 1);

    if (arr[tree[node * 2]] <= arr[tree[node * 2 + 1]])
      tree[node] = tree[node * 2];
    else
      tree[node] = tree[node * 2 + 1];
  }

  int query(int* arr, int left, int right, int start, int end, int node = 1) {
    if (left > end || right < start) return -1;
    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    int m1 = query(arr, left, right, start, mid, node * 2);
    int m2 = query(arr, left, right, mid + 1, end, node * 2 + 1);

    if (m1 == -1)
      return m2;

    else if (m2 == -1)
      return m1;

    else {
      if (arr[m1] <= arr[m2])
        return m1;
      else
        return m2;
    }
  }

  long long getMax(int* arr, int n, int start, int end) {
    int m = query(arr, start, end, 1, n);

    long long area = static_cast<long long>(end - start + 1) *
                     static_cast<long long>(arr[m]);

    if (start <= m - 1) {
      long long temp = getMax(arr, n, start, m - 1);
      area = max(area, temp);
    }

    if (end >= m + 1) {
      long long temp = getMax(arr, n, m + 1, end);
      area = max(area, temp);
    }

    return area;
  }

  void printTree() {
    for (int i = 0; i < treeSize; i++) {
      printf("%d ", tree[i]);
    }
    printf("\n");
  }

  ~SegmentTree() { delete[] tree; }
};

int main() {
  while (true) {
    int n;
    scanf("%d", &n);
    if (n == 0) break;

    SegmentTree s(n);
    int arr[ARR_MAX] = {
        0,
    };

    for (int i = 1; i <= n; i++) {
      scanf("%d", &arr[i]);
    }

    s.init(arr, 1, n);
    printf("%lld\n", s.getMax(arr, n, 1, n));
  }

  return 0;
}