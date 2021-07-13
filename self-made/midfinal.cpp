#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_ARR = 987654321;

int n;
int mid[MAX_ARR];
int final[MAX_ARR];

int main() {
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%d", &mid[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &final[i]);
  }

  int myMid, myFinal;
  scanf("%d %d", &myMid, &myFinal);

  return 0;
}