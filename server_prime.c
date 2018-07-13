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
	int socket_id, n, data_socket,index,index1,flag = 0, number_limit=0, i, j, k =0;
	int read_Buf[100],send_Buf[100], send2_Buf[100];
	socket_id = socket(AF_INET,SOCK_STREAM,0);
	server.sin_family = AF_INET;
	server.sin_port = 3339;
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	bind(socket_id,(struct sockaddr *)&server,sizeof server);
	listen(socket_id,1);
	printf("\n=>	SERVER READY, WAITING FOR CLIENT..........\n");
	n = sizeof client;
	data_socket = accept(socket_id,(struct sockaddr *)&client,&n);
	recv(data_socket,&number_limit,sizeof number_limit,0);
	printf("%d\n",number_limit );
	recv(data_socket,&read_Buf, sizeof read_Buf,0);
	printf("Number array recived from client::\n");
	for(i =0;i<number_limit;i++){
		printf("%d\n",read_Buf[i] );
	}
	for(i = 0; i < number_limit; i++)
	{
		for(j = 2; j < read_Buf[i]/2; j++)
		{
			if(read_Buf[i]%j == 0)
			{
				flag = 1;
				break;	
			}
		}
		if(flag == 0)
		{
			send2_Buf[k]= read_Buf[i];
			k++;
		}
		flag = 0;
	}
	int l=k-1;
	send(data_socket,&l,sizeof l,0);
	send(data_socket,&send2_Buf,sizeof send_Buf,0);
	close(data_socket);
	close(socket_id);
}

