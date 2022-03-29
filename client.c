//saba syed
//mathew chua
// lab 9

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX 80 
#define SA struct sockaddr 

void func(int sockfd) {
  char buff[MAX];
  int n;
  int messageNo =0;

    //Saba: loop
  while (1) {
    bzero(buff, sizeof(buff));
    printf("Enter the string : ");
    n = 0;
    while ((buff[n++] = getchar()) != '\n');
    write(sockfd, buff, sizeof(buff));
if  ((strncmp(buff, "exit", 4)) == 0 || (strncmp(buff, "Exit", 4)) == 0 || (strncmp(buff, "EXIT", 4)) == 0 || (strncmp(buff, "eXit", 4)) == 0 || (strncmp(buff, "exIt", 4)) == 0 || (strncmp(buff, "exiT", 4)) == 0 || (strncmp(buff, "ExIt", 4)) == 0 || (strncmp(buff, "ExiT", 4)) == 0){
      printf("Client Exit...\n"); 
      exit(0);
    }
    bzero(buff, sizeof(buff));
    read(sockfd, buff, sizeof(buff));
    messageNo++;
    printf("From Server message #%d: %s",messageNo, buff); // Making exit statement case sensitive
    
  }
}


int main(int argc, char *argv[]) {
  int sockfd, connfd;
  struct sockaddr_in servaddr, cli;

  // Saba
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
    exit(1);  char command[128];
  char line[128];

  // copy line 
  sprintf(line,"netstat -ant | grep %d", port); 
  strcpy(command, line);
   // system command to check right port
   system(command);

  }



//Mathew: socket create and varification 
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1)
  {
    printf("socket creation failed...\n");
    exit(0);
  }
  else
  {
  printf("Socket successfully created..\n");
  }

  bzero(&servaddr, sizeof(servaddr));

// assign IP, PORT 
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  servaddr.sin_port = htons(PORT);
//  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

// mathew: connect the client socket to server socket 
  if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0)
  {
    printf("connection with the server failed...\n");
    exit(0);
  }
  else
  {
    printf("connected to the server..\n");
  }

// function for chat 
  char command[128];
  char line[128];

  // copy line 
  sprintf(line,"netstat -ant | grep %d", port); 
  strcpy(command, line);
   // system command to check right port
   system(command);
  func(sockfd);

// close the socket 
  close(sockfd);
}