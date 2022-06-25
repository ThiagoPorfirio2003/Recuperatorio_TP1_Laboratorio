#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "utn.h"

#define CANTIDAD_MAXIMA_CARACTERES_NOMBRE 50
#define CANTIDAD_MAXIMA_CARACTERES_APELLIDO 50
#define CANTIDAD_CARACTERES_NOMBRE 50
#define CANTIDAD_CARACTERES_APELLIDO 50
#define VUELO_PRECIO_MINIMO 10000
#define VUELO_PRECIO_MAXIMO 100000000
#define CANTIDAD_CIFRAS_PRECIO 30
#define TIPO_PASAJERO_OPCION_MINIMA 1
#define TIPO_PASAJERO_OPCION_MAXIMA 4
#define CANTIDAD_MAXIMA_CIFRAS_ID 20
#define CARACTERES_MARCO_CODIGOVUELO 15
#define CARACTERES_CODIGOVUELO 10
#define CARACTERES_TIPO_PASAJERO_PALABRA 20
#define CARACTERES_ESTADO_VUELO_PALABRA 20
#define MINIMA_OPCION_MODIFICAR_PASAJERO 1
#define MAXIMA_OPCION_MODIFICAR_PASAJERO 6
#define OPCION_MINIMA_INFORME 1
#define OPCION_MAXIMA_INFORME 3


int controller_addPassenger(Passenger* listPassenger, int id, int cantidadPasajeros)
{
	int retorno;

	char nombre[CANTIDAD_CARACTERES_NOMBRE];
	char apellido[CANTIDAD_CARACTERES_APELLIDO];
	float precio;
	int tipoPasajero;
	char codigoVuelo[CARACTERES_CODIGOVUELO];
	int statusFlight;


	retorno=1;

	if(listPassenger != NULL && id > 0 && cantidadPasajeros > 0)
	{
		if(!Passenger_askOnePassengerData(nombre, apellido, codigoVuelo, &precio, &tipoPasajero, &statusFlight))
		{
			if(!addPassenger(listPassenger, cantidadPasajeros, id, nombre, apellido, precio, tipoPasajero, statusFlight, codigoVuelo))
			{
				retorno=0;
			}
		}
	}
    return retorno;
}

int controller_editPassenger(Passenger* list, int cantidadPasajero, int ultimoId)
{
	int retorno;
	int idAEncontrar;
	int posicionPasajero;
	int opcionModificacion;
	Passenger* pPasajeroAModificar;

	retorno=1;

	if(list != NULL && !utn_GetIntRango(&idAEncontrar, "\nIngrese el id del pasajero cuyos datos desea modificar: ", "Dato invalido. Ingrese el id del pasajero cuyos datos desea modificar: ", 0, ultimoId, 30))
	{
		posicionPasajero = findPassengerById(list, cantidadPasajero,idAEncontrar);

		if(posicionPasajero != -1)
		{
			pPasajeroAModificar = list + posicionPasajero;

			if(pPasajeroAModificar != NULL)
			{
				printf("\n\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
				printf("|%*s|%*s|%*s|$%*s|%*s|%*s|%*s|\n", -CANTIDAD_MAXIMA_CIFRAS_ID, "ID", -CANTIDAD_CARACTERES_NOMBRE, "Nombre", -CANTIDAD_CARACTERES_APELLIDO, "Apellido", -CANTIDAD_CIFRAS_PRECIO, "Precio", -CARACTERES_MARCO_CODIGOVUELO, "Codigo de vuelo", -CARACTERES_TIPO_PASAJERO_PALABRA, "Tipo de pasajero", -CARACTERES_ESTADO_VUELO_PALABRA, "Estado de vuelo");
				printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
				printOnePassenger(pPasajeroAModificar);
				printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
				if(!utn_GetIntRango(&opcionModificacion, "\nCaracteristicas a modificar:\n 1- Nombre\n 2- Apellido\n 3- Precio\n 4- Tipo de Pasajero \n 5- Codigo de vuelo\n 6- Estado de vuelo\nIngrese el numero del aspecto a modificar:  ", "Ingrese el numero del aspecto a modificar: ", MINIMA_OPCION_MODIFICAR_PASAJERO, MAXIMA_OPCION_MODIFICAR_PASAJERO, 3))
				{
					switch(opcionModificacion)
					{
						case 1:
							if(Passenger_modificarNombre(pPasajeroAModificar, "\nIngrese el nuevo nombre del pasajero: ", "Dato invalido. Ingrese el nuevo NOMBRE del pasajero: ", "\n\nNo se puede realizar la operacion debido a que ya no hay memoria\n\n"))
							{
								retorno=1;
							}
							break;

						case 2:
							if(Passenger_ModificarApellido(pPasajeroAModificar, "\nIngrese el nuevo apellido del pasajero: ", "Dato invalido. Ingrese el nuevo APELLIDO del pasajero: ", "\n\nNo se puede realizar la operacion debido a que ya no hay memoria\n\n"))
							{
								retorno=1;
							}
							break;

						case 3:
							if(Passenger_ModificarPrecioVuelo(pPasajeroAModificar, "\nIngresa el nuevo precio del vuelo, debe estar entre $10000 y $100000000: ", "El dato ingresado es invalido. Ingresa el nuevo precio del vuelo, debe estar entre $10000 y $100000000: "))
							{
								retorno=1;
							}
							break;

						case 4:
							if(!Passenger_ModificarTipoPasajero(pPasajeroAModificar, "\nTipo de pasajero:\n 1. FirstClass  \n 2. ExecutiveClass\n 3. EconomyClass\nIngrese el numero correspondiente al tipo: ", "Dato invalido. Ingrese el numero correspondiente al tipo: "))
							{
								retorno=1;
							}
							break;

						case 5:
							if(!Passenger_ModificarCodigoVuelo(pPasajeroAModificar, "\nTeniendo como modelo \"AA1234AA\", ingrese el codigo de vuelo: ", "Dato invalido. Teniendo como modelo \"AA1234AA\", ingrese el codigo de vuelo: ", "\n\nNo se puede realizar la operacion debido a que ya no hay memoria\n\n", "\nEl codigo escrito no cumple con las condiciones\n"))
							{
								retorno=1;
							}
							break;

						case 6:
							if(Passenger_ModificarEstadoVuelo(pPasajeroAModificar, "\nEstado de vuelo:\n 0. Inactivo\n 1. Activo\nIngrese el numero que corresponda: ", "Dato ingresado invalido. Ingrese el numero que corresponda: "))
							{
								retorno=1;
							}
							break;

						default:
							retorno=1;
							break;
					}
					retorno=0;
				}
			}
		}
	}

    return retorno;
}

int controller_removePassenger(Passenger* list, int cantidadPasajeros, int ultimoId)
{
    int retorno;
    int posicionPasajeroAEliminar;
    int idPasajeroAEliminar;
    int preguntaDeConfirmacion;
    Passenger* pPasajeroAEliminar;

    retorno=1;

	if(list != NULL && !utn_GetIntRango(&idPasajeroAEliminar, "\nIngrese el id del pasajero que desea remover: ", "Dato invalido. Ingrese el id del pasajero que desea remover: ", 0, ultimoId, 30))
    {
		posicionPasajeroAEliminar = findPassengerById(list, cantidadPasajeros,idPasajeroAEliminar);

		if(posicionPasajeroAEliminar != -1)
		{
			pPasajeroAEliminar = list + posicionPasajeroAEliminar;
			printf("\n\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++DATOS DEL PASAJERO A ELIMINAR++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
			printf("|%*s|%*s|%*s|$%*s|%*s|%*s|%*s|\n", -CANTIDAD_MAXIMA_CIFRAS_ID, "ID", -CANTIDAD_CARACTERES_NOMBRE, "Nombre", -CANTIDAD_CARACTERES_APELLIDO, "Apellido", -CANTIDAD_CIFRAS_PRECIO, "Precio", -CARACTERES_MARCO_CODIGOVUELO, "Codigo de vuelo", -CARACTERES_TIPO_PASAJERO_PALABRA, "Tipo de pasajero", -CARACTERES_ESTADO_VUELO_PALABRA, "Estado de vuelo");
			printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
			printOnePassenger(pPasajeroAEliminar);
			printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");

			if(!utn_GetIntRango(&preguntaDeConfirmacion, "\nSi esta seguro de querer removerlo presione 1, de lo contrario el 0: ", "Dato invalido. Si esta seguro de querer removerlo presione 1, de lo contrario el 0:", 0, 1, 30))
			{
				retorno =-1;
				if(preguntaDeConfirmacion)
				{
					retorno=1;
					if(!removePassenger(list, cantidadPasajeros, idPasajeroAEliminar))
					{
						retorno=0;
					}
				}
			}
		}
    }

    return retorno;
}

int controller_informPassenger(Passenger* list, int cantidadPasajeros)
{
	int retorno;
	int tipoDeInforme;
	int modoImpresion;
	float precioPromedio;
	float precioTotal;
	int pasajerosSobreElPrecioPromedio;


	retorno=1;

	if(list != NULL && cantidadPasajeros >0)
	{

		if(!utn_GetIntRango(&tipoDeInforme, "\n 1- Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero(Del boleto mas caro al mas barato)\n 2- Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promdio\n 3- Listado de los pasajeros por Código de vuelo y estados de vuelos ACTIVO\nElija una opcion: ", "Dato invalido. Ingrese el id del pasajero cuyos datos desea modificar: ", OPCION_MINIMA_INFORME, OPCION_MAXIMA_INFORME, 30))
		{
			switch(tipoDeInforme)
			{
				case 1:
					sortPassengers(list, cantidadPasajeros,1);
					modoImpresion =1;
					retorno=0;
					break;

				case 2:
					if(!Passenger_getTotalYPromedioPrecio(list, cantidadPasajeros, &precioPromedio, &precioTotal))
					{
						pasajerosSobreElPrecioPromedio = Passenger_getCantidaEncimaPrecioPromedio(list, cantidadPasajeros, precioPromedio);
						if(pasajerosSobreElPrecioPromedio != -1)
						{
							printf("\n - Recaudacion total: $%.2f \n"
									" - Precio promedio: $%.2f\n"
									" - Cantidad de pasajeros encima del precio promedio: %d\n", precioTotal, precioPromedio, pasajerosSobreElPrecioPromedio);
							retorno =0;
						}
					}
					break;

				case 3:
					sortPassengerByCode(list, cantidadPasajeros,1);
					modoImpresion =0;
					retorno=0;
					break;
			}
			if(tipoDeInforme == 1 || tipoDeInforme == 3)
			{
				printPassengers(list, cantidadPasajeros, modoImpresion);
			}
		}
	}

	return retorno;
}
