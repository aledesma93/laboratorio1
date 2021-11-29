/*
 * editorial.h
 *
 *  Created on: 20 nov. 2021
 *      Author: aledesma
 */

#ifndef EDITORIAL_H_
#define EDITORIAL_H_
#include "libro.h"

typedef struct
{
	int idEditorial;
	char nombre[50];
}eEditorial;

eEditorial* editorial_new (void);
eEditorial* editorial_newParametros (char* idStr,char* nombreStr);
int editorial_setIdEditorial(eEditorial* this, int idEditorial);
int editorial_getIdEditorial (eEditorial* this, int* idEditorial);
int editorial_setNombre(eEditorial* this, char* nombre);
int editorial_getNombre(eEditorial* this, char* nombre);
int Obtener_Editorial(eLibro* miLibro, LinkedList* pListaEditorial, char* nombreEditorial);
void MostrarEditorial(eEditorial* unaEditorial);
int ListEditorial(LinkedList* thisEditorial);


#endif /* EDITORIAL_H_ */
