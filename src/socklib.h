#include	<stdio.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<netinet/in.h>
#include	<netdb.h>
#include	<time.h>
#include	<strings.h>

#define   HOSTLEN  256
#define	  BACKLOG  1

int make_server_socket_q(int , int );

int make_server_socket();
