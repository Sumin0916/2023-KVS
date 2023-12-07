#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include"kvs.h"

const int MAXLINE = LINE_LENGTH;

int main(int argc, char** argv) 
{
   int clientfd, port;
   struct sockaddr_in serveraddr;

   FILE *file = fopen("cluster004_web.trc", "r");
   FILE *resultFile = fopen("answer.dat", "w");
    if (file == NULL||resultFile == NULL) {
        perror("Error opening file");
        return 1;
   }

   char *host, buf[MAXLINE];

   host=  argv[1];
   port = atoi(argv[2]);

   if ((clientfd = socket(AF_INET, SOCK_STREAM, 0))<0){
      perror("socket");
      exit(1);
   }

   serveraddr.sin_family = AF_INET;
   serveraddr.sin_port = htons((unsigned short) port);
   serveraddr.sin_addr.s_addr = inet_addr(host);
   
   if(connect(clientfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr))<0){
      perror("Connect");
      exit(1);
   }

   int wbytes;
   
   while(fgets(buf, LINE_LENGTH, file) != NULL){
      wbytes = write(clientfd, buf, strlen(buf));
      if (wbytes < strlen(buf))
         printf("Failed to send message\n");

      memset(buf, 0, LINE_LENGTH);
      read(clientfd, buf, MAXLINE);
      fprintf(resultFile, "%s\n", buf);
   }
   fclose(resultFile);
   close(clientfd);
   return 0;

   return 0;

}

