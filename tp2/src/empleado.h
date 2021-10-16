/*
 * empleado.h
 *
 *  Created on: 15 may. 2021
 *      Author: ledes
 */

#ifndef EMPLEADO_H_
#define EMPLEADO_H_


typedef struct{

	int id;
	char nombre[51];
	char apellido[51];
	float salario;
	int sector;
	int isEmpty;
}Empleado;


#endif /* EMPLEADO_H_ */


int menuInformes();
/** \brief llama al menu de informes y a la funcion elegida por el usuario
 * \return devuelve la opcion elegida por el usuario
 */
int menuEmpleados();
/** \brief llama al menu ABM y a la funcion elegida por el usuario
 * \return devuelve la opcion elegida por el usuario
 */
int menuModificar();
//docu opendiente me tenia que ir
int altaEmpleado(int idx, Empleado vec[], int tam);
//docu opendiente me tenia que ir
int buscarLibre(Empleado vec[], int tam);
//docu opendiente me tenia que ir

void inicializarEmpleados(Empleado vec[], int tam);
//docu opendiente me tenia que ir

void modificarEmpleado(Empleado vec[], int tam);

//docu opendiente me tenia que ir
int buscarEmpleado(int idx, Empleado vec[], int tam);
//docu opendiente me tenia que ir
void mostrarEmpleado(Empleado x);
//docu opendiente me tenia que ir
void mostrarEmpleados(Empleado [], int tam);
//docu opendiente me tenia que ir
void bajaEmpleado(Empleado vec[], int tam);
//docu opendiente me tenia que ir
void ordenarEmpleados(Empleado vec[], int tam);
//docu opendiente me tenia que ir
void informar(Empleado vec[], int tam);
//docu opendiente me tenia que ir


