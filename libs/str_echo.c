﻿#include "../include/unp.h"

void str_echo(int sockfd)
{
	ssize_t n;
	char 	buf[MAXLINE];

again:
	while ( (n = recv(sockfd, buf, MAXLINE, 0)) > 0)
	{
		err_sys("recv");
	}

	if (n < 0 && errno == EINTR)
		goto again;
	else if ( n < 0)
		err_sys("str_echo: read error");
}

