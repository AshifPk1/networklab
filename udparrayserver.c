/* UDP PROGRAM : LIST SORTING -SERVER */
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/stat.h>
main()
{
	struct sockaddr_in client,server;
	int ifd,n,lim,a[10],temp,j,i,k;
	ifd=socket(AF_INET,SOCK_DGRAM,0);
	server.sin_family=AF_INET;
	server.sin_port=2001;
	server.sin_addr.s_addr=inet_addr("127.0.0.1");
	bind(ifd,(struct sockaddr *)&server,sizeof server);
	n=sizeof client;
	printf(" Server ready .....\n");
	/*recevinf from client*/
	recvfrom(ifd,&lim,sizeof(lim),0,(struct sockaddr *)&client,&n);
	recvfrom(ifd,&a,sizeof(a),0,(struct sockaddr *)&client,&n);
	printf("recevied list from client :\n");
	for(i=0;i<lim;i++)
		printf("%d ",a[i]);
	for(i=0;i<lim-1;i++)
	{
		for(j=0;j<lim-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	/*send to client*/
	//sendto(ifd,&lim,sizeof lim,0,(struct sockaddr *)&client,n);
	sendto(ifd,&a,sizeof a,0,(struct sockaddr *)&client,n);printf("\n Sorted List at server side :\n");
	for(i=0;i<lim;i++)
		printf("%d ",a[i]);
	close(ifd);
}
