#include "stdio.h"

void crashme()
{
  int* tmpInt = NULL;

  /* try to force this program to crash */
  *tmpInt = 0;
}

int main(void) 
{
  printf("Hello world !\n");

  crashme();

  printf("Bye this world !\n");

  return 0;
}
