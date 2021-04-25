#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char str[60];
  gets(str);
  char temp_str[10] = "";
  char bl = 0;
  int total = 0;

  for (int i = 0; i < 50; i++)
  {
    if (str[i] == '+' || str[i] == '-' || str[i] == '\0')
    {
      total += bl ? -(atoi(temp_str)) : atoi(temp_str);
      //string 초기화에서 에러남.
      memset(temp_str, 0, strlen(temp_str));
      if (str[i] == '-')
        bl = 1;
      if (str[i] == '\0')
        break;
    }
    else
    {
      char str_i[2];
      str_i[0] = str[i];
      str_i[1] = '\0';
      strcat(temp_str, str_i);
    }
  }

  printf("%d\n", total);

  return 0;
}