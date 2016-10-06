#include "stdio.h"

int main(void) 
{
  printf("Hello world !\n");
  int* tmpInt = NULL;
  /* try to force hello to crash */
  *tmpInt = 0;

  printf("Bye this world !\n");

  return 0;
}
