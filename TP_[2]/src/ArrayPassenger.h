/*
 * ArrayPassenger.h
 *
 *  Created on: 11 may. 2022
 *      Author: thiag
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

typedef struct
{
	int id;
	char name[50];
	char lastName[50];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
} Passenger;

#endif /* ARRAYPASSENGER_H_ */

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int initPassengers(Passenger* list, int len);

/** \brief add in a existing list of passengers the values received as parameters
* in the first empty position
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, int statusFlight, char flycode[]);

/** \brief find a Passenger by Id en returns the index position in array.
*
* \param list Passenger*
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*/
int findPassengerById(Passenger* list, int len,int id);

/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok
*
*/
int removePassenger(Passenger* list, int len, int id);



/** \brief Sort the elements in the array of passengers, the argument order
*indicate UP or DOWN order
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengers(Passenger* list, int len, int order);

/// @brief Con esta funcion se puede mostrar los datos de un pasajero siempre y cuando haya salido todo bien
///
/// @pre
/// @post
/// @param pPasajeroAMostrar: Es el puntero al pasajero que se va a mostrar
/// @return int: 1 si el puntero el nulo o si el estado de vuelo o tipo de pasajero son invalidos, caso contrario devuelve un 0
int printOnePassenger(Passenger* pPasajeroAMostrar);


/** \brief print the content of passengers array
* \param list Passenger*
* \param length int
* \return int
*/
int printPassengers(Passenger* list, int length, int modoImpresion);

/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int sortPassengerByCode(Passenger* list, int len, int order);

/// @brief Con esta funcion se puede pedir todos los datos de un pasajero
///
/// @pre
/// @post
/// @param nombre: Puntero hacia donde se almacenara el nombre ingresado
/// @param apellido: Puntero hacia donde se almacenara el apellido ingresado
/// @param codigoVuelo: Puntero hacia donde se almacenara el codigo de vuelo ingresado
/// @param precio: Puntero hacia donde se almacenara el precio ingresado
/// @param tipoPasajero: Puntero hacia donde se almacenara el tipo de pasajero ingresado
/// @param statusFlight: Puntero hacia donde se almacenara el estado de vuelo ingresado
/// @return int: 1 si alguno de los punteros es nulo o si no hay espacio en memoria suficiente, de lo contrario de vuelve un 0
int Passenger_askOnePassengerData(char* nombre, char* apellido, char* codigoVuelo,float* precio, int* tipoPasajero, int* statusFlight);



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/* Con esta funciones se puede modificar el campo de una de una variable Passenger, que aparece en el nombre
 *  pasajeroAManipular: Es el puntero al pasajero con el que vamos a trabajar
 *  mensaje: Es un puntero. Es el mensaje que aparecera la primera vez que se va a modificar el campo
 *  mensajeError: Es un puntero. Es el mensaje que aparecera la cada vez que se ingrese un dato erroneo para modificar el campo
 *  mensajeErrorSinMemoria: Es un puntero. Es el mensaje que aparecera si no hay suficiente memoria para trabajar
 *  mensajeCodigoInvalido: Es un puntero y es exclusivo de Passenger_ModificarCodigoVuelo, y aparece cada vez que se ingresa un codigo de vuelo que no cumple con el formato mostrado
 */


int Passenger_modificarNombre(Passenger* pasajeroAManipular, char* mensaje, char* mensajeError, char* mensajeErrorSinMemoria);

int Passenger_ModificarApellido(Passenger* pasajeroAManipular, char* mensaje, char* mensajeError, char* mensajeErrorSinMemoria);

int Passenger_ModificarCodigoVuelo(Passenger* pasajeroAManipular, char* mensaje, char* mensajeError, char* mensajeErrorSinMemoria, char* mensajeCodigoInvalido);

int Passenger_ModificarTipoPasajero(Passenger* pasajeroAManipular, char* mensaje, char* mensajeError);

int Passenger_ModificarPrecioVuelo(Passenger* pasajeroAManipular, char* mensaje, char* mensajeError);

int Passenger_ModificarEstadoVuelo(Passenger* pasajeroAManipular, char* mensaje, char* mensajeError);


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/// @brief Con esta funcion se puede obtener la recaudacion total de los vuelos y el precio promedio
///
/// @pre
/// @post
/// @param list: Puntero al array en donde estan cargados los pasajeros
/// @param cantidadPasajeros
/// @param precioPromedio: Puntero a la variable en donde se guardara el promedio de precio de los vuelos
/// @param precioTotal: Puntero a la variable en donde se guardara la recaudacion total
/// @return int: 1 Si alguno de los punteros es nulo o si la cantidad de pasajeros es menor a 1, caso contrario devuelve 0
int Passenger_getTotalYPromedioPrecio(Passenger* list, int cantidadPasajeros, float* precioPromedio, float* precioTotal);

/// @brief Con esta funcion se puede obtener la cantidad de pasajeros que estan encima del promedio
///
/// @pre
/// @post
/// @param list: Puntero al array en donde estan cargados los pasajeros
/// @param cantidadPasajeros
/// @param precioPromedio:
/// @return int: 1 Si el puntero es nulo o si la cantidad de pasajeros es menor a 1 o si el precio promedio es menor a 0, caso contrario devuelve la cantidad de pasajeros
/// que superan el precio promedio
int Passenger_getCantidaEncimaPrecioPromedio(Passenger* list, int cantidadPasajeros, float precioPromedio);



