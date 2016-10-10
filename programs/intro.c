/* File: intro.c */
#include "stdio.h"

void crashme()
{
  int* tmpInt = NULL;

  /* try to force this program to crash */
  *tmpInt = 0;
}

int main(int argc, const char* argv[])
{
  printf("Hello world !\n");

  if (argc > 1)
  {
    crashme();
  }

  printf("Bye this world !\n");

  return 0;
}
