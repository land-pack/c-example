#include <stdio.h>

int v_printf(int arg_count, ...)
{
  int* vl;
  int i_arg, i;

  vl = &arg_count;
  for(i = 0; i < arg_count; i++)
  {
    i_arg = *vl--;
    printf("Argument %d = %d\n", i, i_arg);
  }
  vl = NULL;
  return 0;
}
int main(int argc, char *argv[])
{
  v_printf(2, 1, 2);
  return 0;
}
