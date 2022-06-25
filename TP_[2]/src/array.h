/*
 * array.h
 *
 *  Created on: 5 jun. 2022
 *      Author: thiag
 */

#ifndef ARRAY_H_
#define ARRAY_H_

/// @brief Con esta funcion se pueden comparar 2 caracteres segun el abecedario español
///Las letras con acento valen mas que su version sin acento, pero menos que la letra que le sigue a la sin acento. Valor: a<á<b
/// @pre
/// @post
/// @param primerCaracter
/// @param segundoCaracter
/// @return int: 0 si los dos caracteres son iguales o si alguno almacena un NULL, 1 si el primero es mayor al segundo o -1 si el segundo es mayor que el primero
int array_CompararCaracteresEspanolIngles(char primerCaracter, char segundoCaracter);

/// @brief Compara 2 cadenas de caracteres segun el abecedario español
///
/// @pre
/// @post
/// @param primeraCadena: Puntero a la primer cadena
/// @param segundaCadena: Puntero a la segunda cadena
/// @return int: 2 si alguno de los punteros es nulo, 0 si ambas cadenas son iguales, 1 si el la primera es mayor que la segunda o -1 si la segunda es mayor que la primera
int array_CompararCadenaCaracteresEspanolInles(char* primeraCadena, char* segundaCadena);

#endif /* ARRAY_H_ */
