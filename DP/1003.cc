#include <bits/stdc++.h>

using namespace std;

const int MAX = 45;

vector<pair<int, int>> arr;

void makeTable() {
  arr.push_back(make_pair(1, 0));
  arr.push_back(make_pair(0, 1));
  for (int i = 2; i < MAX; i++) {
    int a = arr[i - 1].first + arr[i - 2].first;
    int b = arr[i - 1].second + arr[i - 2].second;

    arr.push_back(make_pair(a, b));
  }
}

void printPair(pair<int, int> p) { cout << p.first << " " << p.second << "\n"; }

int main() {
  makeTable();

  int TC;
  scanf("%d", &TC);

  for (int i = 0; i < TC; i++) {
    int N;
    scanf("%d", &N);

    printPair(arr[N]);
  }
}