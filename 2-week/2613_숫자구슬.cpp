#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;

void marble_search(int left, int right, int arr[])
{
  int temp_sum = 0, max = 0, mid = 0;
  vector<int> sum_vec;
  int res = right;
  int howmany = 0;
  while (left <= right)
  {
    sum_vec.clear();
    temp_sum = 0;
    max = 0;
    mid = (left + right) / 2;
    for (int i = 0; i < n; i++)
    {
      if (temp_sum + arr[i] <= mid)
      {
        temp_sum += arr[i];
      }
      else
      {
        max = temp_sum > max ? temp_sum : max;
        sum_vec.push_back(temp_sum);
        temp_sum = 0;
        i--;
      }
    }
    if (temp_sum)
    {
      max = temp_sum > max ? temp_sum : max;
      sum_vec.push_back(temp_sum);
    }

    if (sum_vec.size() > m)
    {
      left = mid + 1;
    }
    else if (sum_vec.size() == m)
    {
      if (mid > max)
      {
        right = mid - 1;
      }
      else if (mid == max)
      {
        res = res > mid ? mid : res;
        right = mid - 1;
      }
      else
      {
        left = mid + 1;
      }
    }
    else
    {
      right = mid - 1;
    }
  }
  sum_vec.clear();
  temp_sum = 0;
  cout << res << "\n";
  for (int i = 0; i < n; i++)
  {
    if (temp_sum + arr[i] <= res)
    {
      temp_sum += arr[i];
      howmany++;
    }
    else
    {
      cout << howmany << " ";
      temp_sum = 0;
      howmany = 0;
      i--;
    }
  }
  if (temp_sum)
  {
    cout << howmany << " ";
  }

  cout << "\n";
}

int main()
{
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> n >> m;
  int arr[n];
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    sum += arr[i];
  }
  marble_search(1, sum + 1, arr);
  return 0;
}