/*
 * validaciones.c
 *
 *  Created on: 13 oct. 2021
 *      Author: aledesma
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"



int MenuPrincipal (void)
{
	int opciones;

	printf("\n 1)Leer archivo con los datos de libros y guardarlos.\n 2)Leer archivo con los datos de editoriales y guardarlos.\n 3)Lista ordenada por Autor de manera ascendente.\n 4)Imprimir todos los datos de los libros mas el nombre de la editorial.\n"
	" 5)Listado de los libros de la editorial MINOTAURO.\n6)Salir.\n");

	scanf("%d",&opciones);
	return opciones;
}


int myGets (char* cadena,char mensaje[] ,int longitud) //char nombre [200] myGets(nombre,sizeof(nombre)) sizeof le manda el tamaño
{
	int retorno = -1;

	char bufferString [50];

	printf("%s",mensaje);

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno = 0;
			}
		}//leer de un archivo una cadena de caracteres
	}
	return retorno;
}

int getString(char* cadena, int limite)
{
	int retorno = -1;
	char bufferString[4096];

	if(cadena != NULL && limite > 0 && fgets(bufferString, sizeof(bufferString), stdin) != NULL)
	{
		fflush(stdin);
		if(bufferString[strlen(bufferString) - 1] == '\n')
		{
			bufferString[strlen(bufferString) - 1] = '\0';
		}
		strncpy(cadena, bufferString, limite);
		retorno = 0;
	}
	return retorno;
}


int getFloat(float *pflotante)
{
	int retorno = -1;
	char bufferInt[64];

	if(pflotante != NULL)
	{
		fflush(stdin);
		if(getString(bufferInt, sizeof(bufferInt)) == 0 && validarDecimal(bufferInt, sizeof(bufferInt)))
		{
			*pflotante = atof(bufferInt);
			retorno = 0;
		}
	}
	return retorno;
}
int utn_getNumeroFlotante( float * pNumero,char * pMensaje,char * pMensajeError,float min,float max,int reintentos)
{
	int retorno = -1;
	float bufferInt;

	if(pNumero != NULL && pMensaje != NULL && pMensajeError != NULL && reintentos >= 0 && min <= max)
	{
		do
		{
			printf("%s", pMensaje);
			fflush(stdin);
			if(getFloat(&bufferInt) == 0 && bufferInt >= min && bufferInt <= max)
			{
				retorno = 0;
				*pNumero = bufferInt;
				break;
			}

			reintentos--;
			printf("%s", pMensajeError);
		}while(reintentos > 0);

		if(reintentos == 0)
		{
			printf("Te quedaste sin intentos\n");
		}
	}
	return retorno;
}


int getInt(int* pResultado)
{
	int retorno = -1;
	char bufferInt[64];

	if(pResultado != NULL)
	{
		fflush(stdin);
		if(getString(bufferInt, sizeof(bufferInt)) == 0 && validarEntero(bufferInt, sizeof(bufferInt)))
		{
			*pResultado = atoi(bufferInt);
			retorno = 0;
		}
	}

	return retorno;
}
int utn_getNumero(int* pNumero, char* pMensaje, char* pMensajeError, int min, int max, int reintentos)
{
	int retorno = -1;
	int bufferInt;

	if(pNumero != NULL && pMensaje != NULL && pMensajeError != NULL && reintentos >= 0 && min <= max)
	{
		do
		{
			printf("%s", pMensaje);
			fflush(stdin);
			if(getInt(&bufferInt) == 0 && bufferInt >= min && bufferInt <= max)
			{
				retorno = 0;
				*pNumero = bufferInt;
				break;
			}

			reintentos--;
			printf("%s", pMensajeError);
		}while(reintentos > 0);

		if(reintentos == 0)
		{
			printf("Te quedaste sin intentos\n");
		}
	}
	return retorno;
}

int validarEntero(char* cadena, int limite)
{
	int retorno = -1;

	if(cadena != NULL && limite > 0)
	{
		retorno = 1;
		for(int i = 0; i < limite && cadena[i] != '\0'; i++)
		{
			if(i == 0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int validarDecimal(char* cadena, int limite)
{
	int retorno = -1;
	int punto = 0;

	if(cadena != NULL && limite > 0)
	{
		retorno = 1;
		for(int i = 0; i < limite && cadena[i] != '\0'; i++)
		{
			if(i == 0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}
			if(punto == 0 && cadena[i] == '.')
			{
				punto = 1;
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int esSoloLetras (char* cadena, int longitud){
	int retorno = 1;
	int i;
	if (cadena != NULL)
	{
		for (i= 0; cadena [i] != '\0'; i++)
		{
			if ((cadena[i] != ' ') && (cadena [i] < 'a' || cadena [i]> 'z') && (cadena [i]< 'A' || cadena [i]> 'Z'))
			{
				retorno = 0;
			}
			if(cadena[i]== '-')
				retorno = 1;
		}
	}
	return retorno;
}

int VerificarNombre(char cadena[])
{

    int esNombre;
    int longitud;

    esNombre = 1;
    longitud = strlen(cadena);

    for (int i = 0; i < longitud; i++)
    {
        if ((cadena[i] < 'a'||  cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] != ' '))
        {
            esNombre = 0;
        }
    }

    return esNombre;
}

int utn_getEntero(int* pEntero, int retry, char* msg, char*msgError, int min, int max)
{
    int isOk = -1;
    int auxInt;

    if(pEntero != NULL && msg != NULL && msgError != NULL && min <= max && retry >= 0)
    {
        printf("%s", msg);
        do
        {
            retry--;


            if(getInt(&auxInt) == 0 && auxInt >= min && auxInt <= max)
            {
                *pEntero = auxInt;
                isOk = 0; //exito
                break;
            }
            else
            {
                printf("%s", msgError);
            }
        }
        while(retry >= 0);
    }
    return isOk;
}

/*void SumarNumeros(int listaNumeros[],int tam)
{
	int i;
	int acumulador;
	acumulador = 0;
	for(i=0; i<tam ; i++)
	{
	 acumulador = acumulador + listaNumeros[i];
	}
	printf("La suma es: %d\n", acumulador);
}/

int IngresarEntero(char mensaje[])
{
	int unEntero;

	printf("%s\n",mensaje);
	scanf("%d", &unEntero);

	return unEntero;
	//entero que va a devolver la funcion, por eso tiene un int adelante

}


void mostrarNumero(float numero)// implementacion o desarrollo
{
	printf("el numero es: %.2f",numero );
}

float PedirFlotante(char mensaje[])
{
	int unFlotante;

	printf("%s\n",mensaje);
	scanf("%d", &unFlotante);

	return unFlotante;
}*/
