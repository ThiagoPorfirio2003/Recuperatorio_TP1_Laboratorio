#include "ArrayPassenger.h"

/// @brief Con esta funcion se puede agregar un pasajero a un array de tipo Passenger
///
/// @pre
/// @post
/// @param listPassenger: Puntero al array en donde queremos cargar el nuevo pasajero
/// @param id: El id del nuevo pasajero
/// @param cantidadPasajeros
/// @return int: 1 si el puntero es nulo, si el id es menor a 1 o si la cantidad de pasajeros es menor a 1 o si hubo un error en el ingreso de datos
/// Si todo sale bien se carga el pasajero y retorna un 0
int controller_addPassenger(Passenger* listPassenger, int id, int cantidadPasajeros);

/// @brief Con esta funcion se puede pedir todos los datos de un pasajero
///
/// @pre
/// @post
/// @param nombre: Puntero hacia donde se almacenara el nombre ingresado
/// @param apellido: Puntero hacia donde se almacenara el apellido ingresado
/// @param precio: Puntero hacia donde se almacenara el precio ingresado
/// @param tipoPasajero: Puntero hacia donde se almacenara el tipo de pasajero ingresado
/// @param codigoVuelo: Puntero hacia donde se almacenara el codigo de vuelo ingresado
/// @param statusFlight: Puntero hacia donde se almacenara el estado de vuelo ingresado
/// @return int: 1 si alguno de los punteros es nulo o si no hay espacio en memoria suficiente, de lo contrario de vuelve un 0
int controller_editPassenger(Passenger* list, int cantidadPasajero, int ultimoId);

/// @brief Con esta funcion se puede eliminar algun dato de un pasajero
///
/// @pre
/// @post
/// @param list: Puntero al array en donde esta cargado el pasajero a eliminar
/// @param cantidadPasajero:
/// @param ultimoId:
/// @return int: -1 Si se cancelo la eliminacion del pasajero, 0 si se logro eliminar el pasajero con exito o
///1 si el puntero es nulo, si el id es menor a 1 o si la cantidad de pasajeros es menor a 1 o si hubo un error en la eliminacion del pasajero
int controller_removePassenger(Passenger* list, int cantidadPasajeros, int ultimoId);

/// @brief Con esta funcion se pueden ordenar los pasajeros de forma alfabetica ascendente por apellido y tipo de pasajero(Del mas caro al mas barato) o
/// de forma alfabetica ascendente por codigo de vuelo y estado de vuelo activo o Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio
/// promedio.
/// @pre
/// @post
/// @param list: Puntero al array en donde esta cargado los pasajeros a informar
/// @param cantidadPasajeros:
/// @return int: 1 si el puntero es nulo, si la cantidad de pasajeros es menor a 1 o si hubo un error en el informe, caso contrario devuelve 0
int controller_informPassenger(Passenger* list, int cantidadPasajeros);





