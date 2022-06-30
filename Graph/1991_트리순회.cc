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
  char data;
  treeNode* left;
  treeNode* right;

  treeNode() : data(0), left(nullptr), right(nullptr) {}
  treeNode(char data) : data(data), left(nullptr), right(nullptr) {}

  ~treeNode() {
    if (left != nullptr)
      delete left;

    if (right != nullptr)
      delete right;
  }
};

void preOrder(treeNode* root) {
  if (root == nullptr) {
    return;
  }

  cout << root->data;
  preOrder(root->left);
  preOrder(root->right);
}

void inOrder(treeNode* root) {
  if (root == nullptr) {
    return;
  }

  inOrder(root->left);
  cout << root->data;
  inOrder(root->right);
}

void postOrder(treeNode* root) {
  if (root == nullptr) {
    return;
  }

  postOrder(root->left);
  postOrder(root->right);
  cout << root->data;
}

#define MAXSIZE 30
int N;
treeNode* nodes[MAXSIZE];

int main() {
  FAST;

  for (int i = 0; i < MAXSIZE; i++) {
    nodes[i] = new treeNode(i + 'A');
  }

  cin >> N;

  for (int i = 0; i < N; i++) {
    char root, left, right;

    cin >> root >> left >> right;

    nodes[root - 'A']->left = (left == '.') ? nullptr : nodes[left - 'A'];
    nodes[root - 'A']->right = (right == '.') ? nullptr : nodes[right - 'A'];
  }

  preOrder(nodes[0]);
  cout << endl;
  inOrder(nodes[0]);
  cout << endl;
  postOrder(nodes[0]);
  cout << endl;

  return 0;
}