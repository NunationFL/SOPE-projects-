#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "funcs.h"

bool all=false, bytes=false, dereference=false, separate=false;
int blockSize=0, maxDepth=0;

int main(int argc, char **argv, char **envp)
{
  if(argc<3){
  	printf("Insufficient arguments.\nUsage: simpledu -l [path] [-a] [-b] [-B size] [-L] [-S] [--max-depth=N]\nOrder isn't important\n");
	exit(1);  
  }
  if(invalidArgs(argv,argc)){
  	printf("Bad arguments.\nUsage: simpledu -l [path] [-a] [-b] [-B size] [-L] [-S] [--max-depth=N]\nOrder isn't important\n");
  	exit(2);
  }
  printf("%i\n",maxDepth);
}