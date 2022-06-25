/*
 * array.c
 *
 *  Created on: 5 jun. 2022
 *      Author: thiag
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn.h"

int array_CompararCaracteresEspanolIngles(char primerCaracter, char segundoCaracter)
{
	int retorno;
	int banderaSwitch;
	char* auxiliarCaracterEspanol;
	char* auxiliarCaracterIngles;

	retorno=2;
	banderaSwitch=0;

	if(primerCaracter != '\0' && segundoCaracter != '\0')
	{
		retorno=0;

		if(!utn_VerificarSerLetra_ASCII_EXTEND(&primerCaracter) && utn_VerificarSerLetra_ASCII_EXTEND(&segundoCaracter))
		{
			auxiliarCaracterEspanol=&primerCaracter;
			auxiliarCaracterIngles=&segundoCaracter;
			banderaSwitch=1;
		}
		else
		{
			if(utn_VerificarSerLetra_ASCII_EXTEND(&primerCaracter) && !utn_VerificarSerLetra_ASCII_EXTEND(&segundoCaracter))
			{
				auxiliarCaracterEspanol=&segundoCaracter;
				auxiliarCaracterIngles=&primerCaracter;
				banderaSwitch=1;
			}
		}

		if(banderaSwitch)
		{
			switch(*auxiliarCaracterEspanol)
			{
				case '�':
					if(*auxiliarCaracterIngles> 'a')
					{
						*auxiliarCaracterEspanol='a';
					}
					else
					{
						if(*auxiliarCaracterIngles=='a')
						{
							*auxiliarCaracterEspanol='b';
						}
					}
					break;

				case '�':
					if(*auxiliarCaracterIngles> 'e')
					{
						*auxiliarCaracterEspanol='e';
					}
					else
					{
						if(*auxiliarCaracterIngles== 'e')
						{
							*auxiliarCaracterEspanol='f';
						}
					}

					break;

				case '�':
					if(*auxiliarCaracterIngles> 'i')
					{
						*auxiliarCaracterEspanol='i';
					}
					else
					{
						if(*auxiliarCaracterIngles== 'i')
						{
							*auxiliarCaracterEspanol='j';
						}
					}

					break;

				case '�':
					if(*auxiliarCaracterIngles> 'o')
					{
						*auxiliarCaracterEspanol='o';
					}
					else
					{
						if(*auxiliarCaracterIngles== 'o')
						{
							*auxiliarCaracterEspanol='p';
						}
					}

					break;

				case '�':
					if(*auxiliarCaracterIngles> 'u')
					{
						*auxiliarCaracterEspanol='u';
					}
					else
					{
						if(*auxiliarCaracterIngles== 'u')
						{
							*auxiliarCaracterEspanol='v';
						}
					}

					break;

				case '�':
					if(*auxiliarCaracterIngles> 'A')
					{
						*auxiliarCaracterEspanol='A';
					}
					else
					{
						if(*auxiliarCaracterIngles=='A')
						{
							*auxiliarCaracterEspanol='B';
						}
					}

					break;

				case '�':
					if(*auxiliarCaracterIngles> 'E')
					{
						*auxiliarCaracterEspanol='E';
					}
					else
					{
						if(*auxiliarCaracterIngles== 'E')
						{
							*auxiliarCaracterEspanol='F';
						}
					}
					break;

				case '�':
					if(*auxiliarCaracterIngles> 'I')
					{
						*auxiliarCaracterEspanol='I';
					}
					else
					{
						if(*auxiliarCaracterIngles== 'I')
						{
							*auxiliarCaracterEspanol='J';
						}
					}
					break;

				case '�':
					if(*auxiliarCaracterIngles> 'O')
					{
						*auxiliarCaracterEspanol='O';
					}
					else
					{
						if(*auxiliarCaracterIngles== 'O')
						{
							*auxiliarCaracterEspanol='P';
						}
					}
					break;

				case '�':
					if(*auxiliarCaracterIngles> 'U')
					{
						*auxiliarCaracterEspanol='U';
					}
					else
					{
						if(*auxiliarCaracterIngles== 'U')
						{
							*auxiliarCaracterEspanol='V';
						}
					}
					break;

				case '�':
					if(*auxiliarCaracterIngles> 'n')
					{
						*auxiliarCaracterEspanol='n';
					}
					else
					{
						if(*auxiliarCaracterIngles== 'n')
						{
							*auxiliarCaracterEspanol='o';
						}
					}
					break;

				case '�':
					if(*auxiliarCaracterIngles> 'N')
					{
						*auxiliarCaracterEspanol='N';
					}
					else
					{
						if(*auxiliarCaracterIngles== 'N')
						{
							*auxiliarCaracterEspanol='O';
						}
					}
					break;
			}
		}
		if(primerCaracter<segundoCaracter)
		{
			retorno=-1;
		}
		else
		{
			if(segundoCaracter<primerCaracter)
			{
				retorno=1;
			}
		}
	}

	return retorno;
}

int array_CompararCadenaCaracteresEspanolInles(char* primeraCadena, char* segundaCadena)
{
	int retorno;
	int longitudPrimeraCadena;
	int longitudSegundaCadena;

	retorno=2;

	if(primeraCadena!=NULL && segundaCadena!=NULL)
	{
		retorno=0;
		longitudPrimeraCadena = strlen(primeraCadena);
		longitudSegundaCadena = strlen(segundaCadena);

		for(int i=0;i<longitudPrimeraCadena && i<longitudSegundaCadena;i++)
		{
			retorno = array_CompararCaracteresEspanolIngles(*(primeraCadena+i), *(segundaCadena+i));
			if(retorno!=0)
			{
				break;
			}
		}
	}

	return retorno;
}

