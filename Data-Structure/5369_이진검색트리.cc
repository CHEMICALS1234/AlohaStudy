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
using vpi = vector<pair<int, int>>;

struct treeNode {
  int data;
  treeNode* left;
  treeNode* right;

  treeNode() : data(0), left(nullptr), right(nullptr) {}
  treeNode(int data) : data(data), left(nullptr), right(nullptr) {}

  ~treeNode() {
    if (left != nullptr)
      delete left;

    if (right != nullptr)
      delete right;
  }
};

void addNode(treeNode** root, int data) {
  if (*root == nullptr) {
    (*root) = new treeNode(data);
  }
  else if (data > (*root)->data) {
    addNode(&((*root)->right), data);
  }
  else {
    addNode(&((*root)->left), data);
  }
}

void postOrder(treeNode* root) {
  if (root == nullptr) {
    return;
  }

  postOrder(root->left);
  postOrder(root->right);
  cout << root->data << " ";
}

int main() {
  FAST;

  treeNode* root = nullptr;

  vi nums;

  int n;
  while (cin >> n) {
    if (n == EOF)
      break;
    addNode(&root, n);
  }

  postOrder(root);
  cout << endl;

  return 0;
}