#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define FAST                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);

using namespace std;

int getPi(const string& pattern) {
  int patternLength = static_cast<int>(pattern.size()), j = 0;
  vector<int> pi(patternLength, 0);

  for (int i = 1; i < patternLength; i++) {
    while (j > 0 && (pattern[i] != pattern[j])) j = pi[j - 1];
    if (pattern[i] == pattern[j]) pi[i] = ++j;
  }

  return pi[patternLength - 1];
}

int main() {
  FAST;

  while (true) {
    string s;
    cin >> s;

    if (s == ".") break;

    int piVal = getPi(s);
    int length = s.size();

    if (piVal == 0 || length % (length - piVal)) {
      cout << 1 << "\n";
    } else {
      cout << length / (length - piVal) << "\n";
    }
  }
  return 0;
}