/*
 * parser.h
 *
 *  Created on: 11 nov. 2021
 *      Author: Ludo
 */

#ifndef PARSER_H_
#define PARSER_H_
#include "LinkedList.h"
#include "Controller.h"
#include "libro.h"
#include "editorial.h"

int parser_LibrofromText(FILE* pFile , LinkedList* pListLibro);
int parser_EditorialfromText(FILE* pFile , LinkedList* pListEditorial);
void guardarArchivo(LinkedList* lista, char* archivo);



//int parser_fromBinary(FILE* pFile , LinkedList* pArrayList);

#endif /* PARSER_H_ */
