#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

main()
{
	struct sockaddr_in  server;
	int socket_id,index2,number_limit;
	int read_Buf[100],send_Buf[100];
	socket_id = socket(AF_INET,SOCK_STREAM,0);
	server.sin_family = AF_INET;
	server.sin_port = 4099;
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	connect(socket_id,(struct sockaddr *)&server,sizeof server);
	while(strcmp(read_Buf,"bye")!=0)
	{
		printf("\nClient::");
		printf("\n=>	Enter the limit of number::");
		scanf("%d",&number_limit);
		printf("\n=>	Enter the numbers::\n");
		for(index2 = 0;index2<number_limit;index2++)
		{
			scanf("%d",&send_Buf[index2]);
		}
		send(socket_id,send_Buf,100*sizeof(int),0);
		sleep(3);
		recv(socket_id,read_Buf,100*sizeof(int),0);
		printf("\nPrime numbers are::");
		for(index2 = 0;index2!='\0';index2++)
		{
			printf("\n%d",read_Buf[index2]);
		}
	}
	close(socket_id);
}

