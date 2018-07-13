/* UDP PROGRAM : LIST SORTING -CLIENT */
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/stat.h>
main()
{
	struct sockaddr_in server;
	int ifd,n, a[10],i,l,b[10],k;
	ifd=socket(AF_INET,SOCK_DGRAM,0);
	server.sin_family=AF_INET;
	server.sin_port=2001;
	server.sin_addr.s_addr=inet_addr("127.0.0.1");
	printf(".......Client Ready .......\n");
	printf("enter the array limit");
	scanf("%d",&l);
	printf("enter the array elements\n");
	for(i=0;i<l;i++)
		scanf("%d",&a[i]);
	n=sizeof server;
	/*send to server*/
	sendto(ifd,&l,sizeof l,0,(struct sockaddr *)&server,n);
	sendto(ifd,&a,sizeof a,0,(struct sockaddr *)&server,n);
	/* received from server */
	//recvfrom(ifd,&l,sizeof(l),0,(struct sockaddr *)&server,&n);
	recvfrom(ifd,&b,sizeof(b),0,(struct sockaddr *)&server,&n);
	printf(" Sorted List \n");
	for(i=0;i<l;i++)
		printf("%d ",b[i]);
	close(ifd);
}
