/*	Christopher Flores 10-10824
	Maria Fernanda Magallanes 13-10787

	Main Tarea 1
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{

	int opcion;


	while(1)
	{
		printf("BIENVENIDO AL PROGRAMA DE DESCIFRADO:\n\nOpciones:\n");
		printf("● (1) Registrar nuevos mensajes cifrados y sus descifrados\n");
		printf("● (2) Descifrar mensajes\n");
		printf("● (3) Cifrar mensajes\n");
		printf("● (4) Mostrar un esquema de cifrado\n");
		printf("● (5) Borrar un esquema de cifrado debido a un error\n");
		printf("● (6) SALIR\n\n");
		printf("Opcion: ");

		scanf("%d",&opcion);
		fflush(stdin);
		fflush(stdout);
		switch(opcion){
			case 1:
				while(1){
					
					char fecha[12];
					char cifrado[99];
					char descifrado[99];

					printf("Registrar nuevos mensajes:\n\n");
					printf("Fecha del mensaje de la forma DD-MM-AAAA : ");
					fgets (fecha, sizeof(fecha), stdin);

					printf("Mensaje cifrado: ");
					fgets (cifrado, sizeof(cifrado), stdin);
					printf("Mensaje descifrado: ");
					fgets (descifrado, sizeof(descifrado), stdin);




				}
			case 2:
				while(1){

				}
			case 3:
				while(1){

				}
			case 4: break ;
			case 5:	break;
			case 6: break;
		}
			 
	}

	return 0;
}
