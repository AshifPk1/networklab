#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
main()
{
	struct sockaddr_in client,server;
	int ifd,n,l,confid,k=0;
	char b[500],a[500];
	FILE *fp;
	ifd=socket(AF_INET,SOCK_STREAM,0);
	server.sin_family=AF_INET;
	server.sin_port=3336;
	server.sin_addr.s_addr=inet_addr("127.0.0.1");
	bind(ifd,(struct sockaddr *)&server,sizeof server);
	printf("........Server Ready waiting......\n");
	listen(ifd,5);
	n=sizeof client;
	confid=accept(ifd,(struct sockaddr *)&client,&n);
	printf("from client\n");
	/*recevinf from client*/
	recv(confid,b,sizeof(b),0);
	printf("%s",b);
	fp=fopen("data2.c","r");
	fread(a,sizeof(a),1,fp);
	//fclose(fp);
	send(confid,a,sizeof(a),0);
	printf("the file has been transferred");
	fclose(fp);
	//send(confid,&a,sizeof(a),0);*/
	//printf("%s",data1);
	close(confid);
	close(ifd);
}
