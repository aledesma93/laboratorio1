/*
 * libro.c
 *
 *  Created on: 20 nov. 2021
 *      Author: aledesma
 */

#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include "libro.h"
#include "validaciones.h"
#include "LinkedList.h"
#include "editorial.h"
#include "controller.h"


eLibro* eLibro_new()
{
	eLibro* pLibro = (eLibro*)malloc(sizeof(eLibro));
	if(pLibro!= NULL)
	{
		eLibro_setId(pLibro,0);
		eLibro_setTitulo(pLibro,"");
		eLibro_setAutor(pLibro,"");
		eLibro_setPrecio(pLibro,0);
		eLibro_setIdEditorial(pLibro,0);
	}
	return pLibro;
}

eLibro* eLibro_newParametros(char* idStr,char* tituloStr,char* autorStr,char* precioStr,char* idEditorialStr)
{
	eLibro* pLibroParam;
	int auxId;
	int auxPrecio;
	int auxIdEditorial;
	pLibroParam = eLibro_new();
	if(pLibroParam != NULL && idStr != NULL && tituloStr !=NULL && autorStr != NULL && precioStr != NULL)
	{
		auxId = atoi(idStr);
		auxPrecio = atoi(precioStr);
		auxIdEditorial = atoi(idEditorialStr);
		eLibro_setId(pLibroParam, auxId);
		eLibro_setTitulo(pLibroParam, tituloStr);
		eLibro_setAutor(pLibroParam, autorStr);
		eLibro_setPrecio(pLibroParam, auxPrecio);
		eLibro_setIdEditorial(pLibroParam,auxIdEditorial);
	}

	return pLibroParam;
}

int eLibro_setId(eLibro* this,int id)
{
	int retorno = -1;
	if (this != NULL && id>=0)
	{
		this ->id = id;
		retorno = 0;
	}
	return retorno;
}
int eLibro_getId(eLibro* this,int* id)
{
	int retorno = -1;

	if (this != NULL && id != NULL)
	{
		*id=this->id;
		retorno = 0;
	}
	return retorno;
}

int eLibro_setTitulo(eLibro* this,char* titulo)
{
	int retorno = -1;
	if (this != NULL && titulo != NULL && VerificarNombre(titulo))
	{
		strcpy(this->titulo, titulo);
		retorno = 0;
	}
	return retorno;
}

int eLibro_getTitulo(eLibro* this,char* titulo)
{
	int retorno = -1;

	if (this != NULL && titulo != NULL)
	{
		strcpy(titulo,this->titulo);
		retorno = 0;
	}
	return retorno;
}

int eLibro_setAutor(eLibro* this, char* autor)
{
	int retorno = -1;
	if (this != NULL && autor != NULL && VerificarNombre(autor))
	{
		strcpy(this->autor, autor);
		retorno = 0;
	}
	return retorno;
}

int eLibro_getAutor(eLibro* this,char* autor)
{
	int retorno = -1;

	if (this != NULL && autor != NULL)
	{
		strcpy(autor,this->autor);
		retorno = 0;
	}
	return retorno;
}

int eLibro_setPrecio(eLibro* this,int precio)
{
	int retorno = -1;
	if (this != NULL && precio>=0)
	{
		this ->precio = precio;
		retorno = 0;
	}
	return retorno;
}
int eLibro_getPrecio(eLibro* this,int* precio)
{
	int retorno = -1;

	if (this != NULL && precio != NULL)
	{
		*precio=this->precio;
		retorno = 0;
	}
	return retorno;
}

int eLibro_setIdEditorial(eLibro* this,int idEditorial)
{
	int retorno = -1;
	if (this != NULL && idEditorial>=0)
	{
		this ->idEditorial = idEditorial;
		retorno = 0;
	}
	return retorno;
}
int eLibro_getIdEditorial(eLibro* this,int* idEditorial)
{
	int retorno = -1;

	if (this != NULL && idEditorial != NULL)
	{
		*idEditorial=this->idEditorial;
		retorno = 0;
	}
	return retorno;
}


void MostrarUnLibro(eLibro* UnLibro, LinkedList* thisEditorial)
{
	int id;
	char titulo[50];
	char autor[50];
	int precio;
	char nombreEditorial[50];

	eLibro_getId(UnLibro, &id);
	eLibro_getTitulo(UnLibro, titulo);
	eLibro_getAutor(UnLibro, autor);
	eLibro_getPrecio(UnLibro, &precio);
	Obtener_Editorial(UnLibro, thisEditorial, nombreEditorial);

	printf("%d %s %s %d %s\n",id,titulo,autor,precio,nombreEditorial);
}

int libro_compararPorAutor(void* lista1, void* lista2)
{
    int retorno;
    char autor1[25];
    char autor2[25];
    int retornoCmp;
    eLibro* aux1;
    eLibro* aux2;

    aux1 = (eLibro*) lista1;
    aux2 = (eLibro*) lista2;
    eLibro_getAutor(aux1, autor1);
    eLibro_getAutor(aux2, autor2);

    retornoCmp = strcmp(autor1, autor2);

    if(retornoCmp == 1)
    {
        retorno = 1;
    }
    else
    {
        if(retornoCmp == -1)
        {
            retorno = -1;
        }

    }

    return retorno;
}


int AplicarDescuentoLibro(void* unLibro)
{
	eLibro* auxLibro;
	int retorno;
	int id;
	int precio;
	int descuento;
	retorno = 0;

	if(unLibro != NULL)
	{
		auxLibro = (eLibro*)unLibro;
		eLibro_getIdEditorial(auxLibro, &id);
		eLibro_getPrecio(auxLibro, &precio);

		if(id == 1 && precio >= 300 ) //20%des editorial planeta
		{
			descuento = precio * 0.8;
			eLibro_setPrecio(auxLibro,descuento);
			retorno = 1;
		}
		else
		{
			if(id == 2 && precio <= 200)
			{
				descuento = precio * 0.9;
				eLibro_setPrecio(auxLibro,descuento); //10%de ed siglo
				retorno = 1;
			}
		}
	}
	return retorno;
}
