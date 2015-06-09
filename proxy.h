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
	
	typedef struct DATOS{
		char puerto[256];
		char root[256];
	} datos; 
	
	typedef struct URI{
		char archivo[256];
		char extension[256];
		char version[256];
		char mime[256];
		char metodo[256];
		long length;
	} uri;
	
	datos datosConexion;
	uri uriConexion;
	char root[256];

	int hijo (int sdtc);
	uri recuperarURI(char *);
	void parsear (char *buffer,int sdtc, int sdmotion);
	datos argumentos();
	int funcion(char *path);

#endif
