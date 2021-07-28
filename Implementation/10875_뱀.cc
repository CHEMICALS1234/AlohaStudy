#include <iostream>
#include <vector>
#include <algorithm>

#define FAST                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);

using namespace std;

class Line {
  int x1, y1, x2, y2;
  int direction;

 public:
  Line() {}
  Line(int x1, int y1, int x2, int y2) {}
};
