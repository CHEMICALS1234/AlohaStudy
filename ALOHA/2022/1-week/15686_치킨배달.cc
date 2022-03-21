#include <bits/stdc++.h>

using namespace std;

using Point = pair<int, int>;

constexpr int INF = 98654321;

int N, M;
vector<Point> houseLoc;
vector<Point> chickenLoc;

int getDistance(const Point& p1, const Point& p2) {
  return (abs(p1.first - p2.first) + abs(p1.second - p2.second));
}

int calcCityDistance(const vector<Point>& pickedChickenLoc) {
  int res = 0;
  for (auto p1 : houseLoc) {
    int tempDistance = INF;
    for (auto p2 : pickedChickenLoc) {
      tempDistance = min(tempDistance, getDistance(p1, p2));
    }
    res += tempDistance;
  }

  return res;
}

int pickChicken(int count) {
  vector<bool> checkVec(chickenLoc.size() - count, false);
  checkVec.insert(checkVec.end(), count, true);

  int minDis = INF;

  do {
    vector<Point> pickedChickenLoc;

    for (int i = 0; i < chickenLoc.size(); i++) {
      if (checkVec[i]) {
        pickedChickenLoc.push_back(chickenLoc[i]);
      }
    }

    minDis = min(minDis, calcCityDistance(pickedChickenLoc));

  } while (next_permutation(checkVec.begin(), checkVec.end()));

  return minDis;
}

int main() {
  scanf("%d %d", &N, &M);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int tempNum;
      scanf("%d", &tempNum);

      if (tempNum == 1) {
        houseLoc.push_back({i, j});
      } else if (tempNum == 2) {
        chickenLoc.push_back({i, j});
      }
    }
  }

  printf("%d\n", pickChicken(M));

  return 0;
}