#include <stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/stat.h>

int main()
{
	FILE *fp;
        struct sockaddr_in server;
        int connection_socket, limit;
	int sBuf[100], rBuf[100];
	int i, k;
        connection_socket = socket(AF_INET,SOCK_STREAM,0);
        server.sin_family = AF_INET;
        server.sin_port = 3336;
        server.sin_addr.s_addr = inet_addr("127.0.0.1");
        connect(connection_socket,(struct sockaddr *)&server,sizeof server);
	printf("\n=> Enter the limit of numbers::");
	scanf("%d",&limit);
	printf("\n=> Enter the numbers::");
	for(i = 0;i < limit; i++)
	{
 		scanf("%d",&sBuf[i]);
	}
	send(connection_socket,&limit,sizeof limit,0);
	send(connection_socket,&sBuf,sizeof sBuf,0);
	recv(connection_socket,&k,sizeof k,0);
	recv(connection_socket,&rBuf,sizeof rBuf,0);
	printf("\n=>	Prime numbers are::\n");
	for(i = 1;i <= k; i++)
        {
                printf("%d",rBuf[i]);
		printf("\n");
        }
	//fp = fopen("data.c","r");
	//fread(sBuf,sizeof(sBuf),100,fp);
	//send(connection_socket,sBuf,sizeof(sBuf),0);
	//recv(connection_socket,rBuf,sizeof(rBuf),0);
	//printf("\n=>	%s",rBuf);
	close(connection_socket);
	
}
