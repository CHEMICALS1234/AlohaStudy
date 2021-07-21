#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a_, const void *b_)
{
  return (*(int *)a_ - *(int *)b_);
}

int main()
{
  int n, total = 0;
  scanf("%d", &n);
  int a[n];
  int b[n];
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  for (int i = 0; i < n; i++)
    scanf("%d", &b[i]);

  qsort(a, n, sizeof(int), cmpfunc);
  qsort(b, n, sizeof(int), cmpfunc);

  for (int i = 0; i < n; i++)
  {
    total += (a[i] * b[n - i - 1]);
  }
  printf("%d", total);
}