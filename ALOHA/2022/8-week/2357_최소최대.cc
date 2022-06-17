#include <bits/stdc++.h>

using namespace std;

const int ARR_MAX = 100'000 + 5;
const int INF = 1'000'000'000 + 20;

using ll = long long;

class SegmentTree {
  int h;
  int treeSize;
  ll* tree;
  bool isMin;

 public:
  SegmentTree(int n, bool isMin) : isMin(isMin) {
    h = static_cast<int>(ceil(log2(n)));
    treeSize = (1 << (h + 1));
    tree = new ll[treeSize];

    if (isMin) {
      fill(tree, tree + treeSize, INF);
    }
    else {
      fill(tree, tree + treeSize, 0);
    }
  }

  ll init(ll* arr, int start, int end, int node = 1) {
    if (start == end)
      return tree[node] = arr[start];

    int mid = (start + end) / 2;

    return (isMin)
               ? tree[node] = min(this->init(arr, start, mid, node * 2),
                                  this->init(arr, mid + 1, end, node * 2 + 1))
               : tree[node] = max(this->init(arr, start, mid, node * 2),
                                  this->init(arr, mid + 1, end, node * 2 + 1));
  }

  ll query(int start, int end, int left, int right, int node = 1) {
    if (left > end || right < start)
      return 0;
    if (left <= start && right >= end)
      return tree[node];

    int mid = (start + end) / 2;

    return (isMin) ? min(query(start, mid, left, right, node * 2),
                         query(mid + 1, end, left, right, node * 2 + 1))
                   : max(query(start, mid, left, right, node * 2),
                         query(mid + 1, end, left, right, node * 2 + 1));
  }

  void update(ll* arr, int start, int end, int index, ll diff, int node = 1) {
    if (index < start || index > end)
      return;

    tree[node] += diff;

    if (start == end)
      arr[start] += diff;

    if (start != end) {
      int mid = (start + end) / 2;
      update(arr, start, mid, index, diff, node * 2);
      update(arr, mid + 1, end, index, diff, node * 2 + 1);
    }
  }

  void printTree() {
    for (int i = 1; i < treeSize; i++) {
      printf("%lld ", tree[i]);
    }
    printf("\n");
  }

  ~SegmentTree() { delete[] tree; }
};

int N, M;

int main() {
  scanf("%d %d", &N, &M);

  ll arr[ARR_MAX];

  for (int i = 0; i < N; i++) {
    scanf("%lld", &arr[i]);
  }

  SegmentTree minTree(N, true);
  SegmentTree maxTree(N, false);
  minTree.init(arr, 1, N);
  maxTree.init(arr, 1, N);

  minTree.printTree();

  // for (int i = 0; i < M; i++) {
  //   ll a, b;
  //   scanf("%lld %lld", &a, &b);

  //   printf("%lld %lld\n", minTree.query(1, N, a, b), minTree.query(1, N, a,
  //   b));
  // }
  return 0;
}