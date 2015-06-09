#include "proxy.h"

datos argumentos ()
{
	int fd_conf, i=0, j=0, k=0;
	char bufferConf[256]={0};

		fd_conf = open ("configuraciones.conf", O_RDONLY);
		
		read (fd_conf, bufferConf, sizeof bufferConf);

		for (i=0; bufferConf[i]!='\n'; i++)
		{
			if (isdigit (bufferConf[i]))
			{
				datosConexion.puerto[j] = bufferConf[i];
				j++;
				//printf("1) datosConexion.puerto:%s\n",datosConexion.puerto);
				//printf("1) bufferConf[i]%s\n",bufferConf);
			}
		}

		for (; bufferConf[i]!='\0'; i++)
		{
			if (bufferConf[i] == '/')
			{
				while (isgraph (bufferConf[i]))
				{
					datosConexion.root[k] = bufferConf[i];
					k++;
					i++;
				//	printf("2) datosConexion.root %s\n",datosConexion.root);
				//	printf("2) bufferConf: %s\n",bufferConf);				
				}
			}
		}
	
	return datosConexion;
}
