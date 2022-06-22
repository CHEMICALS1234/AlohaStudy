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

void checkBomb(vector<char>& v, const string& sbomb) {
  int vSize = v.size();
  int sSize = sbomb.length();
  for (int i = 1; i <= sSize; i++) {
    if (v[vSize - i] != sbomb[sSize - i]) {
      return;
    }
  }

  for (int i = 0; i < sSize; i++) {
    v.pop_back();
  }
}

int main() {
  string s, sbomb;
  vector<char> v;

  cin >> s >> sbomb;

  for (int i = 0; i < s.length(); i++) {
    v.push_back(s[i]);

    if (v.size() >= sbomb.length()) {
      checkBomb(v, sbomb);
    }
  }

  if (v.size() == 0) {
    cout << "FRULA";
  }
  else {
    for (char c : v) {
      cout << c;
    }
  }
  cout << endl;
  return 0;
}