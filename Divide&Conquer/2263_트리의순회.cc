#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using node_t = ll;
using dist_t = ll;
using vi = vector<int>;
using vll = vector<ll>;

#define all(x) (x).begin(), (x).end()

#define endl "\n"
#define INF 2e18
#define MOD 1'000'000'007

int n;
vi inorder(100000 + 10);
vi postorder(100000 + 10);
vi preorder;

// 1. Find the root of divided array refer to postorder.
// 2. Search the root and divide inorder.
void divide(int inleft, int inright, int postleft, int postright) {
  if (inright - inleft != postright - postleft) return;
  if (inleft >= inright || postleft >= postright) return;

  int range = inright - inleft;

  // Find and search root.
  for (int i = 0; i < range; i++) {
    int root = postorder[postright - 1];
    if (inorder[inleft + i] != root) continue;

    // Found root in inorder array.
    preorder.push_back(root);
    divide(inleft, inleft + i, postleft, postleft + i);
    divide(inleft + i + 1, inright, postleft + i, postright - 1);
    // Exclude the right-most value of postorder (= root). so, postright - 1.
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> inorder[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> postorder[i];
  }

  divide(0, n, 0, n);

  for (int v : preorder) {
    cout << v << " ";
  }

  return 0;
}