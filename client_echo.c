#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

main()
{
	struct sockaddr_in  server;
	int socket_id;
	char read_Buf[100] = "", send_Buf[100] = "";
	socket_id = socket(AF_INET,SOCK_STREAM,0);
	server.sin_family = AF_INET;
	server.sin_port = 4099;
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	connect(socket_id,(struct sockaddr *)&server,sizeof server);
	while(strcmp(read_Buf,"bye")!=0)
	{
		printf("\nClient::");
		gets(send_Buf);
		send(socket_id,send_Buf,sizeof send_Buf,0);
		recv(socket_id,read_Buf,sizeof read_Buf,0);
		printf("\nServer::%s",read_Buf);
	}
	close(socket_id);
}

