#include <iostream>
#include <algorithm>

using namespace std;

int bin_search(int left, int right, int value, int arr[])
{
  while (left <= right)
  {
    int mid = (left + right) / 2;
    if (value > arr[mid])
    {
      left = mid + 1;
    }
    else if (value < arr[mid])
    {
      right = mid - 1;
    }
    else
      return 1;
  }
  return 0;
}

int main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int n, m, key;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  sort(arr, arr + n);

  cin >> m;
  for (int i = 0; i < m; i++)
  {
    cin >> key;
    cout << bin_search(0, n - 1, key, arr) << "\n";
  }

  return 0;
}