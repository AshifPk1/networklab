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
	int socket_id,index2,number_limit, k, i;
	int read_Buf[100],send_Buf[100], read2_Buf[100];
	socket_id = socket(AF_INET,SOCK_STREAM,0);
	server.sin_family = AF_INET;
	server.sin_port = 3339;
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	connect(socket_id,(struct sockaddr *)&server,sizeof server);
	printf("\n=> Enter the limit of numbers::");
	scanf("%d",&number_limit);
	printf("\n=> Enter the numbers::");
	for(i = 0;i < number_limit; i++)
	{
 		scanf("%d",&send_Buf[i]);
	}
	send(socket_id,&number_limit, sizeof number_limit,0);
	send(socket_id,&send_Buf, sizeof send_Buf,0);
	recv(socket_id,&k, sizeof k,0);
	recv(socket_id,&read2_Buf, sizeof read2_Buf,0);
	printf("\n=>	Prime numbers are::\n");
	for(i = 0;i <= k; i++)
        {
                printf("%d",read2_Buf[i]);
		printf("\n");
        }
	close(socket_id);
}

