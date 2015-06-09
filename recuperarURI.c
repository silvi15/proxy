#include "proxy.h"

uri recuperarURI (char *buffer)
{
	char archivo[256];
	char cadena[256];
	int i=0, j=0, fd, leido;
	char *aux;
	
	memset(archivo,0,sizeof archivo);
	memset(root,0,sizeof root);
	strncpy(root,datosConexion.root,sizeof datosConexion.root);

	while(isgraph(buffer[i])){
		uriConexion.metodo[i]=buffer[i];
		i++;
	}
	
	i+=2;

	// En caso de que no se haya solicitado URI, se envia a index.html 	
	if (isspace(buffer[i]))
		strncpy (uriConexion.archivo,  "index.html", 10);

	// Recupera archivo: index.html ...  

	
	while (isgraph(buffer[i]))
	{

		uriConexion.archivo[j] = buffer[i];
		i++;
		j++;
			
		
	}
	
		
	// Recupera version 
	strncpy(uriConexion.version,"HTTP/1.1",8);

	j=0;
		
	// Recupera extension 
	for (i=0; isgraph(uriConexion.archivo[i]); i++)
	{
		if (uriConexion.archivo[i] == '.')
		{
			i++;
			//parsea q llegue la extencion:  html
			while (isalpha(uriConexion.archivo[i]))
			{
				uriConexion.extension[j] = uriConexion.archivo[i];
				i++;
				j++;
				
			}
		}
	}

	j=0;
	i=0;

	// Recupera mime 
	if((fd=open("mimes",O_RDONLY))<0)
		perror("open()");
	else{
		read(fd,cadena, sizeof cadena);
		close(fd);
	}
	//printf("cadena:\n ___%s___\n",cadena);
	//printf("\nuriConexion.extension:__ %s\n__",uriConexion.extension);	
	aux=strstr(cadena, uriConexion.extension);
	
		while (isgraph (aux[i]))
		{
			if (aux[i] == '=')
			{
				i++;
				//paresea q llegue text/html
				while (isgraph (aux[i]))
				{
					uriConexion.mime[j] = aux[i];
					i++;
					j++;
				
				}
			}
			else
				i++;
		}
	

	//memset(aux,0,sizeof (aux));
	 //memset(aux,'\0', sizeof(aux));
		
	j=0;
	i=0;
	
	while(isgraph(uriConexion.archivo[i])){
		if(uriConexion.archivo[i]=='%' && uriConexion.archivo[i+1]=='2' && uriConexion.archivo[i+2]=='0' )
		{
			archivo[j]=' ';
			i+=3;
			j++;
			
		}
		else{
			archivo[j]=uriConexion.archivo[i];
			j++;
			i++;
		}
	}
	
	memset(uriConexion.archivo,0,sizeof uriConexion.archivo);
	strncpy(uriConexion.archivo,archivo,sizeof archivo);
	strncat(root,archivo,sizeof archivo);

	// Recupera length 
	uriConexion.length = 0;
	fd = open (root, O_RDONLY);
	while ((leido = read (fd, aux, sizeof aux)) > 0)
		uriConexion.length += leido;

	
	return uriConexion;
}
