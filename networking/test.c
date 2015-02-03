#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <string.h>


int main(void){
	int client_socket,client_connect;
	char buff[100],str[100];
	char kou[100];

	struct sockaddr_in server_addr,peer_addr;

	client_socket = socket(AF_INET,SOCK_STREAM,0);
	printf("the socket is connected %d\n",client_socket);

	int portno = 9001;
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons(portno);

	
		client_connect = connect(client_socket,(struct sockaddr *)&server_addr,sizeof(server_addr));
		printf("value of connect %d\n",client_connect);

	while(1){
		printf("enter : ");
		scanf("%s",kou);

		strcpy(buff,kou);
	 	send(client_socket,buff,13,0);

	 	recv(client_socket,buff, 1024, 0);

	 	printf("recv data %s\n",buff);
	 }
	return 0;
}