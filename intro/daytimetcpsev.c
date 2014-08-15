#include "../lib/unp.h"
#include <time.h>

int main(int argc, char **argv) 
{
	int 		listenfd, connfd;
	struct sockaddr_in serveraddr;
	char		buff[MAXLINE];
	time_t		ticks;

	listenfd = Socket(AF_INET, SOCK_STREAM, 0);

	bzero(&serveraddr, sizeof(serveraddr));

	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serveraddr.sin_port = htons(13);

	Bind(listenfd, (SA *)&serveraddr, sizeof(serveraddr));

	Listen(listenfd, LISTENQ);

	for(;;)
	{
		connfd = Accept(listenfd, (SA *)NULL, NULL);

		ticks = time(NULL);
		printf("a client is connected!");
		snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
		Write(connfd, buff, strlen(buff));

		Close(connfd);
	}

	exit(0);
}
