#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

class Frac {
  int num, den;

  int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
  }

 public:
  Frac(int num, int den) {
    int gcdValue = gcd(num, den);
    this->num = num / gcdValue;
    this->den = den / gcdValue;
  }

  Frac operator-(const Frac& frac) const {
    Frac temp(num * frac.den - den * frac.num, den * frac.den);
    return temp;
  }

  Frac& operator=(const Frac& frac) {
    num = frac.num;
    den = frac.den;
    return *this;
  }

  double getReversed() {
    return ceil(static_cast<double>(den) / static_cast<double>(num));
  }

  int getDen() { return den; }

  bool isUnit() { return (num == 1); }

  void printFrac() { printf("%d / %d\n", num, den); }
};

int main() {
  int T;
  scanf("%d", &T);

  for (int t = 0; t < T; t++) {
    int num, den;
    scanf("%d %d", &num, &den);

    Frac original(num, den);

    while (true) {
      if (original.isUnit()) break;
      Frac uni(1, original.getReversed());
      original = (original - uni);
    }

    printf("%d\n", original.getDen());
  }

  return 0;
}