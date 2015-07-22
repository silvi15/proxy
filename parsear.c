#include "proxy.h"

void parsear (char *buffer,int sdmotion,int sdtc){
 
 
   char *path  = NULL;
   int leido;
   char cabecera[256];
   char bufferCodigo[256];
   //memset (archivo, 0, sizeof archivo);	
   memset (cabecera, 0, sizeof cabecera);
   //memset (buffer, 0, sizeof buffer);
   memset (bufferCodigo, 0, sizeof bufferCodigo);
   char *estado;
   int resultado;

   datosConexion = argumentos(); 

   if(strtok(buffer, " "))
      {
      path = strtok(NULL, " ");
      if(path)
         path=strdup(path);
      }

	printf("path :%s\n",path);

	//si es igual, creo el formulario	
  	if(strcmp(path,"/index.html")==0){   	
	
		uriConexion = recuperarURI (buffer);
		memset (uriConexion.archivo, 0, sizeof uriConexion.archivo);
		if ((resultado = open (root, O_RDONLY)) > 0)
			
		{	
			memset (root, 0, sizeof root);
			memset (uriConexion.extension, 0, sizeof uriConexion.extension);
			estado = "200 OK";
			leido = snprintf (cabecera, sizeof cabecera,"%s %s\nContent-Type: %s\nContent-Length: %ld\n\n", 
				  uriConexion.version, estado, uriConexion.mime, uriConexion.length);
			memset (uriConexion.version, 0, sizeof uriConexion.version);
	        	write (sdtc, cabecera, leido);
			memset (cabecera, 0, sizeof cabecera);
			// Se parsea el URI pedido 
			// resultado contiene el open del archivo de configuracion text/html por eje
			// el pedido de la uri lo almaceno en un bufferCodigo	
				while ((leido = read (resultado, bufferCodigo, sizeof bufferCodigo)) > 0)
				{
					write (sdtc, bufferCodigo, leido);
					memset (bufferCodigo, 0, sizeof bufferCodigo);
				}							
				close(sdtc);
		}
	}
	else{
	printf("creo la funcion cron");
	funcion(path,sdtc);
	/*estado = "200 OK";
	leido = snprintf (cabecera, sizeof cabecera,"%s %s\nContent-Type: %s\nContent-Length: %ld\n\n", 
				  uriConexion.version, estado, uriConexion.mime, uriConexion.length);
			memset (uriConexion.version, 0, sizeof uriConexion.version);
	        	write (sdtc, cabecera, leido);
			memset (cabecera, 0, sizeof cabecera);
			
	}*/
return 0;

}
