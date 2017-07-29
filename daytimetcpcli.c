
#include	<sys/types.h>	/* basic system data types */
#include	<stdio.h>	/* basic system data types */
//#include <sys/socket.h>
#include	<netinet/in.h>	/* sockaddr_in{} and other Internet defns */

#define MAXLINE 4096


int main(int argc,char **argv)
{

	int sockfd,n;
	char recvline[MAXLINE+1];
	struct sockaddr_in servaddr;

	if(argc!=2)
	{
		printf("usage:a.out <IPaddress>\n");
		exit(1);
	}

	if( (sockfd=socket(AF_INET,SOCK_STREAM,0))<0)
		printf("socket error\n");

	printf("sockfd is %d\n",sockfd);


	bzero(&servaddr,sizeof(servaddr) );
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(13);
	if(inet_pton(AF_INET,argv[1],&servaddr.sin_addr)<=0 )
	{
		printf("inet_pton error for %s\n",argv[1]);
		exit(1);
	}

	printf("inet_pton is\n");

	if(connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr) ) <0)
	{
		printf("connect error\n");
	}

	printf("connect is\n");

	while(  (n=read(sockfd,recvline,MAXLINE) )>0  )
	{
		printf("123 connect is\n");
		recvline[n]='\0'; // =0
		if(fputs(recvline,stdout)==EOF)
			printf("fputs error\n");
	}

		printf("ss3 connect is\n");
	if(n<0)
		printf("read error\n");

		printf("456 connect is\n");

	exit(0);
		printf("789 connect is\n");
}


