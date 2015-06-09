
#include "proxy.h"

int hijo (int sdtc){

	
	char buffer[4096]; /*almacena la comunicacion*/
	int leido; /*almacena lo q se lee desde el port 5000 al 8080*/

	int sdmotion; /*descriptor q inicia el socket de comunicacion */	
	int leidomotion;
	char buffermotion[4096];
	struct hostent *Host; //IP del servidor
	struct sockaddr_in Direccion; //Estructura necesaria para la funcion bind()

	#if DEBUG
		printf ("hijo = %d\n", getpid());
	#endif


	/* Obtengo la ip a la cual conectarme */
	if ((Host = gethostbyname ("localhost")) == NULL)
		printf ("Error en gethostbyname()\n");
	else
		printf ("IP: %s\n", Host->h_name);

	/* Abrimos el socket */
	/* AF_INET porque el cliente puede estar en una PC distinta al servidor */
	/* SOCK_STREAM porque se utilizara el protocolo TCP */
	if ((sdmotion = socket (AF_INET, SOCK_STREAM, 0)) == -1)
		printf ("Error en socket()\n");

	/* Vamos a atender el servicio */
	Direccion.sin_family = AF_INET; // Mismo que para la fucion Socket()
	Direccion.sin_port = htons(8080); //Puerto del servicio
	Direccion.sin_addr.s_addr = htonl (0x7f000001); //Direccion del servidor

	leido=read(sdtc,buffer, sizeof(buffer));	

	if (connect (sdmotion, (struct sockaddr *)&Direccion, sizeof Direccion) == -1)
		perror ("connect");
	
	write(sdmotion, buffer, leido);
	parsear(buffer,sdmotion, sdtc);


	while ((leidomotion=read(sdmotion,buffermotion, sizeof buffermotion)) > 0){
		
		write(sdtc,buffermotion,leidomotion);
	
		 }
	close(sdmotion);	
	
return 0;

}
