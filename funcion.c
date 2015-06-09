#include "proxy.h"

int funcion(char * path){

char *p;
//printf ("String  \"%s\" separar en token:\n",path);
p = strtok (path,"?");
	while (p!= NULL)
	{
    		printf ("%s\n",p);
    		p = strtok (NULL, "&");
  	}

/*
/accion.html
Minutos=2
Hora=06
dia=5
Mes=8
semana=3		
*/

return 0;
}
