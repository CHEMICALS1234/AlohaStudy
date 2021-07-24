#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getPi(const string& pattern) {
  int patternLength = static_cast<int>(pattern.size()), j = 0;
  vector<int> pi(patternLength, 0);

  for (int i = 1; i < patternLength; i++) {
    while (j > 0 && (pattern[i] != pattern[j])) j = pi[j - 1];
    if (pattern[i] == pattern[j]) pi[i] = ++j;
  }

  int maxValue = *max_element(pi.begin(), pi.end());

  return maxValue;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;

  int maxValue = 0;

  for (int i = 0; i < s.size(); i++) {
    maxValue = max(maxValue, getPi(s.substr(i, s.size())));
  }

  cout << maxValue;

  return 0;
}