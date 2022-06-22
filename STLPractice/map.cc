#include <iostream>
#include <map>
#include <string>

#define endl "\n"

using namespace std;

template <typename T, typename U>
void printMap(const map<T, U> m) {
  for (auto i : m) {
    cout << i.first << " " << i.second << "\n";
  }
}

int main() {
  map<int, string> m;

  m.insert({1, "유성민"});
  m.insert({3, "acc"});
  m.insert({2, "asdf"});
  m.insert({8, "fes"});
  m.insert({6, "webw"});

  cout << (m.find(4) != m.end()) << endl;

  printMap(m);

  return 0;
}