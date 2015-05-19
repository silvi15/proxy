#ifndef _PROXY_H_

	#define _PROXY_H_

	#include <stdio.h>
	#include <unistd.h>
	#include <errno.h>
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <fcntl.h>
	#include <string.h>
	#include <stdlib.h>
	#include <sys/wait.h>
	#include <sys/socket.h>
	#include <netinet/in.h>
	#include <netdb.h>
	#include <arpa/inet.h>
	#include <sys/shm.h>
	#include <sys/mman.h>
	#include <sys/wait.h>
	#include <semaphore.h>
	#include <sys/ioctl.h> 

	// estas variables definidas, son para: parseurl.c
	#define ERRVAL -1  
	#define DEFAULT_PORT 80
	#define PUERTO_CLIENTE "8080" /* Es el puerto en el que escuchará mi cliente intermedio */
	#define DEBUG 0	 

	typedef struct url_data {
	  char* url;
	  char* protocol;
	  char* hostname;
	  char* path;
	  int port;
	} url_data_t;

	int hijo(int sdtc);

	
#endif
