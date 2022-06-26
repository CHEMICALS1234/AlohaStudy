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

#define MAXSIZE (2000 + 5)

vector<bool> isPrime(MAXSIZE, true);
vi ASet;
vi BSet;

int N;

void setup() {
  isPrime[1] = false;
  for (int i = 2; i * i < MAXSIZE; i++) {
    if (!isPrime[i])
      continue;

    for (int j = 2 * i; j < MAXSIZE; j += i) {
      isPrime[j] = false;
    }
  }
}

int main() {
  FAST;
  setup();

  cin >> N;

  int temp;
  bool isFirstEven;

  for (int i = 0; i < N; i++) {
    cin >> nums[i];
  }

  return 0;
}