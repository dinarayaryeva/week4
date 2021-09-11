
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
  int n = 20;
  int pid = fork();
    
    if (pid == 0)
        printf("Hello from Child [%d - %d]\n", pid, n);
  
    else
        printf("Hello from Parent [%d - %d]\n", pid , n);
    return 0;
}