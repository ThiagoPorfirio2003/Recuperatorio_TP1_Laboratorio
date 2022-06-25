#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"
#include "ArrayPassenger.h"
#include "Controller.h"

#define CANTIDAD_PASAJEROS 2000
#define MENU_OPCION_MINIMA 1
#define MENU_OPCION_MAXIMA 6


int main(void) {
	setbuf(stdout, NULL);


	int opcionMenu;
	int banderaOpcionDos;
	int banderaOpcionTres;
	int banderaOpcionCuatro;
	int banderaOpcionCinco;
	int contadorID;


	Passenger list[CANTIDAD_PASAJEROS];
	Passenger hardcodeado[]={
			{2,"Pedra", "Rácedo", 78030, "AD2314AS", 3, 1, 0},
			{4,"Thiago", "Porfirio", 102003, "CV1245FD", 2, 0, 0},
			{3,"Patricio", "Fernandez", 52000, "AS5364AD", 3, 0, 0},
			{5,"Juana", "Rácedo", 32000, "AB4561CV", 2, 1, 0},
			{1,"Esteban", "Águirre", 15000, "FD3463DA", 3, 1, 0},
	};

	contadorID=0;
	banderaOpcionDos=0;
	banderaOpcionTres=0;
	banderaOpcionCuatro=0;
	banderaOpcionCinco=1;


	initPassengers(list, CANTIDAD_PASAJEROS);

	printf("¡¡¡¡ Bienvendido !!!\n\n");
	do
	{
		printf("---------------------OPCIONES-----------------------\n"
				"1. Ingresar datos de un pasajero\n"
				"2. Modificar datos de un pasajero, se requiere su ID\n"
				"3. Eliminar un pasajero, se requiere su ID\n"
				"4. Informe sobre pasajeros\n"
				"5. Usar datos Precargados\n\n");

		if(!utn_GetIntRango(&opcionMenu, "Ingrese la opcion: ", "Dato invalido. Ingrese la opcion: ", MENU_OPCION_MINIMA, MENU_OPCION_MAXIMA, 1))
		{
			switch(opcionMenu)
			{
				case 1:

					contadorID++;
					if(controller_addPassenger(list, contadorID, CANTIDAD_PASAJEROS))
					{
						contadorID--;
						printf("\n\nHa ocurrido un error en la carga del pasajero, lo mas probable es que no haya mas espacio");
					}
					else
					{
						printf("\n\nSe ha ingresado al pasajero con exito");
					}


					banderaOpcionDos =1;
					banderaOpcionTres =1;
					banderaOpcionCuatro =1;
					banderaOpcionCinco=0;

				break;

				case 2:
					if(banderaOpcionDos ==1)
					{
						if(controller_editPassenger(list, CANTIDAD_PASAJEROS , contadorID))
						{
							printf("\n\nNo se modifico el usuario, debido a un error o inexistencia");
						}
					}
					else
					{
						printf("\n\nTenes que ingresar al menos un pasajero para poder realizar esta opcion");
					}
					break;

				case 3:
					if(banderaOpcionTres ==1)
					{
						switch(controller_removePassenger(list, CANTIDAD_PASAJEROS, contadorID))
						{
							case -1:
								printf("\n\nSe ha cancelado la eliminacion del pasajero");
								break;

							case 0:
								printf("\n\nSe ha eliminado con exito al pasajero");
								break;

							case 1:
								printf("\n\nHa ocurrido un error, lo mas probable es que el ID seleccionado no corresponda a un pasajero activo");
								break;

							default:
								printf("\n\nAlguien estuvo modificando el codigo y lo hizo mal");
								break;
						}
					}
					else
					{
						printf("\n\nTenes que ingresar al menos un pasajero para poder realizar esta opcion");
					}
					break;

				case 4:
					if(banderaOpcionCuatro==1)
					{
						if(controller_informPassenger(list, CANTIDAD_PASAJEROS))
						{
							printf("\n\nHa ocurrido un error");
						}
						else
						{
							printf("\n\nSe mostraron con exito todos los pasajeros");
						}
					}
					else
					{
						printf("\n\nTenes que ingresar al menos un pasajero para poder realizar esta opcion");
					}
					break;

				case 5:
					if(banderaOpcionCinco==1)
					{
						list[0] = hardcodeado[0];
						list[1] = hardcodeado[1];
						list[2] = hardcodeado[2];
						list[3] = hardcodeado[3];
						list[4] = hardcodeado[4];

						contadorID =5;
						banderaOpcionDos =1;
						banderaOpcionTres =1;
						banderaOpcionCuatro =1;
						banderaOpcionCinco =0;
						printf("\nSe activaron los 5 pasajeros precargados.");
					}
					else
					{
						printf("\nComo ya ingresaste al menos un pasajero o entraste aqui previamente, esta opcion se volvio inaccesible");
					}
					break;

				default:
					printf("\nSaliendo...");
					break;
			}
		}

		printf("\n\n");
	}while(opcionMenu < 6);

	return EXIT_SUCCESS;
}
