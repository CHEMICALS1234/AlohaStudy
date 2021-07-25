#include <iostream>
#include <stack>
#include <string>

#define FAST                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);

using namespace std;

string makePostfixNotation(string sample) {
  string result = "";
  stack<char> st;

  for (const auto c : sample) {
    if (('A' <= c && c <= 'Z') || ('0' <= c && c <= '9'))
      result += c;
    else {
      switch (c) {
        case '(':
          st.push(c);
          break;

        case '*':
        case '/':
          while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
            result += st.top();
            st.pop();
          }
          st.push(c);
          break;
        case '+':
        case '-':
          while (!st.empty() && st.top() != '(') {
            result += st.top();
            st.pop();
          }
          st.push(c);
          break;
        case ')':
          while (!st.empty() && st.top() != '(') {
            result += st.top();
            st.pop();
          }
          st.pop();
          break;
      }
    }
  }

  while (!st.empty()) {
    result += st.top();
    st.pop();
  }

  return result;
}

int calculate(string postfixedString) {
  stack<int> st;

  for (const auto temp : postfixedString) {
    if (temp == '+' || temp == '*' || temp == '-' || temp == '/') {
      int a = st.top();
      st.pop();
      int b = st.top();
      st.pop();

      int result;

      switch (temp) {
        case '+':
          result = b + a;
          break;

        case '*':
          result = b * a;
          break;

        case '-':
          result = b - a;
          break;

        case '/':
          result = b / a;
          break;

        default:
          break;
      }

      st.push(result);

    } else {
      st.push(temp - '0');
    }
  }

  return st.top();
}

int main() {
  FAST;

  string sample;
  cin >> sample;

  cout << calculate(makePostfixNotation(sample)) << "\n";

  return 0;
}