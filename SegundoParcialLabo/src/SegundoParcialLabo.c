/*
 ============================================================================
 Name        : SegundoParcialLabo.c
 Author      : Ludmila
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "validaciones.h"
#include "libro.h"
#include "editorial.h"
#include "controller.h"
#include "parser.h"

int main(void)
{
	setbuf(stdout,NULL);
    char salir;
    salir = 'n';
    //creo la lista, aun no esta creada en memoria, por eso llamo a new:
    LinkedList* listaLibros = ll_newLinkedList();
    LinkedList* listaEditorial = ll_newLinkedList();
    //LinkedList* lista = ll_newLinkedList();

    do{
		switch(MenuPrincipal())
		{
			case 1://Leer un archivo con los datos de libros, guardándolos en un linkedList de entidades eLibro.
				controller_LibroLoadFromText("libros.csv",listaLibros);
				break;
			case 2://Leer un archivo con los datos de editoriales, guardándolos en un linkedList de entidades eEditorial.
				controller_EditorialLoadFromText("editorial.csv",listaEditorial );
				break;
			case 3://Ordenar la lista generada en el ítem anterior, con la función ll_sort, según el criterio de ordenamiento “Autor” de manera ascendente
				//controller_addEmployee();
				controller_ordenarLibrosPorAutor(listaLibros);
				break;
			case 4://Imprimir por pantalla todos los datos de los libros. ACLARACIÓN: Se deberá imprimir la descripción de la editorial
				controller_ListLibro(listaLibros,listaEditorial);
				break;
			case 5://Realizar un listado de los libros de la editorial MINOTAURO. Para ello deberá utilizar la función ll_filter* del LinkedList. Guardar el listado en un archivo csv.

				system("cls");
				if(controller_saveAsTextMinotauro("listaMinotauro.csv", listaLibros))
				{
					printf("Archivo filtrado guardado\n");
				}
				else
				{
					printf("Error al filtrar archivo\n");
				}
				system("pause");
				break;

			case 6:
				 controller_aplicarDescuentos(listaLibros, listaEditorial);
				 break;
			case 7:
				 controller_guardarMapeado("mapeado.csv", listaLibros, listaEditorial);
				break;
			case 8:
				printf("Confirma salida s/n: \n");
				fflush(stdin);
				scanf("%c",&salir);
				break;
		   default:
				printf("Error,opcion invalida \n");
		}
	  }while(salir != 's');
    printf("Vuelva prontos...");

    return EXIT_SUCCESS;
}

