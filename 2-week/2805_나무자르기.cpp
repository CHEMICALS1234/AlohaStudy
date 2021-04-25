#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;

long long parametric_search(long left, long right, long long len[])
{
  long long res = 0;
  while (left <= right)
  {
    long long howmany = 0;
    long long mid = (left + right) / 2;

    for (int i = 0; i < n; i++)
    {
      howmany += len[i] > mid ? len[i] - mid : 0;
    }

    if (howmany >= m)
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
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  long long arr[n];
  long max = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    max = arr[i] > max ? arr[i] : max;
  }
  cout << parametric_search(0, max + 1, arr) << "\n";

  return 0;
}