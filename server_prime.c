#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
	struct sockaddr_in client, server;
	int socket_id, n, data_socket,index,index1,flag = 0;
	int read_Buf[100],send_Buf[100];
	socket_id = socket(AF_INET,SOCK_STREAM,0);
	server.sin_family = AF_INET;
	server.sin_port = 4099;
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	bind(socket_id,(struct sockaddr *)&server,sizeof server);
	listen(socket_id,1);
	printf("\n=>	SERVER READY, WAITING FOR CLIENT..........");
	n = sizeof client;
	data_socket = accept(socket_id,(struct sockaddr *)&client,&n);
	while(strcmp(send_Buf,"bye")!=0)
	{
		recv(data_socket,read_Buf,100*sizeof(int),0);
		for(index = 0;index!='\0';index++)
		{
			printf("\nCLIENT::%d",read_Buf[index]);
		}
		for(index = 0;index!='\0';index++)
		{
			for(index1 = 2;index1<=read_Buf[index]/2;index1++)
			{
				if(read_Buf[index]%index1==0)
				{
					flag = 1;
					break;
				}
			}
			if(flag == 0)
					send_Buf[index] = read_Buf[index];
			flag = 0;
		}		
		send(data_socket,send_Buf,100*sizeof(int),0);
	}
	close(data_socket);
	close(socket_id);
}

