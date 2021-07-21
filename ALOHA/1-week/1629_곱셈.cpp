#include <iostream>

using namespace std;

long long a;
long long b;
long long c;

long long mul(long long b)
{
  long long temp;
  if (b > 1)
  {
    temp = mul(b / 2);
  }
  if (b == 1)
  {
    return a;
  }
  else if (b % 2 == 0)
  {
    return (temp * temp) % c;
  }
  else if (b % 2 == 1)
  {
    return ((temp * temp) % c * (a)) % c;
  }
}

int main()
{
  cin >> a >> b >> c;
  a %= c;
  cout << mul(b) % c << endl;
  return 0;
}