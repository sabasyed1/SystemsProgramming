// Saba Syed
// Mathew chua
// lab 8

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>

//saba: declaration of variables
FILE *fp;
char *myfifo = "chuaFifo.fifo";
char *myrecording = "recording.out";
char *theargs[5];
char *user;

int main(int argc, char *argv[])
{
  system("clear");

  if(argc < 2)
  {
    printf("NOTE: \"username on phone\"\n");
    exit(1);
  }

  user = argv[1];
  theargs[0] = "./listen";
  theargs[1] = user;
  theargs[2] = myfifo;
  theargs[3] = myrecording;
  theargs[4] = NULL;
	
  // asks user
  fp = fopen(myrecording, "a");
  fprintf(fp, "Hello, How can I help you? %s\n", user);
  fprintf(fp, "NOTE: This call will be recorded\n");
  fclose(fp);
  printf("Hello, How can I help you? %s\n", user);
  printf("NOTE: This call will be recorded\n");

  char command[128];
  strcpy(command,"ps -ef | egrep 'listen|speak' "); 
  system(command);

  execvp(theargs[0], theargs);
}