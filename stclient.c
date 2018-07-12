#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
struct student
{
	int roll;
	char name[20];
	int s1,s2,s3,tot;
}s[10];
main()
{
	struct sockaddr_in client,server;
	int ifd,l,a[10],confid,i,num;
	ifd=socket(AF_INET,SOCK_STREAM,0);
	server.sin_family=AF_INET;
	server.sin_port=2006;
	server.sin_addr.s_addr=inet_addr("127.0.0.1");
	printf(".......Client Ready .......\n");
	connect(ifd,(struct sockaddr *)&server,sizeof server);
	printf("enter the number of students");
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		printf("rollno");
		scanf("%d",&s[i].roll);
		printf("name");
		scanf("%s",s[i].name);
		printf("mark1");
		scanf("%d",&s[i].s1);
		printf("mark1");
		scanf("%d",&s[i].s2);
		printf("mark1");
		scanf("%d",&s[i].s3);
	}
	//for(i=0;i<1;i++)
	//scanf("%d %d %d %d",&s[i].roll &s[i].s1 &s[i].s2 &s[i].s3);
	//for(i=0;i<1;i++)
	//printf("%d %d %d %d",s[i].roll s[i].s1 s[i].s2 s[i].s3);
	/*send to server*/
	//for(i=0;i<1;i++)
	send(ifd,&num,sizeof(num),0);
	send(ifd,&s,sizeof(s),0);/* receiving from serevr*/
	recv(ifd,&s,sizeof(s),0);
	printf("received record from server");
	printf("\n rollno\tname\ts1\ts2\ts3\t total\n");
	for(i=0;i<num;i++)
	{
		printf("\n%d\t %s\t %d\t%d\t%d\t%d\n",s[i].roll,s[i].name,s[i].s1,s[i].s1,s[i].s1,s[i].tot);
	}
	close(ifd);
}
