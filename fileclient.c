#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
//#include<sys/stat.h>
main()
{
	FILE *fp;
	struct sockaddr_in client,server;
	int ifd,l,confid,i;
	char c,a[500],b[500];
	ifd=socket(AF_INET,SOCK_STREAM,0);
	server.sin_family=AF_INET;
	server.sin_port=3336;
	server.sin_addr.s_addr=inet_addr("127.0.0.1");
	printf(".......Client Ready .......\n");
	connect(ifd,(struct sockaddr *)&server,sizeof server);
	//fp=fopen("fdata","r");
	/*while((c=getc(fp)!=EOF))
	  {
	  puts(c);
	  }
	  fread(fdata,1000,1,fp);
	//puts(fdata);
	/*send to server*/
	fp=fopen("data.c","r");
	fread(a,sizeof(a),1,fp);
	//fclose(fp);
	printf("from server \n");
	send(ifd,a,sizeof(a),0);
	fclose(fp);
	recv(ifd,b,sizeof(b),0);
	printf("%s",b);
	close(ifd);
}
