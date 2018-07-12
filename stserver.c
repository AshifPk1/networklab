#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/stat.h>
struct student
{
	int roll;
	char name[20];
	int s1,s2,s3,tot;
}s[10],temp;
main()
{
	struct sockaddr_in client,server;
	int ifd,n,n1,confid,i,num;
	ifd=socket(AF_INET,SOCK_STREAM,0);
	server.sin_family=AF_INET;
	server.sin_port=2006;
	server.sin_addr.s_addr=inet_addr("127.0.0.1");
	bind(ifd,(struct sockaddr *)&server,sizeof server);
	listen(ifd,1);
	n=sizeof client;
	confid=accept(ifd,(struct sockaddr *)&client,&n);
	recv(confid,&num,sizeof num,0);
	recv(confid,&s,sizeof s,0);
	printf("received record from client ");
	printf("\n rollno\tname\ts1\ts2\ts3\t total\n");
	for(i=0;i<num;i++)
	{
		s[i].tot=s[i].s1+s[i].s2+s[i].s3;
		printf("\n%d\t %s\t %d\t%d\t%d\t%d\n",s[i].roll,s[i].name,s[i].s1,s[i].s1,s[i].s1,s[i].tot);
	}
	send(confid,&s,sizeof(s),0);
	close(confid);
	close(ifd);
}
