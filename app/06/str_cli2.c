#include "../../include/unp.h"

void
str_cli(FILE *fp, int sockfd)
{
	int 	maxfd, stdineof;
	fd_set 	rset;
	char 	buf[MAXLINE];
	int		n;

	stdineof = 0;
	FD_ZERO(&rset);
	for ( ; ; ) {
		if (stdineof == 0)
			FD_SET(fileno(fp), &rset);
		FD_SET(sockfd, &rset);
		maxfd = max(fileno(fp), sockfd) + 1;

		Select(maxfd, &rset, NULL, NULL, NULL);

		if (FD_ISSET(sockfd, &rset)) {
			if ( (n = Read(sockfd, buf, MAXLINE)) == 0) {
				if (stdineof == 1)
					return;
				else 
					err_quit("str_cli:server terminated permaturely");
			}
			Writen(fileno(stdout), buf, n);
		}

		if (FD_ISSET(fileno(fp), &rset)) {
			if ( (n = Read(fileno(fp), buf, MAXLINE)) == 0) {
				stdineof = 1;
				Shutdown(sockfd, SHUT_WR);
				FD_CLR(fileno(fp), &rset);
				continue;
			}
			Writen(sockfd, buf, n);
		}
	}
}
				
				
