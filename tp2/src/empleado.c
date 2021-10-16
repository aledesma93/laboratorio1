/*
 * empleado.c
 *
 *  Created on: 15 may. 2021
 *      Author: ledes
 */


#include "empleado.h"
#include "utn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menuEmpleados(){
	system("cls");
	int opcion;


	printf("*****MENU OPCIONES*****\n\n");
	printf("1. Alta empleado\n");
	printf("2. Modificar empleado\n");
	printf("3. Baja empleado\n");
	printf("4. Listar empleado\n");
	printf("5. Salir\n\n");
	printf("Ingrese opcion deseada: ");

	scanf("%d",&opcion);

	return opcion;

}

int altaEmpleado(int idx, Empleado vec[], int tam){

	int todoOk=-1;
	Empleado auxEmpleado;
	int indice;
	float auxFloat;
	char auxChar[51];
	int auxInt;




	indice = buscarLibre(vec,tam);

	if(indice==-1){
		printf("Sistema completo\n\n");
	}else{
		while(todoOk==-1){

			if((utn_getCadena(auxChar,51,3,"Ingrese su nombre: ","Nombre no valido. Reingrese\n"))==0){
				strcpy(auxEmpleado.nombre, auxChar);
			}else{
				printf("Se quedo sin intentos\n");
				todoOk=0;
				break;
			}

			if((utn_getCadena(auxChar,51,3,"Ingrese su apellido: ","Apellido no valido. Reingrese\n"))==0){
				strcpy(auxEmpleado.apellido,auxChar);
			}else{
				printf("Se quedo sin intentos\n");
				todoOk=0;
				break;
			}

			if((utn_getFlotante(&auxFloat,3,"Ingrese salario: ", "Salario no valido. Reigrese\n",1,999999999))==0){
				auxEmpleado.salario=auxFloat;
			}else{
				printf("Se quedo sin intentos\n");
				todoOk=0;
				break;
			}

			if((utn_getEntero(&auxInt,3,"Ingrese sector: ","Sector no valido. Reingrese\n",0,999999999))==0){
				auxEmpleado.sector=auxInt;
				todoOk=1;
			}else{
				printf("Se quedo sin intentos\n");

				break;
			}



		}
		if(todoOk==1){
			auxEmpleado.id=idx;
			auxEmpleado.isEmpty=0;
			vec[indice]=auxEmpleado;
			printf("\n\nEl ID del nuevo empleado es: %d\n ",idx);
		}
	}

	return todoOk;

}


int buscarLibre(Empleado vec[], int tam){

	int indice=-1;

	for(int i=0; i<tam;i++){
		if(vec[i].isEmpty==1){
			indice=i;
			break;
		}
	}
	return indice;
}


void inicializarEmpleados(Empleado vec[], int tam){

	for(int i=0;i<tam;i++){

		vec[i].isEmpty=1;
	}
}

void modificarEmpleado(Empleado vec[], int tam){

	int indice;
	char confirma;
	int id;
	char auxChar[51];
	int auxInt;
	float auxFloat;

		printf("Ingrese ID de empleado: ");
		scanf("%d",&id);

	indice=buscarEmpleado(id,vec,tam);

	if (indice==-1){
		printf("No hay ningun empleado con el id:%d ",id);

	}else{
		printf("ID     NOMBRE     APELLIDO     SALARIO     SECTOR     \n\n");
		mostrarEmpleado(vec[indice]);
		printf("Desea modificar este empleado? (s/n): ");
		fflush(stdin);
		scanf("%c",&confirma);
		if(confirma=='s'){

			switch(menuModificar()){

				case '1':
					utn_getCadena(auxChar,51,3,"Ingrese nuevo nombre: ","Nombre no valido. Reingrese\n");
					strcpy(vec[indice].nombre,auxChar);
					system("cls");
					printf("Se actualizo el nombre\n");
					break;
				case '2':
					utn_getCadena(auxChar,51,3,"Ingrese nuevo apellido: ","Apellido no valido. Reingrese\n");
					strcpy(vec[indice].apellido,auxChar);
					system("cls");
					printf("Se actualizo el apellido\n");
					break;
				case '3':
					utn_getFlotante(&auxFloat,3,"Ingrese nuevo salario: ", "Salario no valido. Reingrese\n",1,999999999);
					vec[indice].salario=auxFloat;
					system("cls");
					printf("Se actualizo el salario\n");
					break;
				case '4':
					utn_getEntero(&auxInt,3,"Ingrese nuevo sector: ","Sector no valido. Reingrese\n",0,999999999);
					vec[indice].sector=auxInt;
					system("cls");
					printf("Se actualizo el sector\n");
					break;



			}




		}

	}










}

int buscarEmpleado(int idx, Empleado vec[], int tam){

	int indice=-1;

		for(int i=0; i<tam;i++){
			if(vec[i].id==idx && vec[i].isEmpty==0){
				indice=i;
				break;
			}
		}
		return indice;
}

void mostrarEmpleado(Empleado x){

	printf("%d      %s     %s     %.2f     %d     \n\n",x.id,x.nombre,x.apellido,x.salario,x.sector);



}

void mostrarEmpleados(Empleado vec[], int tam){
	int flag=0;

	printf("LISTA DE EMPLEADOS\n\n");
	printf("ID     NOMBRE     APELLIDO     SALARIO     SECTOR     \n\n");

	for(int i=0;i<tam;i++){
		if(vec[i].isEmpty==0){

			mostrarEmpleado(vec[i]);
			flag=1;
		}


	}
	if (flag==0){

		printf("No hay empleados que listar\n");
	}

}

int menuModificar(){
	system("cls");
	char opcion;
	printf("1. Modificar nombre\n");
	printf("2. Modificar apellido\n");
	printf("3. Modificar salario\n");
	printf("4. Modificar sector\n\n");
	printf("Ingrese opcion deseada: ");
	fflush(stdin);
	scanf("%c",&opcion);

	return opcion;
}

void bajaEmpleado(Empleado vec[], int tam){

	int id;
	int indice;
	char confirma;


		printf("Ingrese ID de empleado: ");
		scanf("%d",&id);

	indice=buscarEmpleado(id,vec,tam);

	if (indice==-1){
		printf("No hay ningun empleado con el id:%d ",id);

	}else{
		printf("ID     NOMBRE     APELLIDO     SALARIO     SECTOR     \n\n");
		mostrarEmpleado(vec[indice]);
		printf("Desea eliminar este empleado? (s/n): ");
		fflush(stdin);
		scanf("%c",&confirma);
		if(confirma=='s'){
			vec[indice].isEmpty=1;
			printf("Se ha realizado la baja con exito.\n");

		}else{

			printf("\nSe cancelo la operacion\n\n");

		}
}
}

void ordenarEmpleados(Empleado list[], int tam){

	Empleado auxEmpleado;

    for(int i=0; i<tam -1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            {
            	if(list[i].isEmpty==0 && list[i].sector>list[j].sector){

            		auxEmpleado=list[i];
            		list[i]=list[j];
            		list[j]=auxEmpleado;

            	}else
            		if(list[i].sector == list[j].sector && strcmp(list[i].apellido,list[j].apellido)>0){

            		auxEmpleado=list[i];
            		list[i]=list[j];
            		list[j]=auxEmpleado;
            	}
            }
        }
    }

    mostrarEmpleados(list,tam);
}

    int menuInformes()
    {
	int opcion;
	system("cls");
	printf("1. Listado de empleados ordenados por sector y apellido\n");
	printf("2. Total y promedio de los salarios, y cuantos empleados superan el salario promedio\n\n");
	printf("Ingrese opcion deseada: ");
	scanf("%d",&opcion);

	return opcion;
}

    void informar(Empleado vec[],int tam)
{
			char seguir='s';
			do{
				switch(menuInformes()){
				case 1:
					ordenarEmpleados(vec,tam);
					system("pause");
					break;
				case 2:
					printf("no lo termine");
					system("pause");
					break;
				default:
					printf("Opcion no valida \n\n");
					break;
				}
				fflush(stdin);
			}while(seguir=='s');
}
