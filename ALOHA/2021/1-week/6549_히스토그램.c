#include <stdio.h>
#include <stdlib.h>

int g_area = 0;

void find_min(int start, int end, int arr[], int *min, int *min_index)
{
  int temp_min = 1000000001;
  int temp_i = 0;
  for (int i = start; i < end; i++)
  {
    if (temp_min > arr[i])
    {
      temp_min = arr[i];
      temp_i = i;
    }
  }
  *min = temp_min;
  *min_index = temp_i;
}

void histo(int start, int end, int arr[], int area)
{
  if (start < end)
  {
    int min = 0;
    int min_index = 0;
    find_min(start, end, arr, &min, &min_index);
    area = area > min * (end - start) ? area : min * (end - start);
    histo(start, min_index, arr, area);
    histo(min_index + 1, end, arr, area);
    if (g_area < area)
    {
      g_area = area;
    }
  }
}

int main()
{
  int n = 0;
  int area_final = 0;
  int storage[100000];
  int howmany = 0;

  while (1)
  {
    scanf("%d", &n);
    if (n == 0)
      break;
    int histo_num[n];
    for (int i = 0; i < n; i++)
      scanf("%d", &histo_num[i]);

    histo(0, n, histo_num, 0);
    storage[howmany] = g_area;
    howmany++;
  }
  for (int i = 0; i < howmany; i++)
  {
    printf("%d\n", storage[i]);
  }
  return 0;
}