// saba syed
// mathew chua
//lab8

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>

//myfifo contains the file name for my fifo
//myrecording contains the file name for recording the conversation
//user is who is speaking or listening
//the array "theargs" passes the previous variables to processes
//message is what the users has typed
//userplusmessage is what is being sent to the user who is reading
//fdw is the file descriptor of the  writing side of the fifo
char *myfifo;
char *myrecording;
char *user;
char *theargs[5];
char  message[80];
int   fdw;
char  userplusmessage[80];
FILE *fp;


void main (char* argcSpeak, char *argvSpeak[])
{
// initialize meaningful variable names from passed arguments
// then populate the parameter array "theargs"
  user=argvSpeak[1];
  myfifo=argvSpeak[2];
  myrecording=argvSpeak[3];
  theargs[0]="./listen";
  theargs[1]=user;
  theargs[2]=myfifo;
  theargs[3]=myrecording;
  theargs[4]=NULL;
// make or ensure their exists a fifo
  mkfifo(myfifo, 0666);

// saba:instruct the user 
  printf("\nType in a Message you want to Send: ");
  fp = fopen(myrecording, "a");
  fprintf(fp,"\nType in a Message you want to Send: ");
  fclose(fp);

// accept the input from the user
  fgets(message, 80, stdin);
// send user input to .out file
  fp = fopen(myrecording, "a");
  fprintf(fp,"%s", message);
  fclose(fp);

// combined the message with user information
  strcpy(userplusmessage, user);
  strcat(userplusmessage, ":");
  strcat(userplusmessage, message);



//mathew: open the fifo in Writing mode (WRONLY)
//then write the message to the writing side of the FIFO using fdw
  fdw=open("/chuaFifo.fifo", O_WRONLY);
  write(fdw, userplusmessage, strlen(userplusmessage)+1);
  printf("sending -> %s \n", userplusmessage);
  close(fdw);
  
  

//go back to listening by overwriting this process (without forking)
  char command[128];
  strcpy(command,"ps -ef | egrep 'listen|speak' "); 
  system(command);
  execvp(theargs[0], theargs);
}