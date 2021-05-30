#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
  int n;
  stack<string> st;

  cin >> n;
  for (int i = 0; i < n; i++) {
    string temp;
    cin >> temp;
    st.push(temp);
  }

  while (!st.empty()) {
    cout << st.top() << " ";
    st.pop();
  }
  return 0;
}