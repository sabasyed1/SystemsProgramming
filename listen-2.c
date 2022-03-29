//saba syed
//mathew chua
//lab 8


#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>

// variables
struct sigaction mysignal;
char *myfifo;
char *myrecording;
char *user;
char *theargs[5];
FILE *fp;
void tospeak ()
{
  
  execvp(theargs[0], theargs);
}

int main(char* argcListen, char *argvListen[])
{
  user=argvListen[1];
  myfifo=argvListen[2];
  myrecording=argvListen[3];
  theargs[0]="./speak";
  theargs[1]=user;
  theargs[2]=myfifo;
  theargs[3]=myrecording;
  theargs[4]=NULL;

  char command[128];
  strcpy(command,"ps -ef | egrep 'listen|speak' "); 
  system(command);

  mysignal.sa_handler=tospeak;
  mysignal.sa_flags = SA_NODEFER |SA_RESETHAND ;
  sigaction(SIGTSTP, &mysignal, NULL);
	
 
  while (1)
  {
      printf("You are listening!!!\n\n");
      sleep(2);
      fp = fopen(myrecording, "a");
      fprintf(fp, "You are listening!!!\n\n");
      fclose(fp);


  }
}