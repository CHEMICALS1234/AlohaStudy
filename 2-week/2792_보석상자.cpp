#include <iostream>
#include <algorithm>

using namespace std;

int n, m;

long long parametric_search(int left, int right, int arr[])
{
  long long res = right;
  while (left <= right)
  {
    long long mid = (left + right) / 2;
    long long howmany = 0;
    for (int i = 0; i < m; i++)
    {
      howmany += arr[i] % mid == 0 ? arr[i] / mid : arr[i] / mid + 1;
    }
    if (howmany > n)
    {
      left = mid + 1;
    }
    else
    {
      if (res >= mid)
      {
        res = mid;
      }
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
  int max = 0;
  cin >> n >> m;
  int arr[m];
  for (int i = 0; i < m; i++)
  {
    cin >> arr[i];
    max = arr[i] > max ? arr[i] : max;
  }

  cout << parametric_search(1, max + 1, arr);

  return 0;
}