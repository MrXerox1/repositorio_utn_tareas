/*
 ============================================================================
 Name        : clase_07.c
 Author      : Sergio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

int main(void)
{
	int numero;
	if(getIntArray(&numero, "ingrese numero","numero invalido",0,100,2)==0)
	{
		printf("get int me devolvio: %d",numero);
	}

	// para probar
	if(utn_esNumerica("+9")==0)
		printf("\nok");
	else
		printf("err");
	//____________




	return EXIT_SUCCESS;
}

int getIntArray(	int *pResultado,
		char *pMensaje,
		char *pMensajeError,
		int minimo,
		int maximo,
		int reintentos)
{
	int retorno = 0;
	int j;
	char input[50];
	int buffer;
	int length;


	for(j=0;j<reintentos;j++)
	{
		printf("%s",pMensaje);
		fgets(input, sizeof(input), stdin);
		length = strlen (input);
		input[length-1]='\0'; // saco enter

		retorno = utn_esNumerica(input);

		buffer = atoi(input);

		if(retorno==0 && buffer >= minimo && buffer <= maximo)
		{
			*pResultado = buffer;
			break;
		}
		else
		{
			retorno=-1;
		}
	}
	return retorno;
}

int utn_esNumerica(char input[])
{
	int length = strlen(input);
	int i,retorno;

	retorno = 0;
	for(i=0;i<length;i++)
	{
		if(input[i] < '0' || input[i] > '9')
		{
			if(input[i]=='-' && i==0)
			{
				continue;
			}
			if(input[i]=='+' && i==0)
			{
				continue;
			}
			retorno = -1;
			break;
		}
	}
	return retorno;
}
