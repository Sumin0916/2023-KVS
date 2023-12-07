#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include"kvs.h"

const int LISTENQ = LINE_LENGTH;
const int MAXLINE = LINE_LENGTH;

int main(int argc, char **argv) 
{
   kvs_t* kvs = open_kvs();
   int listenfd, connfd, port;
   socklen_t clientlen;
   struct sockaddr_in serveraddr, clientaddr;
   char buf[MAXLINE];
   
   if ((listenfd = socket(AF_INET, SOCK_STREAM, 0))<0){
      perror("socket");
      exit(-1);
   }

   port = atoi(argv[1]);
   serveraddr.sin_family = AF_INET;
   serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
   serveraddr.sin_port = htons((unsigned short)port);

   if (bind(listenfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) ==-1){
      perror("Failed ot bind");
      return -1;
   }

   if (listen(listenfd, LISTENQ)<0)
      return -1;
   
   printf("Waiting for request ... \n");

   clientlen = sizeof(clientaddr);

   if ((connfd = accept(listenfd, (struct sockaddr*)&clientaddr, &clientlen))<0){
      perror("accept");
      exit(-1);
   }

   char * caddrp = inet_ntoa(clientaddr.sin_addr);
   printf("Connected to %s\n", caddrp);

   int n;
   while(1){
      n = read(connfd, buf, MAXLINE);
      if (n==0 || n==-1) break;

      const char* operation = strtok(buf, ",");
      int key = (int)atoi(strtok(NULL, ",")+5);
      const char* value = strtok(NULL, ",");

      if(strcmp(operation, "get") == 0){
         char *res = get(kvs, key);
         write(connfd, res, strlen(res));
      }

      else {
         set(kvs, operation, key, value);
         char res[6];
         sprintf(res, "%ld", strlen(value)-1);
         write(connfd, res, 6);
      }
      memset(buf, 0, LINE_LENGTH);
   }
   close_kvs(kvs);
   return 0;
}