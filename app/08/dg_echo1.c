#include "../../include/unp.h"
void 
dg_echo(int sockfd, SA *pcliaddr, socklen_t clilen) {
	int 	n;
	socklen_t len;
	char 	msg[MAXLINE];
	for ( ; ; ) {
		len = clilen;
		n = Recvfrom(sockfd, msg, MAXLINE, 0, pcliaddr, &len);
		Sendto(sockfd, msg, n, 0, pcliaddr, len);
	}
}

