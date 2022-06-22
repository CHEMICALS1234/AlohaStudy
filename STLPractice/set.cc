#include <iostream>
#include <set>

using namespace std;

template <typename T>
void printSet(const set<T>& s) {
  for (auto i : s) {
    cout << i;
  }
}

template <typename T, typename U>
void printSetPair(const set<pair<T, U>>& s) {
  for (auto i : s) {
    cout << i.first << " " << i.second << "\n";
  }
}

int main() {
  set<int> s;

  s.insert(10);
  s.insert(500);
  s.insert(20);
  s.insert(30);
  s.insert(10);

  // printSet(s);

  // cout << (s.find(20) != s.end());

  set<pair<int, int>> ps;

  ps.insert({10, 30});
  ps.insert({30, 20});
  ps.insert({10, 20});
  ps.insert({80, 25});
  ps.insert({9, 10});

  printSetPair(ps);

  return 0;
}