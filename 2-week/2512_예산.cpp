#include <iostream>
#include <algorithm>

using namespace std;
int n, m;

int budget(int low, int high, int arr[])
{
  int res = 0;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
      sum += (arr[i] < mid) ? arr[i] : mid;
    }
    if (sum <= m)
    {
      res = mid;
      low = mid + 1;
    }
    else // sum > m
    {
      high = mid - 1;
    }
  }
  return res;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  int arr[n];
  int high = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    if (arr[i] > high)
      high = arr[i];
  }
  sort(arr, arr + n);
  cin >> m;
  cout << budget(0, high, arr) << "\n";
  return 0;
}