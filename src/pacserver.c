#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/signal.h>
#include "socklib.h"

#ifndef CONFDIR
	#define PACKAGE_NAME "PAC Server"
	#define PACKAGE_VERSION "alpha"
	#define CONFDIR "./"
#else
	#include "config.h"
#endif

const char * PAC_FILE = "pac.txt";
void read_til_crnl(FILE *fp);
void process_rq(int fd );
void header(FILE *fp, int content_len);
void release(int sig){
	int status;
	while(wait3(&status, WNOHANG, (struct rusage*)0))
		;
}

int main(int args, char * argv[]){
	int sock, fd, port;
	FILE *fpin;
	char	request[BUFSIZ];
	printf("%s %s (%s %s) \n"
			"Copyright (C) 2014 Jakes Lee, GKC.Asia\n"
			"This is free software; see the source for copying conditions.  There is NO\n"
			"warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n\n"
			, PACKAGE_NAME, PACKAGE_VERSION, __DATE__, __TIME__);
	if(args == 1){
		port = 9999;
	}else
		port = atoi(argv[1]);
	if(chdir(CONFDIR) == -1){
		printf("Error configuration path.\n");
		return 1;
	}
	printf("Changed PWD to %s.\n",CONFDIR );
	sock = make_server_socket(port);
	signal(SIGCHLD, release);
	if(sock == -1)
		return 2;
	printf("PAC File Host Server has started at port %d.\n", port);
	while(1){
		fd = accept(sock, NULL, NULL);
		fpin = fdopen(fd, "r" );
		if(fgets(request,BUFSIZ,fpin) > 0){
			printf("Request: %s\n", request);
			read_til_crnl(fpin);
			process_rq(fd);
		}
		fclose(fpin);
	}

}

/* ------------------------------------------------------ *
   read_til_crnl(FILE *)
   skip over all request info until a CRNL is seen
   ------------------------------------------------------ */

void read_til_crnl(FILE *fp){
	char	buf[BUFSIZ];
	while( fgets(buf,BUFSIZ,fp) != NULL && strcmp(buf,"\r\n") != 0 )
		;
}

/* ------------------------------------------------------ *
   process_rq( int fd )
   do what the request asks for and write reply to fd 
   handles request in a new process
   ------------------------------------------------------ */

void process_rq(int fd){
	char	 pac_content[BUFSIZ];
	FILE * fdp, * fp;
	struct stat info;
	/* create a new process and return if not the child */
	if ( fork() != 0 )
		return;
	fdp = fdopen(fd, "w");
	if(stat(PAC_FILE, &info)  < 0){
		exit(3);
	}

	header(fdp, info.st_size);
	fp = fopen(PAC_FILE, "r");
	while(! feof(fp)){
		if(fgets(pac_content, BUFSIZ, fp) >0 || feof(fp))
			fputs(pac_content, fdp);
	}
	printf("Responsed\n");
	fclose(fp);
	fclose(fdp);
}

/* ------------------------------------------------------ *
   the reply header thing: all functions need one
   ------------------------------------------------------ */

void header( FILE *fp, int content_len ){
	fprintf(fp, "HTTP/1.0 200 OK\r\n"
			"Server: PAC Server\r\n"
			"Content-Type: application/x-ns-proxy-autoconfig\r\n"
			"Content-Length: %d\r\n"
			"Connection: Close\r\n\r\n",  content_len);
}
