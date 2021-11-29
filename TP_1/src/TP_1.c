/*
 ============================================================================
 Name        : TP_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"


int main()

{
	setbuf(stdout, NULL);
	char seguir = 's';
	int opcion;
	int A = 0;
	int B = 0;
	int factorial(int numero);
	float resultadoDividir;
	float resultadoSumar;
	float resultadoRestar;
	float resultadoMultiplicar;


	do {
		printf("\nIngrese una opcion:\n\n");
		printf("1- Ingresar 1er operando (A= %d)\n", A);
		printf("2- Ingresar 2do operando (B= %d)\n", B);
		printf("3- Calcular todas las operaciones\n");
		printf("4- Mostrar Resultados\n");
		printf("5- Salir\n");

		scanf("%d", &opcion);
		while (opcion < 1 || opcion > 5) {
			printf("ERROR,reingrese una opcion valida");
			scanf("%d", &opcion);
		}
		switch (opcion) {
		case 1:
			system("cls");
			printf("ingrese 1er operando: ");
			scanf("%d", &A);
			break;
		case 2:
			system("cls");
			printf("ingrese 2do operando: ");
			scanf("%d", &B);
			break;
		case 3:
			system("cls");
			printf("Se han realizado las operaciones, pulse 4 para mostrar los resultados\n");
			sumar(A, B, &resultadoSumar);
			restar(A, B, &resultadoRestar);
			multiplicar(A, B, &resultadoMultiplicar);
			dividir(A, B, &resultadoDividir);
			factorial(A);
			factorial(B);
			break;

		case 4:
			system("cls");
			printf("A=%d\nB=%d\n", A, B);
			printf("Resultado de la suma es: %f\n", resultadoSumar);
			printf("Resultado de la resta es: %f\n", resultadoRestar);
			printf("Resultado de la multiplicacion es: %f\n",resultadoMultiplicar);
			printf("Resultado de la division es: %.2f\n", resultadoDividir);
			printf("El factorial de A es %d \n", factorial(A));
			printf("El factorial de B es %d \n", factorial(B));
			break;
		case 5:
			system("cls");
			seguir = 'n';
			break;
		}
	} while (seguir == 's');


	return 0;
}
