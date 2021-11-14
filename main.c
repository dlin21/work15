#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

char ** parse_args( char * line){
  
  // argument array
  char ** args = malloc(5 * sizeof(char*));
  // command
  char * comm;

  int i = 0;
  while(line){
    comm = strsep(&line, " ");
    args[i] = comm;
    i++;
  }

  return args;
}

int main(){
  char in[100] = "ls -a -l";
  char ** args = parse_args(in);
  // execvp(path, argument_array)
  // argument array: array of strings containing arguments to the command
  execvp(args[0], args);

  return 0;
}