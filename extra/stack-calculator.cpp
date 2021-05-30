#include <iostream>
#include <stack>
#include <string>

using namespace std;

int getPriority(char c) {
  int prior = 0;
  if (c == '+' || c == '-')
    prior = 1;
  else if (c == '*' || c == '/')
    prior = 2;
  else if (c == '(')
    prior = -1;
  return prior;
}

string makePostfixNotation(string sample) {
  string result = "";
  stack<char> st;

  for (int i = 0; i < sample.size(); i++) {
    char temp = sample[i];
    if (temp == '+' || temp == '*' || temp == '-' || temp == '/' ||
        temp == '(' || temp == ')') {
      while (!st.empty()) {
        if (temp == '(') break;

        if (getPriority(st.top()) >= getPriority(temp)) {
          result.push_back(st.top());
          st.pop();
        } else {
          if (temp == ')' || st.top() == '(') {
            st.pop();
          }
          break;
        }
      }
      if (temp != ')') st.push(temp);

    } else {
      result.push_back(temp);
    }
  }

  while (!st.empty()) {
    result.push_back(st.top());
    st.pop();
  }

  return result;
}

int calculate(string postfixedString) {
  stack<int> st;

  for (int i = 0; i < postfixedString.size(); i++) {
    char temp = postfixedString[i];
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
  string sample;
  cin >> sample;

  string resultString = makePostfixNotation(sample);

  int result = calculate(resultString);

  cout << result << '\n';
  return 0;
}