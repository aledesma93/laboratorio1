/*
 * libro.h
 *
 *  Created on: 20 nov. 2021
 *      Author: Ludo
 */

#ifndef LIBRO_H_
#define LIBRO_H_
#include "LinkedList.h"

typedef struct
{
	int id;
	char titulo[50];
	char autor[50];
	int precio;
	int idEditorial;
}eLibro;

eLibro* eLibro_new();
eLibro* eLibro_newParametros(char* idStr,char* tituloStr,char* autorStr,char* precioStr,char* idEditorialStr);


int eLibro_setId(eLibro* this,int id);
int eLibro_getId(eLibro* this,int* id);

int eLibro_setTitulo(eLibro* this,char* titulo);
int eLibro_getTitulo(eLibro* this,char* titulo);

int eLibro_setAutor(eLibro* this,char* autor);
int eLibro_getAutor(eLibro* this,char* autor);

int eLibro_setPrecio(eLibro* this,int precio);
int eLibro_getPrecio(eLibro* this,int* precio);

int eLibro_setIdEditorial(eLibro* this,int idEditorial);
int eLibro_getIdEditorial(eLibro* this,int* idEditorial);

void MostrarUnLibro(eLibro* UnLibro, LinkedList* thisEditorial);
int libro_compararPorAutor(void* lista1, void* lista2);
void eLibro_delete();

#endif /* LIBRO_H_ */
