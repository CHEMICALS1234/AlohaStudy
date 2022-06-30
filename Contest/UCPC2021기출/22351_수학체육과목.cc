#include <bits/stdc++.h>

#define FAST                         \
  ios_base ::sync_with_stdio(false); \
  cin.tie(NULL);                     \
  cout.tie(NULL);

#define endl "\n"

using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<long long>;
using vpi = vector<pair<int, int>>;

int main() {
  FAST;

  string s;
  cin >> s;

  for (int lenA = 1; lenA <= 3; lenA++) {
    bool isBest = true;
    int step = lenA;
    int first = stoi(s.substr(0, step));
    int prev, curr;

    for (int i = step; i < s.length(); i += step) {
      prev = stoi(s.substr(i - step, step));

      if (prev == pow(10, step) - 1) {
        step++;
      }

      if (i + step - 1 >= s.length()) {
        isBest = false;
        break;
      }

      curr = stoi(s.substr(i, step));

      if (prev + 1 != curr) {
        isBest = false;
        break;
      }
    }

    if (isBest) {
      if (first >= curr) {
        cout << first << " " << first << endl;
        break;
      }

      cout << first << " " << curr << endl;
      break;
    }
  }
  return 0;
}