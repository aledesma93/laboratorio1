#include "libro.h"
#include "editorial.h"
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"

int controller_LibroLoadFromText(char* path , LinkedList* pArrayList);
int controller_EditorialLoadFromText(char* path , LinkedList* pArrayList);

int controller_ListLibro(LinkedList* thisLibro ,LinkedList* thisEditorial);

int controller_ordenarLibrosPorAutor(LinkedList* pListaLibros);
int filtrarMinotauro(void* unLibro);
int filtrarEditorial(LinkedList* lista);
int filtrarPlaneta(LinkedList* lista);
int controller_saveAsTextMinotauro(char* path , LinkedList* listaLibros);
int controller_obtenerEditorial(eLibro* miLibro, LinkedList* listaEditorial, char* descEdit);
int controller_saveAsTextDesc(char* path , LinkedList* listaLibros);


int controller_aplicarDescuentos(LinkedList* listaLibros, LinkedList* listaEditorial);
int controller_guardarMapeado(char* path, LinkedList* listaLibros, LinkedList* listaEditorial);
int controller_validarDescuento(LinkedList* listaEditorial, void* l1);

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);




