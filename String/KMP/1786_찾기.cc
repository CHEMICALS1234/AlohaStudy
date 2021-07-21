#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> getPi(string pattern) {
  int m = static_cast<int>(pattern.size()), j = 0;
  vector<int> pi(m, 0);

  for (int i = 1; i < m; i++) {  // pi[0] = 무조건 0이니까, 1부터 시작해도 좋다.
    while (j > 0 && (pattern[i] != pattern[j])) j = pi[j - 1];
    if (pattern[i] == pattern[j]) pi[i] = ++j;
  }

  return pi;
}

vector<int> kmp(string s, string pattern) {
  vector<int> ans;
  auto pi = getPi(pattern);

  int stringSize = static_cast<int>(s.size()),
      patternSize = static_cast<int>(pattern.size()),
      //
      j = 0;

  for (int i = 0; i < stringSize; i++) {
    while (j > 0 && (s[i] != pattern[j])) j = pi[j - 1];

    if (s[i] == pattern[j]) {
      if (j == patternSize - 1) {
        ans.push_back(i - patternSize + 1);
        j = pi[j];
      } else {
        j++;
      }
    }
  }

  return ans;
}

int main() {
  string s, pattern;
  getline(cin, s);
  getline(cin, pattern);

  auto matched = kmp(s, pattern);

  printf("%d\n", static_cast<int>(matched.size()));

  for (auto i : matched) printf("%d ", i + 1);

  return 0;
}