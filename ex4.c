#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

extern char **environ;

int main()
{
  printf("Enter your bash command\n");

  char command[256]; //command buffer

  fgets(command, 256, stdin); //getting command

  char *args[256]; //command arguments buffers
  
  char str[256] = {0}; // clear command buffer

  for (int i=0; i<strlen(command)-1; i++){
    str[i] = command[i]; //the purpose of this is \n in the end
  }

  int index = 0; //index of the argument in args

  char b[128] = {0}; //temporary variable
  args[0] = b; //initialization

  for (int i=0; i<strlen(str); i++){

     if (str[i]==' ') { //if new argument in command

       index++;
       char c[128] = {0}; //temporary variable
       args[index] = c;

     }
     else { //continue reading the argument
      char c = str[i];
      strncat(args[index], &c, 1);
     }
  }
  index++;
  args[index] = NULL; //adding null argument in the end

  int pid = fork();
  if (pid==0){ //child process
  execvp(args[0], args); 
  }

  return 0;
}