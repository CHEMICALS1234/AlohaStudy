#include <bits/stdc++.h>

#define FAST                         \
  ios_base ::sync_with_stdio(false); \
  cin.tie(NULL);                     \
  cout.tie(NULL);                    \
                                     \
#define endl "\n"

using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<long long>;

struct Node {
  map<string, Node*> child;
  map<string, Node*>::iterator iter;

  void insertNode(const vector<string>& v, int idx) {
    if (idx == v.size())
      return;

    string s = v[idx];
    iter = child.find(s);

    // 이미 있으면, 그 뒤에 추가한다.
    if (iter != child.end()) {
      iter->second->insertNode(v, idx + 1);
    }
    else {
      Node* n = new Node;
      child.insert({s, n});
      n->insertNode(v, idx + 1);
    }
  }
  void print(int idx) {
    if (child.empty())
      return;

    for (auto& p : child) {
      for (int i = 0; i < idx; i++) {
        cout << "--";
      }

      cout << p.first << endl;
      p.second->print(idx + 1);
    }
  }
};

int main() {
  int N, K;
  Node* root = new Node;
  cin >> N;

  while (N--) {
    cin >> K;
    vector<string> v;
    while (K--) {
      string s;
      cin >> s;
      v.push_back(s);
    }
    root->insertNode(v, 0);
  }

  root->print(0);
  return 0;
}
