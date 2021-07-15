#include <bits/stdc++.h>

using namespace std;

const int ARR_MAX = 1'000'000 + 50;

class SegmentTree {
  int h;
  int treeSize;
  long long* tree;
  int start, end;

 public:
  SegmentTree(int n) : start(1), end(n) {
    h = static_cast<int>(ceil(log2(n)));
    treeSize = (1 << (h + 1));
    tree = new long long[treeSize];
  }

  long long init(long long* arr, int start, int end, int node = 1) {
    if (start == end) return tree[node] = arr[start];

    int mid = (start + end) / 2;

    return tree[node] = this->init(arr, start, mid, node * 2) +
                        this->init(arr, mid + 1, end, node * 2 + 1);
  }
  long long init(long long* arr, int node = 1) {
    if (start == end) return tree[node] = arr[start];

    int mid = (start + end) / 2;

    return tree[node] = this->init(arr, start, mid, node * 2) +
                        this->init(arr, mid + 1, end, node * 2 + 1);
  }

  long long sum(int start, int end, int left, int right, int node = 1) {
    if (left > end || right < start) return 0;
    if (left <= start && right >= end) return tree[node];

    int mid = (start + end) / 2;
    return sum(start, mid, left, right, node * 2) +
           sum(mid + 1, end, left, right, node * 2 + 1);
  }
  long long sum(int left, int right, int node = 1) {
    if (left > end || right < start) return 0;
    if (left <= start && right >= end) return tree[node];

    int mid = (start + end) / 2;
    return sum(start, mid, left, right, node * 2) +
           sum(mid + 1, end, left, right, node * 2 + 1);
  }

  void update(int start, int end, int index, long long diff, int node = 1) {
    if (index < start || index > end) return;

    tree[node] += diff;

    if (start != end) {
      int mid = (start + end) / 2;
      update(start, mid, index, diff, node * 2);
      update(mid + 1, end, index, diff, node * 2 + 1);
    }
  }
  void update(int index, long long diff, int node = 1) {
    if (index < start || index > end) return;

    tree[node] += diff;

    if (start != end) {
      int mid = (start + end) / 2;
      update(start, mid, index, diff, node * 2);
      update(mid + 1, end, index, diff, node * 2 + 1);
    }
  }

  void printTree() {
    for (int i = 0; i < treeSize; i++) {
      printf("%lld ", tree[i]);
    }
    printf("\n");
  }

  ~SegmentTree() { delete[] tree; }
};

int main() {
  int n, m, k;
  n = 8;

  long long arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};

  SegmentTree s(n);
  s.init(arr);

  // s.printTree();

  cout << s.sum(3, 7);

  return 0;
}