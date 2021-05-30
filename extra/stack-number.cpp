#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
  string s;
  stack<char> st, result;

  cin >> s;

  for (int i = 0; i < s.size(); i++) {
    st.push(s[i]);
  }

  int t = 0;

  while (!st.empty()) {
    if (t == 3) {
      result.push(',');
      t = 0;
    }
    result.push(st.top());
    st.pop();
    t++;
  }
  while (!result.empty()) {
    cout << result.top();
    result.pop();
  }

  return 0;
}