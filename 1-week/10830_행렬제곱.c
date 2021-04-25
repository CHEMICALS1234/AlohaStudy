#include <stdio.h>

int n;

void calcMatrix(int arr[n][], int copy_arr[n][], int b)
{
  int temp[n][n];
  if (n > 1)
  {
    calcMatrix(arr, copy_arr, b / 2);
  }

  if (n == 1)
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        // temp[i][j] = arr[i][j];
      }
    }
  }
}

int main()
{
  int b = 0;
  scanf("%d %d", &n, &b);

  int arr[n][n];
  // int temp_arr[n][n];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      scanf("%d", &arr[i][j]);
    }
  }

  return 0;
}