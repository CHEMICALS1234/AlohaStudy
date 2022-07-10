#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using node_t = ll;
using dist_t = ll;
using vi = vector<int>;
using vll = vector<ll>;

#define all(x) (x).begin(), (x).end()

#define endl "\n"
#define INF 2e18
#define MOD 1'000'000'007

#define MAX_N 20

int N, R;
vi nums(MAX_N + 2, 0);
vector<bool> visited(MAX_N + 2, false);

void printArr() {
  for (int i = 0; i < R; i++) {
    cout << nums[i] << " ";
  }
  cout << endl;
}
void printLine() { cout << "----------------------------" << endl; }
void clr() {
  fill(all(nums), 0);
  fill(all(visited), false);
}
void permutation(int depth) {
  if (depth == R) {
    printArr();
    return;
  }

  for (int i = 1; i <= N; i++) {
    if (visited[i])
      continue;

    visited[i] = true;
    nums[depth] = i;
    permutation(depth + 1);
    visited[i] = false;
  }
}

void repPermutation(int depth) {
  if (depth == R) {
    printArr();
    return;
  }

  for (int i = 1; i <= N; i++) {
    nums[depth] = i;
    repPermutation(depth + 1);
  }
}

void combination(int depth, int next) {
  if (depth == R) {
    printArr();
    return;
  }

  for (int i = next; i <= N; i++) {
    nums[depth] = i;
    combination(depth + 1, i + 1);
  }
}

void repCombination(int depth, int next) {
  if (depth == R) {
    printArr();
    return;
  }

  for (int i = next; i <= N; i++) {
    nums[depth] = i;
    repCombination(depth + 1, i);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vi nums;

  cin >> N >> R;
  printLine();
  permutation(0);
  clr();

  printLine();
  repPermutation(0);
  clr();

  printLine();
  combination(0, 1);
  clr();

  printLine();
  repCombination(0, 1);
  clr();

  return 0;
}