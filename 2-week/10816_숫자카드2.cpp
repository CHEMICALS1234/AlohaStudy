// 그냥 무식하게 하면 시간초과가 남.

// #include <iostream>
// #include <algorithm>

// using namespace std;

// int n;

// int bin_card(int left, int right, int value, int arr[])
// {
//   while (left <= right)
//   {
//     int count = 0;
//     int mid = (left + right) / 2;
//     if (value > arr[mid])
//     {
//       left = mid + 1;
//     }
//     else if (value < arr[mid])
//     {
//       right = mid - 1;
//     }
//     else
//     {
//       int i = 0;
//       while (value == arr[mid + i])
//       {
//         count++;
//         i++;
//       }
//       i = -1;
//       while (value == arr[mid + i])
//       {
//         count++;
//         i--;
//       }
//       return count;
//     }
//   }
//   return 0;
// }

// int main()
// {
//   cin.tie(0);
//   ios_base::sync_with_stdio(false);

//   cin >> n;
//   int arr[n];
//   for (int i = 0; i < n; i++)
//   {
//     cin >> arr[i];
//   }
//   sort(arr, arr + n);
//   int m, key;
//   cin >> m;
//   for (int i = 0; i < m; i++)
//   {
//     cin >> key;
//     cout << bin_card(0, n - 1, key, arr) << " ";
//   }

//   return 0;
// }

#include <iostream>
#include <algorithm>

using namespace std;

int n;

int main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  int m, key;
  cin >> m;
  for (int i = 0; i < m; i++)
  {
    cin >> key;
    cout << upper_bound(arr, arr + n, key) - lower_bound(arr, arr + n, key) << " ";
  }

  return 0;
}