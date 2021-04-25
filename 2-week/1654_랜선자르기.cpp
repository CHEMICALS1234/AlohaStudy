#include <iostream>
#include <algorithm>

using namespace std;

int n, k;

long long parametric_search(long left, long right, long long len[])
{
  long long res = 0;
  while (left <= right)
  {
    long long temp_n = 0;
    long long mid = (left + right) / 2;
    for (int i = 0; i < k; i++)
    {
      temp_n += len[i] / mid;
    }
    if (temp_n >= n)
    {
      if (res < mid)
      {
        res = mid;
      }
      left = mid + 1;
    }
    else
    {
      right = mid - 1;
    }
  }
  return res;
}

int main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> k >> n;
  long long len[k];

  for (int i = 0; i < k; i++)
  {
    cin >> len[i];
  }
  cout << parametric_search(0, 2147483647, len);
  return 0;
}