#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b)
{
  return (*(int *)a - *(int *)b);
}

int main()
{
  int dwarf[9] = {};
  int total = 0;
  for (int i = 0; i < 9; i++)
  {
    scanf("%d", &dwarf[i]);
    total += dwarf[i];
  }

  for (int i = 0; i < 9; i++)
  {
    for (int j = i + 1; j < 9; j++)
    {
      if (total - (dwarf[i] + dwarf[j]) == 100)
      {
        dwarf[i] = 0;
        dwarf[j] = 0;
        qsort(dwarf, 9, sizeof(int), cmpfunc);
        for (int k = 2; k < 9; k++)
        {
          printf("%d\n", dwarf[k]);
        }
        return 0;
      }
    }
  }
}