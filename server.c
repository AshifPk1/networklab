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
	struct sockaddr_in client, server;
	int connection_socket,communication_socket, n, limit, flag = 0;
	int rBuf[100], sBuf[100], s2Buf[100], i, k = 0, j;
	connection_socket = socket(AF_INET,SOCK_STREAM,0);
	server.sin_family = AF_INET;
	server.sin_port = 3336;
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	bind(connection_socket,(struct sockaddr *)&server,sizeof server);
	printf("\n=>    Server is ready for client.......\n");
	listen(connection_socket,1);
	n = sizeof client;
	communication_socket = accept(connection_socket,(struct sockaddr *)&client,&n);
	recv(communication_socket,&limit,sizeof (limit),0);
	recv(communication_socket,&rBuf,sizeof (rBuf),0);
	printf("Number array recived from client::\n");
	for(i =0;i<limit;i++){
		printf("%d\n",rBuf[i] );
	}
	for(i = 0; i < limit; i++)
	{
		for(j = 2; j < rBuf[i]/2; j++)
		{
			if(rBuf[i]%j == 0)
			{
				flag = 1;
				break;	
			}
		}
		if(flag == 0)
		{
			s2Buf[k]= rBuf[i];
			k++;
		}
		flag = 0;
	}
	int l=k-1;
	send(communication_socket,&l,sizeof l,0);
	send(communication_socket,&s2Buf,sizeof s2Buf,0);
	close(communication_socket);
	close(connection_socket);
}
