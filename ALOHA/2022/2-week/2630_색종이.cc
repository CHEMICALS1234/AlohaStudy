#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

int N;

int blue = 0, white = 0;

vvi maps;

void solve(int ystart, int xstart, int len) {
  if (len == 1) {
    if (maps[ystart][xstart]) {
      blue++;
    } else {
      white++;
    }
    return;
  }

  int prev = maps[ystart][xstart], now;
  bool isOneColor = true;

  for (int i = ystart; i < ystart + len; i++) {
    for (int j = xstart; j < xstart + len; j++) {
      if (i == ystart && j == xstart) continue;
      now = maps[i][j];
      if (now != prev) {
        isOneColor = false;
        break;
      }
      prev = now;
    }
    if (!isOneColor) break;
  }
  if (isOneColor) {
    if (now) {
      blue++;
    } else {
      white++;
    }

    return;
  }

  int nextLen = len / 2;

  solve(ystart, xstart, nextLen);
  solve(ystart + nextLen, xstart, nextLen);
  solve(ystart, xstart + nextLen, nextLen);
  solve(ystart + nextLen, xstart + nextLen, nextLen);
}

int main() {
  scanf("%d", &N);

  for (int i = 0; i < N; i++) {
    vi tempvec;
    for (int j = 0; j < N; j++) {
      int temp;
      scanf("%d", &temp);

      tempvec.push_back(temp);
    }
    maps.push_back(tempvec);
  }

  solve(0, 0, N);

  printf("%d\n%d\n", white, blue);
  return 0;
}