#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using node_t = ll;
using dist_t = ll;

#define endl "\n"
#define INF 987654321

#define MAXSIZE 404040

class SegmentTree {
  int n;
  pair<ll, ll> tree[MAXSIZE];

  // pair<int,int> = pair<index, value> 로 생각.
  pair<ll, ll> action(const pair<ll, ll>& leftChild,
                      const pair<ll, ll>& rightChild) {
    // do something
    if (leftChild.second == rightChild.second) {
      return (leftChild.first < rightChild.first) ? leftChild : rightChild;
    }

    return (leftChild.second < rightChild.second) ? leftChild : rightChild;
  }

 public:
  SegmentTree() {}
  SegmentTree(int n) : n(n){};

  void inputArr() {
    for (int i = 0; i < n; i++) {
      tree[n + i].first = i + 1;
      cin >> tree[n + i].second;
    }
  }

  void build() {
    for (int i = n - 1; i > 0; i--) {
      tree[i] = action(tree[i << 1], tree[(i << 1) | 1]);
    }
  }

  void modify(int pos, pair<ll, ll> value) {
    for (tree[pos += n] = value; pos > 1; pos >>= 1) {
      tree[pos >> 1] = action(tree[pos], tree[pos ^ 1]);
    }
  }

  pair<ll, ll> query(ll left, ll right) {
    pair<ll, ll> res = {MAXSIZE, INF};

    for (left += n, right += n; left < right; left >>= 1, right >>= 1) {
      if (left & 1)
        res = action(res, tree[left++]);

      if (right & 1)
        res = action(res, tree[--right]);
    }

    return res;
  }

  void printTree() {
    for (int i = 1, j = 2; i < (2 * n); i++) {
      cout << "(" << tree[i].first << "," << tree[i].second << ")" << '\t';

      if (i == (j - 1)) {
        cout << endl;
        j <<= 1;
      }
    }
  }
};

int N, M;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  SegmentTree st(N);
  st.inputArr();
  st.build();

  cin >> M;
  while (M--) {
    int a, b, c;
    cin >> a >> b >> c;
    switch (a) {
      case 1: {
        st.modify(b - 1, {b, c});
        break;
      }
      default: {
        cout << st.query(b - 1, c).first << endl;
      }
    }
  }

  return 0;
}
