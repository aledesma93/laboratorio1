/*
 * editorial.c
 *
 *  Created on: 20 nov. 2021
 *      Author: aledesma
 */
#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include "LinkedList.h"
#include "editorial.h"
#include "validaciones.h"
#include "libro.h"

eEditorial* editorial_new (void)
{
	eEditorial* pEditorial = (eEditorial*)malloc(sizeof(eEditorial));
	if (pEditorial !=NULL)
	{
		editorial_setIdEditorial(pEditorial,0);
		editorial_setNombre(pEditorial,"");
	}
	return pEditorial;
}

eEditorial* editorial_newParametros (char* idStr,char* nombreStr)
{
	eEditorial* pEditorialParam;
	int auxId;
	pEditorialParam = editorial_new();

	if (pEditorialParam != NULL && nombreStr != NULL && idStr != NULL )
	{
		auxId = atoi(idStr);
		editorial_setIdEditorial(pEditorialParam, auxId);
		editorial_setNombre(pEditorialParam, nombreStr);
	}

	return pEditorialParam;
}


int editorial_setIdEditorial(eEditorial* this, int idEditorial)
{
	int retorno = -1;
	if (this != NULL && idEditorial>=0)
	{
		this ->idEditorial = idEditorial;
		retorno = 0;
	}
	return retorno;
}

int editorial_getIdEditorial (eEditorial* this, int* idEditorial)
{
	int retorno = -1;

	if (this != NULL && idEditorial != NULL)
	{
		*idEditorial = this->idEditorial;
		retorno = 0;
	}

	return retorno;
}

int editorial_setNombre(eEditorial* this, char* nombre)
{
	int retorno = -1;
	if (this != NULL && nombre != NULL && VerificarNombre(nombre))
	{
		strcpy(this->nombre, nombre);
		retorno = 0;
	}
	return retorno;
}

int editorial_getNombre(eEditorial* this, char* nombre)
{
	int retorno = -1;
	if (this != NULL && nombre != NULL)
	{
		strcpy(nombre,this->nombre);
		retorno = 0;
	}
	return retorno;
}

int Obtener_Editorial(eLibro* miLibro, LinkedList* pListaEditorial, char* nombreEditorial)
{
	eEditorial* pEditorial;
    int retorno = 0;
    int lenEditorial;
    int idLibroEditorial; //ID DE EDITORIAL DEL LIBRO
    int idEditorial; // ID DE EDITORIAL PARA LA LISTA DE EDITORIALES

    lenEditorial = ll_len(pListaEditorial);

    if(miLibro != NULL && pListaEditorial != NULL && nombreEditorial != NULL)
    {
    	eLibro_getIdEditorial(miLibro, &idLibroEditorial);
        for(int i=0; i<lenEditorial; i++)
        {
        	pEditorial = ll_get(pListaEditorial, i);
        	editorial_getIdEditorial(pEditorial, &idEditorial);
            if(idLibroEditorial == idEditorial)
            {
            	editorial_getNombre(pEditorial, nombreEditorial);
                retorno = 1;
            }
        }
    }

    return retorno;
}

void MostrarEditorial(eEditorial* unaEditorial)
{
	int id;
	char nombreEditorial[50];

	editorial_getIdEditorial(unaEditorial, &id);
	editorial_getNombre(unaEditorial, nombreEditorial);

	printf("%d %s \n",id,nombreEditorial);
}

int ListEditorial(LinkedList* thisEditorial)
{
	int retorno = -1;
	eEditorial* pEditorial;
	int len;

	len= ll_len(thisEditorial);
	if(thisEditorial != NULL)
	{
		for(int i=0; i< len;i++)
		{
			pEditorial = (eEditorial*)ll_get(thisEditorial,i);
			MostrarEditorial(pEditorial);
			retorno = 1;
		}
	}
	return retorno;
}

