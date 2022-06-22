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

// bool compare(const string& s1, const string& s2) {
//   if (s1.length() == s2.length()) {
//     return s1 < s2;
//   }
//   else {
//     return s1.length() < s2.length();
//   }
// }

void printVector(const vector<string>& v) {
  for (auto s : v) {
    cout << s << " ";
  }
  cout << endl;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<string> phonebook;

    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      phonebook.push_back(s);
    }

    // 길이가 짧은 순으로 정렬.
    sort(phonebook.begin(), phonebook.end());

    // printVector(phonebook);

    bool check = true;
    for (int i = 0; i < phonebook.size() - 1; i++) {
      string curr = phonebook[i];
      string next = phonebook[i + 1];

      for (int j = 0; j < curr.size(); j++) {
        check = true;
        if (curr[j] != next[j]) {
          check = false;
          break;
        }
      }

      if (check) {
        cout << "NO\n";
        break;
      }
    }

    if (!check) {
      cout << "YES\n";
    }
  }

  return 0;
}
