#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using node_t = ll;
using dist_t = ll;

#define endl "\n"
#define INF 2e18

#define MAXSIZE 1'000'005
#define MOD 1'000'000'007

template <typename T>
class SegmentTree {
  int n;  // 데이터 개수
  T tree[2 * MAXSIZE];

  // 합, 곱, concat 등등.
  T action(T leftChild, T rightChild) {
    // do something
    return (leftChild * rightChild) % MOD;
  }

 public:
  SegmentTree() {}
  SegmentTree(int n) : n(n){};

  // n개의 데이터를 입력받음.
  void inputArr() {
    for (int i = 0; i < n; i++) {
      cin >> tree[n + i];
    }
  }

  // 세그먼트 트리를 만듦.
  void build() {
    for (int i = n - 1; i > 0; i--) {
      // 부모 노드를 왼쪽, 오른쪽 자식의 action으로 설정한다.
      tree[i] = action(tree[i << 1], tree[(i << 1) | 1]);
    }
  }

  // pos 위치의 값을 value로 대체.
  void modify(int pos, T value) {
    // pos를 n + pos로 바꿔주고 그 자리의 값을 value로 먼저 바꾼다.
    for (tree[pos += n] = value; pos > 1; pos >>= 1) {
      // 그런 후, 부모의 값을 자신과 형제의 action으로 바꿔준다.
      tree[pos >> 1] = action(tree[pos], tree[pos ^ 1]);

      // 이를 root(1번 노드) 까지 반복.
    }
  }

  // [left, right) 의 action을 반환.
  T query(ll left, ll right) {
    T res = 1;

    // 먼저 tree에서의 left, right를 초기화.
    for (left += n, right += n; left < right; left >>= 1, right >>= 1) {
      // left가 홀수(rightChild라는 뜻)면 action. 짝수면 위에서 action.
      if (left & 1) {
        res = action(res, tree[left++]);
      }

      // 이때도 action but, right는 포함 안되니까 먼저 -- 하고 action.
      if (right & 1) {
        res = action(res, tree[--right]);
      }
    }

    return res;
  }

  void printTree() {
    for (int i = 1, j = 2; i < (2 * n); i++) {
      cout << tree[i] << '\t';

      if (i == (j - 1)) {
        cout << endl;
        j <<= 1;
      }
    }
  }
};

int N, M, K;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M >> K;

  SegmentTree<ll> st(N);
  st.inputArr();
  st.build();

  for (int i = 0; i < M + K; i++) {
    int a, b, c;
    cin >> a >> b >> c;

    switch (a) {
      case 1: {
        st.modify(b - 1, c);
        break;
      }

      default: {
        cout << st.query(b - 1, c) % MOD << endl;
        break;
      }
    }
  }

  return 0;
}
