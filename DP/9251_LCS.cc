#include <bits/stdc++.h>

using namespace std;
const int MAX = 1000 + 5;

int arr[MAX][MAX];

int makeTable(string a, string b) {
  int aLen = a.length();
  int bLen = b.length();

  int m = 0;

  for (int i = 0; i <= aLen; i++) {
    for (int j = 0; j <= bLen; j++) {
      arr[i][j] = 0;
    }
  }

  for (int i = 1; i <= aLen; i++) {
    for (int j = 1; j <= bLen; j++) {
      if (a[i - 1] == b[j - 1]) {
        arr[i][j] = arr[i - 1][j - 1] + 1;
        m = max(m, arr[i][j]);
      } else {
        arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
        m = max(m, arr[i][j]);
      }
    }
  }
  return m;
}

void printArr(int aLen, int bLen) {
  for (int i = 0; i <= aLen; i++) {
    for (int j = 0; j <= bLen; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}

string findLCS(string a, string b, int m) {
  int aLen = a.length();
  int bLen = b.length();
  string temp;

  for (int i = aLen; i > 0; i--) {
    for (int j = bLen; j > 0; j--) {
      if (m) {
        if (arr[i][j] != arr[i - 1][j] && arr[i][j] != arr[i][j - 1] &&
            arr[i][j] <= m) {
          temp.insert(0, 1, a[i - 1]);
          m--;
        }
      }
    }
  }

  return temp;
}

int main() {
  string b, a;
  cin >> b >> a;

  cout << makeTable(a, b);
}