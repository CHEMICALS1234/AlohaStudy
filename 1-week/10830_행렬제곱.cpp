#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef vector<vector<int>> matrix;

int n;

void mul(matrix &ans, matrix &arr)
{
  matrix temp(n, vector<int>(n));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      for (int k = 0; k < n; k++)
      {
        temp[i][j] += (ans[i][k] * arr[k][j]);
      }
      temp[i][j] %= 1000;
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      ans[i][j] = temp[i][j];
    }
  }
}

int main()
{
  long long b;
  cin >> n >> b;
  matrix arr(n, vector<int>(n));
  matrix ans(n, vector<int>(n));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> arr[i][j];
    }
    ans[i][i] = 1;
  }

  while (b > 0)
  {
    if (b % 2 == 1)
    {
      mul(ans, arr);
    }
    mul(arr, arr);
    b /= 2;
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}