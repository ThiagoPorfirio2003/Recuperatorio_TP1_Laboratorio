/*
 * ArrayPassenger.c
 *
 *  Created on: 11 may. 2022
 *      Author: thiag
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "utn.h"
#include "array.h"

#define CANTIDAD_MAXIMA_CARACTERES_NOMBRE 50
#define CANTIDAD_MAXIMA_CARACTERES_APELLIDO 50
#define CANTIDAD_CARACTERES_NOMBRE 50
#define CANTIDAD_CARACTERES_APELLIDO 50
#define VUELO_PRECIO_MINIMO 10000
#define VUELO_PRECIO_MAXIMO 100000000
#define CANTIDAD_CIFRAS_PRECIO 30
#define TIPO_PASAJERO_OPCION_MINIMA 1
#define TIPO_PASAJERO_OPCION_MAXIMA 3
#define CANTIDAD_MAXIMA_CIFRAS_ID 20
#define CANTIDAD_MINIMA_CARACTERES_CODIGOVUELO 8
#define CANTIDAD_MAXIMA_CARACTERES_CODIGOVUELO 8
#define CARACTERES_MARCO_CODIGOVUELO 15
#define CARACTERES_CODIGOVUELO 10
#define CARACTERES_TIPO_PASAJERO_PALABRA 20
#define CARACTERES_ESTADO_VUELO_PALABRA 20
#define MINIMA_OPCION_MODIFICAR_PASAJERO 1
#define MAXIMA_OPCION_MODIFICAR_PASAJERO 5

int initPassengers(Passenger* list, int len)
{
	int retorno;
	int i;

	retorno = -1;

	if(list !=NULL && len > 0)
	{
		for(i=0;i< len;i++)
		{
			list[i].isEmpty = 1;
		}
		retorno =0;
	}
	return retorno;
}

int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, int statusFlight, char flycode[])
{
	int retorno;
	int i;

	retorno =-1;

	if(list !=NULL && len > 0 && name != NULL && lastName != NULL && flycode !=NULL)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == 1)
			{
				list[i].id = id;
				strcpy(list[i].name, name);
				strcpy(list[i].lastName, lastName);
				list[i].price = price;
				list[i].typePassenger = typePassenger;
				list[i].statusFlight = statusFlight;
				strcpy(list[i].flycode,flycode);
				list[i].isEmpty = 0;
				retorno =0;
				break;
			}
		}
	}
	return retorno;
}


int findPassengerById(Passenger* list, int len,int id)
{
	int retorno;
	int i;

	retorno =-1;

	if(list !=NULL && len>0)
	{
		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty ==0)
			{
				if(list[i].id == id)
				{
					retorno = i;
					break;
				}
			}
		}
	}
	return retorno;
}

int removePassenger(Passenger* list, int len, int id)
{
	int retorno;
	int i;

	retorno = -1;

	if(list !=NULL && len > 0 && id>-1)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].id == id)
			{
				list[i].isEmpty = 1;
				retorno =0;
				break;
			}
		}
	}
	return retorno;
}




int static Passenger_SwapPassenger(Passenger* this, Passenger* pasajeroDeCambio)
{
	int retorno;
	Passenger pasajeroAuxiliar;

	retorno=1;
	if(this != NULL && pasajeroDeCambio != NULL)// && pasajeroAuxiliar != NULL)
	{
		pasajeroAuxiliar = *this;
		*this = *pasajeroDeCambio;
		*pasajeroDeCambio = pasajeroAuxiliar;
		retorno=0;
	}

	return retorno;
}


int static Passenger_SwapPorApellidoAscendente(Passenger* primerPasajero, Passenger* segundoPasajero)
{
	int estadoComparacion;

	estadoComparacion=2;

	if(primerPasajero != NULL && segundoPasajero !=NULL)
	{
		estadoComparacion = array_CompararCadenaCaracteresEspanolInles(primerPasajero->lastName, segundoPasajero->lastName);
		if(estadoComparacion ==1)
		{
			if(Passenger_SwapPassenger(primerPasajero, segundoPasajero))
			{
				estadoComparacion =2;
			}
		}
	}
	return estadoComparacion;
}

int static Passenger_SwapPorTipoPasajeroAscendente(Passenger* primerPasajero, Passenger* segundoPasajero)
{
	int retorno;
	int restaEntreTipos;

	retorno =2;
	if(primerPasajero != NULL && segundoPasajero !=NULL)
	{
		restaEntreTipos = primerPasajero->typePassenger - segundoPasajero->typePassenger;
		if(restaEntreTipos > 0)
		{
			retorno = 1;
			if(Passenger_SwapPassenger(primerPasajero, segundoPasajero))
			{
				retorno =2;
			}
		}
		else
		{
			if(restaEntreTipos == 0)
			{
				retorno = 0;
			}
			else
			{
				retorno =-1;
			}
		}
	}

	return retorno;
}


int static Passenger_SwapPorApellidoDescendente(Passenger* primerPasajero, Passenger* segundoPasajero)
{
	int estadoComparacion;

	estadoComparacion=2;

	if(primerPasajero != NULL && segundoPasajero !=NULL)
	{
		estadoComparacion = array_CompararCadenaCaracteresEspanolInles(primerPasajero->lastName, segundoPasajero->lastName);
		if(estadoComparacion ==-1)
		{
			if(Passenger_SwapPassenger(primerPasajero, segundoPasajero))
			{
				estadoComparacion =2;
			}
		}
	}
	return estadoComparacion;
}

int static Passenger_SwapPorTipoPasajeroDescendente(Passenger* primerPasajero, Passenger* segundoPasajero)
{
	int retorno;
	int restaEntreTipos;

	retorno =2;
	if(primerPasajero != NULL && segundoPasajero !=NULL)
	{
		restaEntreTipos = primerPasajero->typePassenger - segundoPasajero->typePassenger;
		if(restaEntreTipos > 0)
		{
			retorno = 1;
		}
		else
		{
			if(restaEntreTipos == 0)
			{
				retorno = 0;
			}
			else
			{
				retorno =-1;
				if(Passenger_SwapPassenger(primerPasajero, segundoPasajero))
				{
					retorno =2;
				}
			}
		}
	}

	return retorno;
}


int static Passenger_SwapPassengerPorApellidoYTipoPasajero(Passenger* primerPasajero, Passenger* segundoPasajero, int (*pFuncionSwapeoApellido)(Passenger*, Passenger*), int (*pFuncionSwapeoTipoPasajero)(Passenger*, Passenger*))
{
	int retorno;
	int estadoSwapApellido;
	int estadoSwapTipoPasajero;

	retorno =2;

	if(primerPasajero != NULL && segundoPasajero != NULL && pFuncionSwapeoApellido != NULL && pFuncionSwapeoTipoPasajero != NULL)
	{
		estadoSwapApellido = pFuncionSwapeoApellido(primerPasajero, segundoPasajero);
		retorno=estadoSwapApellido;

		if(estadoSwapApellido !=2)
		{
			if(estadoSwapApellido == 0)
			{
				estadoSwapTipoPasajero = pFuncionSwapeoTipoPasajero(primerPasajero, segundoPasajero);
				retorno=estadoSwapTipoPasajero;
			}
		}
	}

	return retorno;
}

int sortPassengers(Passenger* list, int len, int order)
{
	int retorno;
	int flagSwap;
	int estadoSwapAscendente;
	int limiteDecremental;
	int (*pFuncionSwapApellido) (Passenger*, Passenger*);
	int (*pFuncionSwapTipoPasajero) (Passenger*, Passenger*);
	Passenger* pasajeroAuxiliarUno;
	Passenger* pasajeroAuxiliarDos;

	retorno=1;

	if(list != NULL && len >0 && (order == 0 || order ==1))
	{
		limiteDecremental= len-1;
		retorno=0;

		if(order)
		{
			pFuncionSwapApellido = Passenger_SwapPorApellidoAscendente;
			pFuncionSwapTipoPasajero = Passenger_SwapPorTipoPasajeroAscendente;
		}
		else
		{
			pFuncionSwapApellido = Passenger_SwapPorApellidoDescendente;
			pFuncionSwapTipoPasajero = Passenger_SwapPorTipoPasajeroDescendente;
		}

		do{
			flagSwap=0;
			for(int i=0;i<limiteDecremental;i++)
			{
				while(list[i].isEmpty ==1 && i<limiteDecremental)
				{
					i++;
				}
				pasajeroAuxiliarUno = list +i;
				while(list[i+1].isEmpty == 1 && i<limiteDecremental)
				{
					i++;
				}
				pasajeroAuxiliarDos = list + i+1;
				/*
				if(banderaAsistenciaPasajeroDos)
				{
					pasajeroAuxiliarDos++;
				}*/

				if(pasajeroAuxiliarUno->isEmpty == 0 && pasajeroAuxiliarDos->isEmpty == 0)
				{
					//estadoSwapAscendente = Passenger_SwapPassengerPorApellidoYTipoPasajero(&list[i], &list[i+1], pFuncionSwapApellido, pFuncionSwapTipoPasajero);
					estadoSwapAscendente = Passenger_SwapPassengerPorApellidoYTipoPasajero(pasajeroAuxiliarUno, pasajeroAuxiliarDos, pFuncionSwapApellido, pFuncionSwapTipoPasajero);

					if(estadoSwapAscendente != 2)
					{
						if(estadoSwapAscendente == 1)
						{
							flagSwap =1;
						}
					}
					else
					{
						retorno=1;
						break;
					}
				}
			}
			if(retorno)
			{
				break;
			}

			limiteDecremental--;
		}while(flagSwap);
	}
	return retorno;
}

int Passenger_verificarYTransfomarEstadoVueloIntAString(char* estadoVueloString, int estadoVueloNumero)
{
	int retorno;

	retorno=1;

	if(estadoVueloString != NULL)
	{
		retorno=0;
		if(estadoVueloNumero ==1)
		{
			strcpy(estadoVueloString, "Activo");
		}
		else
		{
			if(estadoVueloNumero ==0)
			{
				strcpy(estadoVueloString, "Inactivo");
			}
			else
			{
				retorno=1;
			}
		}
	}
	return retorno;
}

int Passenger_verificarYTransfomarTipoPasajeroIntAString(char* tipoPasajeroString, int tipoPasajeroNumero)
{
	int retorno;

	retorno=1;

	if(tipoPasajeroString != NULL)
	{
		retorno=0;
		switch(tipoPasajeroNumero)
		{
			case 1:
				strcpy(tipoPasajeroString, "FirstClass");
				break;

			case 2:
				strcpy(tipoPasajeroString, "ExecutiveClass");
				break;

			case 3:
				strcpy(tipoPasajeroString, "EconomyClass");
				break;

			default:
				retorno=1;
				break;
		}
	}
	return retorno;
}


int printOnePassenger(Passenger* pPasajeroAMostrar)
{
	int retorno;
	char tipoPasajeroPalabra[CARACTERES_TIPO_PASAJERO_PALABRA];
	char estadoVueloPalabra[CARACTERES_ESTADO_VUELO_PALABRA];

	retorno=1;

	if(pPasajeroAMostrar == NULL)
	{
		printf("\n\nNULLO\n\n");
	}

	if(pPasajeroAMostrar != NULL && !Passenger_verificarYTransfomarEstadoVueloIntAString(estadoVueloPalabra, pPasajeroAMostrar->statusFlight) &&
			!Passenger_verificarYTransfomarTipoPasajeroIntAString(tipoPasajeroPalabra, pPasajeroAMostrar->typePassenger))
	{
		printf("|%*d|%*s|%*s|$%*.2f|%*s|%*s|%*s|\n", -CANTIDAD_MAXIMA_CIFRAS_ID, pPasajeroAMostrar->id, -CANTIDAD_CARACTERES_NOMBRE, pPasajeroAMostrar->name, -CANTIDAD_CARACTERES_APELLIDO, pPasajeroAMostrar->lastName, -CANTIDAD_CIFRAS_PRECIO, pPasajeroAMostrar->price, -CARACTERES_MARCO_CODIGOVUELO, pPasajeroAMostrar->flycode, -CARACTERES_TIPO_PASAJERO_PALABRA, tipoPasajeroPalabra, -CARACTERES_ESTADO_VUELO_PALABRA, estadoVueloPalabra);
		retorno=0;
	}
    return retorno;
}

int printPassengers(Passenger* list, int length, int modoImpresion)
{
	int retorno;
	retorno=1;

	if(list != NULL && length > 0 && (modoImpresion == 0 || modoImpresion == 1))
	{
		retorno=0;
		printf("\n\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		printf("|%*s|%*s|%*s|$%*s|%*s|%*s|%*s|\n", -CANTIDAD_MAXIMA_CIFRAS_ID, "ID", -CANTIDAD_CARACTERES_NOMBRE, "Nombre", -CANTIDAD_CARACTERES_APELLIDO, "Apellido", -CANTIDAD_CIFRAS_PRECIO, "Precio", -CARACTERES_MARCO_CODIGOVUELO, "Codigo de vuelo", -CARACTERES_TIPO_PASAJERO_PALABRA, "Tipo de pasajero", -CARACTERES_ESTADO_VUELO_PALABRA, "Estado de vuelo");
		printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		for(int i=0;i<length;i++)
		{
			if(list[i].isEmpty ==0 && (modoImpresion != 0 || list[i].statusFlight == 1))
			{
				if(printOnePassenger(&list[i]))
				{
					retorno=1;
					break;
				}
			}
		}
		printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");

	}
    return retorno;
}





int static Passenger_SwapPorCodigoVueloAscendente(Passenger* primerPasajero, Passenger* segundoPasajero)
{
	int estadoComparacion;

	estadoComparacion=2;

	if(primerPasajero != NULL && segundoPasajero !=NULL)
	{
		estadoComparacion = array_CompararCadenaCaracteresEspanolInles(primerPasajero->flycode, segundoPasajero->flycode);
		if(estadoComparacion ==1)
		{
			if(Passenger_SwapPassenger(primerPasajero, segundoPasajero))
			{
				estadoComparacion =2;
			}
		}
	}
	return estadoComparacion;
}

int static Passenger_SwapPorEstadoVueloAscendente(Passenger* primerPasajero, Passenger* segundoPasajero)
{
	int retorno;
	int restaEntreTipos;

	retorno =2;
	if(primerPasajero != NULL && segundoPasajero !=NULL)
	{
		restaEntreTipos = primerPasajero->statusFlight - segundoPasajero->statusFlight;
		if(restaEntreTipos > 0)
		{
			retorno = 1;
			if(Passenger_SwapPassenger(primerPasajero, segundoPasajero))
			{
				retorno =2;
			}
		}
		else
		{
			if(restaEntreTipos == 0)
			{
				retorno = 0;
			}
			else
			{
				retorno =-1;
			}
		}
	}

	return retorno;
}


int static Passenger_SwapPorCodigoVueloDescendente(Passenger* primerPasajero, Passenger* segundoPasajero)
{
	int estadoComparacion;

	estadoComparacion=2;

	if(primerPasajero != NULL && segundoPasajero !=NULL)
	{
		estadoComparacion = array_CompararCadenaCaracteresEspanolInles(primerPasajero->flycode, segundoPasajero->flycode);
		if(estadoComparacion ==-1)
		{
			if(Passenger_SwapPassenger(primerPasajero, segundoPasajero))
			{
				estadoComparacion =2;
			}
		}
	}
	return estadoComparacion;
}

int static Passenger_SwapPorEstadoVueloDescendente(Passenger* primerPasajero, Passenger* segundoPasajero)
{
	int retorno;
	int restaEntreTipos;

	retorno =2;
	if(primerPasajero != NULL && segundoPasajero !=NULL)
	{
		restaEntreTipos = primerPasajero->statusFlight - segundoPasajero->statusFlight;
		if(restaEntreTipos > 0)
		{
			retorno = 1;
		}
		else
		{
			if(restaEntreTipos == 0)
			{
				retorno = 0;
			}
			else
			{
				retorno =-1;
				if(Passenger_SwapPassenger(primerPasajero, segundoPasajero))
				{
					retorno =2;
				}
			}
		}
	}

	return retorno;
}

int static Passenger_SwapPassengerPorCodigoVueloYEstadoVuelo(Passenger* primerPasajero, Passenger* segundoPasajero, int (*pFuncionSwapCodigoVuelo)(Passenger*, Passenger*), int (*pFuncionEstadoVuelo)(Passenger*, Passenger*))
{
	int retorno;
	int estadoSwapCodigoVuelo;
	int estadoSwapEstadoVuelo;

	retorno =2;

	if(primerPasajero != NULL && segundoPasajero != NULL && pFuncionSwapCodigoVuelo != NULL && pFuncionEstadoVuelo != NULL)
	{
		estadoSwapCodigoVuelo = pFuncionSwapCodigoVuelo(primerPasajero, segundoPasajero);
		retorno=estadoSwapCodigoVuelo;
		if(estadoSwapCodigoVuelo !=2)
		{
			if(estadoSwapCodigoVuelo == 0)
			{
				estadoSwapEstadoVuelo = pFuncionEstadoVuelo(primerPasajero, segundoPasajero);
				retorno=estadoSwapEstadoVuelo;
			}
		}
	}

	return retorno;
}

int sortPassengerByCode(Passenger* list, int len, int order)
{
	int retorno;
	int flagSwap;
	int estadoSwapAscendente;
	int limiteDecremental;
	int (*pFuncionSwapCodigoVuelo) (Passenger*, Passenger*);
	int (*pFuncionSwapEstadoVuelo) (Passenger*, Passenger*);
	Passenger* pasajeroAuxiliarUno;
	Passenger* pasajeroAuxiliarDos;

	retorno=1;

	if(list != NULL && len >0 && (order == 0 || order ==1))
	{
		limiteDecremental= len-1;
		retorno=0;

		if(order)
		{
			pFuncionSwapCodigoVuelo = Passenger_SwapPorCodigoVueloAscendente;
			pFuncionSwapEstadoVuelo = Passenger_SwapPorEstadoVueloAscendente;
		}
		else
		{
			pFuncionSwapCodigoVuelo = Passenger_SwapPorCodigoVueloDescendente;
			pFuncionSwapEstadoVuelo = Passenger_SwapPorEstadoVueloDescendente;
		}

		do{
			flagSwap=0;
			for(int i=0;i<limiteDecremental;i++)
			{
				while(list[i].isEmpty ==1 && i<limiteDecremental)
				{
					i++;
				}
				pasajeroAuxiliarUno = list +i;
				while(list[i+1].isEmpty == 1 && i<limiteDecremental)
				{
					i++;
				}
				pasajeroAuxiliarDos = list + i+1;

				if(pasajeroAuxiliarUno->isEmpty == 0 && pasajeroAuxiliarDos->isEmpty ==0)
				{
					estadoSwapAscendente = Passenger_SwapPassengerPorCodigoVueloYEstadoVuelo(pasajeroAuxiliarUno, pasajeroAuxiliarDos, pFuncionSwapCodigoVuelo, pFuncionSwapEstadoVuelo);
					if(estadoSwapAscendente != 2)
					{
						if(estadoSwapAscendente == 1)
						{
							flagSwap =1;
						}
					}
					else
					{
						retorno=1;
						break;
					}
				}

			}
			if(retorno)
			{
				break;
			}

			limiteDecremental--;
		}while(flagSwap);
	}
	return retorno;
}


int static Passenger_verificarSerCodigoDeVuelo(char* cadenaAlfanumerica)
{
	int retorno;
	int contadorLetras;
	int contadorNumeros;

	retorno =1;
	contadorLetras=0;
	contadorNumeros=0;

	if(cadenaAlfanumerica != NULL)
	{
		retorno=0;
		for(int i=0; i<8;i++)
		{
			if(isalpha(*(cadenaAlfanumerica+i)))
			{
				if((contadorNumeros == 0 && contadorLetras <2) || (contadorNumeros ==4 && contadorLetras > 1))
				{
					contadorLetras++;
				}
				else
				{
					retorno=1;
					break;
				}
			}
			else
			{
				if(isdigit(*(cadenaAlfanumerica+i)))
				{
					if(contadorNumeros<4 && contadorLetras == 2)
					{
						contadorNumeros++;
					}
					else
					{
						retorno=1;
						break;
					}
				}
				else
				{
					retorno=1;
					break;
				}
			}
		}
	}
	return retorno;
}


int Passenger_modificarNombre(Passenger* pasajeroAManipular, char* mensaje, char* mensajeError, char* mensajeErrorSinMemoria)
{
	int retorno;
	char nombre[CANTIDAD_CARACTERES_NOMBRE];

	retorno=1;

	if(pasajeroAManipular!=NULL && mensaje != NULL && mensajeError != NULL && mensajeErrorSinMemoria !=NULL)
	{
		if(!utn_GetNombreRango(nombre, mensaje, mensajeError, mensajeErrorSinMemoria, 2, CANTIDAD_MAXIMA_CARACTERES_NOMBRE, CANTIDAD_CARACTERES_NOMBRE))
		{
			strcpy(pasajeroAManipular->name, nombre);
			retorno=0;
		}
	}

	return retorno;
}

int Passenger_ModificarApellido(Passenger* pasajeroAManipular, char* mensaje, char* mensajeError, char* mensajeErrorSinMemoria)
{
	int retorno;
	char apellido[CANTIDAD_CARACTERES_APELLIDO];

	retorno=1;

	if(pasajeroAManipular!=NULL && mensaje != NULL && mensajeError != NULL && mensajeErrorSinMemoria != NULL)
	{
		if(!utn_GetNombreRango(apellido, mensaje, mensajeError, mensajeErrorSinMemoria, 2, CANTIDAD_MAXIMA_CARACTERES_NOMBRE, CANTIDAD_CARACTERES_NOMBRE))
		{
			strcpy(pasajeroAManipular->lastName, apellido);
			retorno=0;
		}
	}
	return retorno;
}

int Passenger_ModificarCodigoVuelo(Passenger* pasajeroAManipular, char* mensaje, char* mensajeError, char* mensajeErrorSinMemoria, char* mensajeCodigoInvalido)
{
	int retorno;
	char codigoVuelo[CARACTERES_CODIGOVUELO];

	retorno=1;

	if(pasajeroAManipular!=NULL && mensaje !=NULL && mensajeError != NULL && mensajeErrorSinMemoria != NULL && mensajeCodigoInvalido !=NULL)
	{
		while(utn_GetCadenaAlfanumericaRango(codigoVuelo, mensaje, mensajeError, mensajeCodigoInvalido, CANTIDAD_MINIMA_CARACTERES_CODIGOVUELO, CANTIDAD_MAXIMA_CARACTERES_CODIGOVUELO, CARACTERES_CODIGOVUELO) ||
				Passenger_verificarSerCodigoDeVuelo(codigoVuelo))
		{
			printf("%s",mensajeCodigoInvalido);
		}

		utn_trasnformarCadenaAMayuscula(codigoVuelo);
		strcpy(pasajeroAManipular->flycode,codigoVuelo);
		retorno =0;
	}
	return retorno;
}

int Passenger_ModificarTipoPasajero(Passenger* pasajeroAManipular, char* mensaje, char* mensajeError)
{
	int retorno;
	int tipoPasajero;

	retorno=1;

	if(pasajeroAManipular!=NULL && mensaje != NULL && mensajeError != NULL)
	{
		if(!utn_GetIntRango(&tipoPasajero, mensaje, mensajeError, TIPO_PASAJERO_OPCION_MINIMA, TIPO_PASAJERO_OPCION_MAXIMA, 5))
		{
			pasajeroAManipular->typePassenger = tipoPasajero;
			retorno=0;
		}
	}

	return retorno;
}

int Passenger_ModificarPrecioVuelo(Passenger* pasajeroAManipular, char* mensaje, char* mensajeError)
{
	int retorno;
	float precio;

	retorno=1;

	if(pasajeroAManipular!=NULL && mensaje != NULL && mensajeError != NULL)
	{
		if(!utn_GetFloatRango(&precio, mensaje, mensajeError, VUELO_PRECIO_MINIMO, VUELO_PRECIO_MAXIMO, CANTIDAD_CIFRAS_PRECIO))
		{
			pasajeroAManipular->price = precio;
			retorno=0;
		}
	}

	return retorno;
}

int Passenger_ModificarEstadoVuelo(Passenger* pasajeroAManipular, char* mensaje, char* mensajeError)
{
	int retorno;
	int estadoDeVuelo;

	retorno=1;

	if(pasajeroAManipular!=NULL && mensaje != NULL && mensajeError != NULL)
	{
		if(!utn_GetIntRango(&estadoDeVuelo, mensaje, mensajeError, 0, 1, 5))
		{
			pasajeroAManipular->statusFlight = estadoDeVuelo;
			retorno=0;
		}
	}

	return retorno;
}


int Passenger_getTotalYPromedioPrecio(Passenger* list, int cantidadPasajeros, float* precioPromedio, float* precioTotal)
{
	int retorno;
	int pasajerosActivos;

	pasajerosActivos =0;
	retorno=1;

	if(list != NULL && precioPromedio != NULL && precioTotal != NULL)
	{
		retorno =0;
		for(int i=0; i<cantidadPasajeros; i++)
		{
			if(list[i].isEmpty == 0)
			{
				pasajerosActivos++;
				(*precioTotal)+= list[i].price;
			}
		}
		*precioPromedio = *precioTotal / pasajerosActivos;
	}
	return retorno;
}

int Passenger_getCantidaEncimaPrecioPromedio(Passenger* list, int cantidadPasajeros, float precioPromedio)
{
	int retorno;

	retorno =-1;

	if(list != NULL && cantidadPasajeros > 0 && precioPromedio > 0)
	{
		retorno =0;
		for(int i=0; i<cantidadPasajeros; i++)
		{
			if(list[i].isEmpty == 0 && list[i].price > precioPromedio)
			{
				retorno++;
			}
		}
	}
	return retorno;
}

int Passenger_askOnePassengerData(char* nombre, char* apellido, char* codigoVuelo,float* precio, int* tipoPasajero, int* statusFlight)
{
	int retorno;
	retorno=1;

	if(nombre != NULL && apellido != NULL && codigoVuelo != NULL && precio != NULL && tipoPasajero != NULL && statusFlight != NULL &&
			!utn_GetNombreRango(nombre, "\nIngrese el nombre del pasajero: ", "Dato invalido. Ingrese el NOMBRE del pasajero: ", "\nHubo un error debido a faltante de memoria", 2, CANTIDAD_MAXIMA_CARACTERES_NOMBRE, CANTIDAD_CARACTERES_NOMBRE) &&
			!utn_GetNombreRango(apellido, "\nIngrese el apellido del pasajero: ", "Dato invalido. Ingrese el APELLIDO del pasajero: ", "\nHubo un error debido a faltante de memoria", 2, CANTIDAD_MAXIMA_CARACTERES_APELLIDO, CANTIDAD_CARACTERES_APELLIDO) &&
			!utn_GetFloatRango(precio, "\nIngresa el precio del vuelo, debe estar entre $10000 y $100000000: ", "El dato ingresado es invalido. Ingresa el precio del vuelo, debe estar entre $10000 y $100000000:", VUELO_PRECIO_MINIMO, VUELO_PRECIO_MAXIMO, CANTIDAD_CIFRAS_PRECIO) &&
			!utn_GetIntRango(tipoPasajero, "\nTipo de pasajero:\n 1. FirstClass  \n 2. ExecutiveClass\n 3. EconomyClass\nIngrese el numero correspondiente al tipo: ", "Dato invalido. Ingrese el numero correspondiente al tipo: ", TIPO_PASAJERO_OPCION_MINIMA, TIPO_PASAJERO_OPCION_MAXIMA, 5) &&
			!utn_GetIntRango(statusFlight, "\nEstado de vuelo:\n 0. Inactivo\n 1. Activo\nIngrese el numero que corresponda: ", "Dato ingresado invalido. Ingrese el numero que corresponda: ", 0, 1, 5))
	{
		while(utn_GetCadenaAlfanumericaRango(codigoVuelo, "\nTeniendo como modelo \"AA1234AA\", ingrese el codigo de vuelo: ", "Dato invalido. Teniendo como modelo \"AA1234AA\", ingrese el codigo de vuelo: ", "\nNo se puede realizar la operacion debido a que ya no hay memoria\n", CANTIDAD_MINIMA_CARACTERES_CODIGOVUELO, CANTIDAD_MAXIMA_CARACTERES_CODIGOVUELO, CARACTERES_CODIGOVUELO) ||
				Passenger_verificarSerCodigoDeVuelo(codigoVuelo))
		{
			printf("\nEl codigo ingresado no cumple con los requisitos\n");
		}
		utn_trasnformarCadenaAMayuscula(codigoVuelo);
		retorno=0;
	}
	return retorno;
}
