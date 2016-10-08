/* File: break.c */
#include "stdio.h"

int main(int argc, const char* argv[])
{
  int a=4, b=8, c=0;
  printf ("a=%d, b=%d, c=%d\n", a, b, c);

  c = a > b ? a : b;
  printf ("c = max(a,b) = %d\n", c);

  c = a + b;
  printf ("c = a + b = %d\n", c);

  return 0;
}
