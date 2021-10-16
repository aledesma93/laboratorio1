/*
 ============================================================================
 Name        : TP2.c
 Author      : aledesma
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include <string.h>
#include "empleado.h"
#define LISTA 1000

int main(void) {

	setbuf(stdout,NULL);
	char seguir='s';
	char confirma;
	int proximoId=1;
	int flagAlta=0;
	Empleado listaEmpleados[LISTA];
	inicializarEmpleados(listaEmpleados,LISTA);


	do{
		switch(menuEmpleados()){

		case 1:
			if(altaEmpleado(proximoId,listaEmpleados,LISTA)){
				proximoId++;
				flagAlta=1;
			}
			break;

		case 2:
			if(flagAlta){

				modificarEmpleado(listaEmpleados,LISTA);
			}else
			{
				printf("No hay existen empleados para modificar\n");
			}
			break;
		case 3:
			if(flagAlta){

				bajaEmpleado(listaEmpleados,LISTA);
			}else{
				printf("No existen empleados para eliminar\n");
			}

			break;
		case 4:
			if(flagAlta){
				informar(listaEmpleados,LISTA);
			}else{
				printf("Debe ingresar un empleado para poder listarlos\n");
			}
			break;
		case 5:
			printf("Desea salir? (s/n): ");
			fflush(stdin);
			scanf("%c", &confirma);
			if(confirma=='s'){

				seguir='n';

			}else{

				printf("\nSe cancelo la operacion\n\n");
			}

			break;
		default:
			printf("Opcion invalida. \n");

			break;


		fflush(stdin);




		}
		system("pause");
	}while(seguir=='s');

	return EXIT_SUCCESS;
}
