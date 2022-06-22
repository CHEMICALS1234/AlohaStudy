#include <bits/stdc++.h>
#define MAX 1'000 + 10
#define endl "\n"

using namespace std;

int table[MAX][MAX] = {};

int makeTable(string& a, string& b) {
  int alen = a.length();
  int blen = b.length();

  int m = 0;

  for (int i = 1; i <= alen; i++) {
    for (int j = 1; j <= blen; j++) {
      if (a[i - 1] == b[j - 1]) {
        table[i][j] = table[i - 1][j - 1] + 1;
        m = max(m, table[i][j]);
      }
      else {
        table[i][j] = max(table[i - 1][j], table[i][j - 1]);
        m = max(m, table[i][j]);
      }
    }
  }

  return m;
}

int main() {
  string a, b;
  cin >> a >> b;

  cout << makeTable(a, b) << endl;
  return 0;
}