#include "../../include/unp.h"

int
main(int argc, char **argv) {
	int 	listenfd, connfd, udpfd, nready, maxfd;
	struct 	sockaddr_in servaddr, cliaddr;
	char 	msg[MAXLINE];
	ssize_t n;
	socklen_t len;
	pid_t 	childpid;
	const int on = 1;

	void sig_chld(int);

	fd_set rset;

	listenfd = Socket(AF_INET, SOCK_STREAM, 0);
	
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(SERV_PORT);
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

	Setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
	Bind(listenfd, (SA *)&servaddr, sizeof(servaddr));

	Listen(listenfd, LISTENQ);

	udpfd = Socket(AF_INET, SOCK_DGRAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(SERV_PORT);
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

	Bind(udpfd, (SA *)&servaddr, sizeof(servaddr));

	Signal(SIGCHLD, sig_chld);

	FD_ZERO(&rset);
	maxfd = max(listenfd, udpfd) + 1;
	for ( ; ; ) {
		FD_SET(listenfd, &rset);
		FD_SET(udpfd, &rset);

		if ( (nready = select(maxfd, &rset, NULL, NULL, NULL)) < 0) {
			if (errno == EINTR)
				continue;
			else
				err_sys("select error!");
		}

		if (FD_ISSET(listenfd, &rset)) {
			len = sizeof(cliaddr);
			connfd = Accept(listenfd, (SA *)&cliaddr, &len);

			if ( (childpid = Fork()) == 0) {
				Close(listenfd);
				str_echo(connfd);
				exit(0);
			}
			Close(connfd);
		}

		if (FD_ISSET(udpfd, &rset)) {
			len = sizeof(cliaddr);
			n = Recvfrom(udpfd, msg, MAXLINE, 0, (SA *)&cliaddr, &len);
			Sendto(udpfd, msg, n, 0, (SA *)&cliaddr, len);
		}
	}
}
