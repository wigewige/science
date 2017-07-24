#include <stdio.h>
#include <sys/socket.h>
#include <linux/sockios.h>
#include <linux/if.h>
#include <netinet/in.h>


void main()
{
	int socket_fd;
	struct ifreq if_device;
	int ret;
	int s_addr_value;
	struct sockaddr_in *p_ifr_addr;

	socket_fd=socket(AF_INET,SOCK_STREAM,0);
	if(socket_fd < 0)
	{
		printf("err ,create socket fail,%d\n",socket_fd);
		perror("deatail error info is");
		return;
	}

	printf("create socket succ,socket_fd=%d\n",socket_fd);

	memset(&if_device,0,sizeof(if_device));
	strncpy(if_device.ifr_ifrn.ifrn_name,"eth0",sizeof(if_device.ifr_ifrn.ifrn_name));
	ret=ioctl(socket_fd,SIOCGIFADDR,&if_device);
	if(ret<0)
		printf("ioctl err,ret=%d\n",ret);

	p_ifr_addr=(struct sockaddr_in *)&if_device.ifr_ifru.ifru_addr;
	s_addr_value = (int)p_ifr_addr->sin_addr.s_addr;

	//s_addr_value=p_ifr_addr->sin_addr.s_addr;
	printf("s_addr_value=%#x,s_addr_value=%d\n",s_addr_value,s_addr_value);
	printf("s_addr_value=%s\n",inet_ntoa(*(struct in_addr *)&s_addr_value));

	close(socket_fd);

	//////////////////////////

	//socket_fd=socket(AF_INET,SOCK_STREAM,0);
	socket_fd=socket(AF_INET,SOCK_DGRAM,0);
	if(socket_fd < 0)
	{
		printf("err ,create socket fail,%d\n",socket_fd);
		perror("deatail error info is");
		return;
	}

	printf("create socket succ,socket_fd=%d\n",socket_fd);


	memset(&if_device,0,sizeof(if_device));
	strncpy(if_device.ifr_ifrn.ifrn_name,"lo",sizeof(if_device.ifr_ifrn.ifrn_name));
	ret=ioctl(socket_fd,SIOCGIFADDR,&if_device);
	if(ret<0)
		printf("ioctl err,ret=%d\n",ret);

	p_ifr_addr=(struct sockaddr_in *)(&if_device.ifr_ifru.ifru_addr);
	s_addr_value = (int)p_ifr_addr->sin_addr.s_addr;

	//s_addr_value=p_ifr_addr->sin_addr.s_addr;
	//printf("s_addr_value=%d\n",s_addr_value);
	printf("s_addr_value=%#x,s_addr_value=%d\n",s_addr_value,s_addr_value);
	printf("s_addr_value=%s\n",inet_ntoa(*(struct in_addr *)&s_addr_value));
	//printf("s_addr_value=%s\n",inet_ntoa((struct in_addr *)&s_addr_value));


	close(socket_fd);
	socket_fd=0;
	printf("close socket succ,socket_fd=%d\n",socket_fd);



	return;
}
