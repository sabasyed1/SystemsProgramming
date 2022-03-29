// Saba Syed
// Mathew Chua
// Lab 9 

#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <signal.h>
#include <sys/wait.h>


#define MAX 80 
#define SA struct sockaddr

// saba:Function designed for chat between client and server. 
void func(int sockfd) {
  char buff[MAX];
  int n;
  int messageNo = 0;

  //saba: loop
  while (1) {
    bzero(buff, MAX);
    //read the message from client and copy it in buffer 
    read(sockfd, buff, sizeof(buff));
    //print buffer which contains the client contents 
    printf("From client message #%d: %s\t", messageNo ,buff);
    // Making exit statement case sensitive

if  ((strncmp(buff, "exit", 4)) == 0 || (strncmp(buff, "Exit", 4)) == 0 || (strncmp(buff, "EXIT", 4)) == 0 || (strncmp(buff, "eXit", 4)) == 0 || (strncmp(buff, "exIt", 4)) == 0 || (strncmp(buff, "exiT", 4)) == 0 || (strncmp(buff, "ExIt", 4)) == 0 || (strncmp(buff, "ExiT", 4)) == 0){      
        printf("Server Exit...\n");
	printf("Waiting for new connection...\n");

      exit(0);
    }
    bzero(buff, MAX);
    n = 0;
    // copy server message in the buffer 
    while ((buff[n++] = getchar()) != '\n')
        ;
    // and send that buffer to client 
    write(sockfd, buff, sizeof(buff));
    // if msg contains "Exit" then server exit and chat ended. 
   
  }
}


// mathew: Driver function 
int main(int argc, char *argv[]) {

  int sockfd, connfd, len, newsockfd, pid;
  struct sockaddr_in servaddr, cli;

  //******Code I Changed******//
  if (argc < 2) {
    printf("ERROR, no port provided\n");
    exit(1);
  }
  // clears the screen for better visibility
  system("clear");
  //setting port and checking if the port number is acceptable
  int PORT;
  int port = atoi(argv[1]); 
  if((port >= 1024 && port <= 49151)) {
    PORT = port;

  }
  else {
    printf("You have provided well-known port! Please provide a port which is not well-known and not ephemeral");
    exit(1);
  }


//mathew: socket create and verification 
sockfd = socket(AF_INET, SOCK_STREAM, 0);
if (sockfd == -1){
  printf("socket creation failed...\n");
  exit(0);
}
else {
  printf("Socket successfully created..\n");
  
}
bzero(&servaddr, sizeof(servaddr));

// assign IP, PORT 
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(PORT);

// saba: Binding newly created socket to given IP and verification 
  if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0)
  {
    printf("socket bind failed...\n");
    exit(0);
  }
  else
  {
    printf("Socket successfully binded..\n");
  }
// saba:Now server is ready to listen and verification 
  if ((listen(sockfd, 5)) != 0)
  {
    printf("Listen failed...\n");
    exit(0);
  }
  else
  {
    printf("Server listening..\n");
  char command[128];
  char line[128];

  // copy line 
  sprintf(line,"netstat -ant | grep %d", port); 
  strcpy(command, line);
   // system command to check right port
   system(command);

  }
  len = sizeof(cli);

// mathew: Accept the data packet from client and verification 
while (1) {
     newsockfd = accept(sockfd, 
           (struct sockaddr *) &cli, &len);
     if (newsockfd < 0) 
         printf("ERROR on accept");
     pid = fork();
     if (pid < 0)
         printf("ERROR on fork");
     if (pid == 0)  {
         close(sockfd);
         func(newsockfd);  // Function for chatting between client and server 
         exit(0);
     }
     else close(newsockfd); // After chatting close the socket 
 }
}