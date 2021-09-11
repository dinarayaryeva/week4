
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
  printf("Enter your bash command\n");
  char command[256];
  scanf("%s", command);
  system(command);
  
  return 0;
}