#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int ARR_MAX = 1'000 + 10;
const int INF = 987654321;
int happiness[ARR_MAX][ARR_MAX];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int r, c;
  cin >> r >> c;

  string s = "";

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> happiness[i][j];
    }
  }

  if (r & 1) {  // 행이 홀수 개일 경우
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c - 1; j++) {
        if (i & 1)
          s += "L";
        else
          s += "R";
      }
      if (i != r - 1) s += "D";
    }
  } else if (c & 1) {  // 열이 홀수 개일 경우
    for (int i = 0; i < c; i++) {
      for (int j = 0; j < r - 1; j++) {
        if (i & 1)
          s += "U";
        else
          s += "D";
      }
      if (i != c - 1) s += "R";
    }
  } else {                    // 행, 열 모두 짝수 개일 경우
    pair<int, int> minPoint;  // 검은 칸 && 지나면 안되는 곳.
    int minScore = INF;

    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (((i + j) & 1) && minScore > happiness[i][j]) {
          minScore = happiness[i][j];
          minPoint = {i, j};
        }
      }
    }

    // 꼬불꼬불 할 수 있는 최좌측 지점까지 가기.
    int newR = (minPoint.first & 1) ? minPoint.first - 1 : minPoint.first;
    for (int i = 0; i < newR; i++) {
      for (int j = 0; j < c - 1; j++) {
        if (i & 1)
          s += "L";
        else
          s += "R";
      }
      s += "D";
    }

    // 먼저 꼬불꼬불
    int newC = minPoint.second;
    for (int j = 0; j < newC; j++) {
      if (j & 1)
        s += "UR";
      else
        s += "DR";
    }

    for (int j = newC; j < c - 1; j++) {
      if (j & 1)
        s += "RU";
      else
        s += "RD";
    }

    newR = (minPoint.first & 1) ? (r - minPoint.first - 1)
                                : (r - minPoint.first - 2);

    for (int i = 0; i < newR; i++) {
      s += "D";
      for (int j = 0; j < c - 1; j++) {
        if (i & 1)
          s += "R";
        else
          s += "L";
      }
    }
  }

  cout << s << "\n";

  return 0;
}