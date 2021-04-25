#include <iostream>
#include <algorithm>
// #include <cmath>

using namespace std;

long long x, y, init_z;

//뭐, 이렇게 binary search로 풀어도 되지만.
int game(long long left, long long right)
{
  int res = -1;
  while (left <= right)
  {
    int mid = (left + right) / 2;
    int temp_z = (100 * (y + mid)) / (x + mid);
    if (temp_z > init_z)
    {
      res = mid;
      right = mid - 1;
    }
    else
    {
      left = mid + 1;
    }
  }
  return res;
}

int main()
{
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> x >> y;
  init_z = (100 * y) / x;

  long long result = (init_z >= 99) ? -2 : (((x % (99 - init_z)) == 0) ? (x / (99 - init_z)) : ((x / (99 - init_z)) + 1));
  cout << game(0, result + 1) << "\n";
  return 0;
}