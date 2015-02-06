#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/ip.h>
int main(void){
	int sfd,cfd,lfd, accept_socket;
	char buff[100],str[100];

	struct sockaddr_in server_addr;
	socklen_t server_addr_size;

	sfd = socket(AF_INET,SOCK_STREAM,0);
	printf("the vale of sfd : %d\n",sfd);

	memset(&server_addr, 0, sizeof(struct sockaddr_in));

	int portno = 9001;
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons(portno);

	cfd = bind(sfd, (const struct sockaddr *)&server_addr,sizeof(server_addr));
	printf("the value of cfd : %d\n",cfd);

	lfd = listen(sfd, 50);
	printf("the value of lfd : %d\n",lfd);

	server_addr_size = sizeof server_addr;
	
	accept_socket = accept(sfd, (struct sockaddr *)&server_addr,&server_addr_size);
	printf("the value of accept_socket : %d\n",accept_socket);
	while(1){
		recv(accept_socket,buff,1024,0);
		int i = 0;
		char temp;
		int j = strlen(buff) - 1;
		while (i < j) {
			temp = buff[i];
			buff[i] = buff[j];
			buff[j] = temp;
			i++;
			j--;
		}
		send(accept_socket,buff,13,0);
	}
	
	return 0;
}