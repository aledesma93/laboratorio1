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

int factorial(int numero);
float resultadoDividir;
float resultadoSumar;
float resultadoRestar;
float resultadoMultiplicar;

int main()

{
	setbuf(stdout, NULL);
	char seguir = 's';
	int opcion;
	int A = 0;
	int B = 0;

	do {
		printf("\nIngrese una opcion:\n\n");
		printf("1- Ingresar 1er operando (A= %d)\n", A);
		printf("2- Ingresar 2do operando (B= %d)\n", B);
		printf("3- Calcular la suma (A+B)\n");
		printf("4- Calcular la resta (A-B)\n");
		printf("5- Calcular la multiplicacion (A*B)\n");
		printf("6- Calcular la division (A/B)\n");
		printf("7- Calcular el factorial (A!)\n");
		printf("8- Calcular todas las operacione\n");
		printf("9- Salir\n");

		scanf("%d", &opcion);
		while (opcion < 1 || opcion > 9) {
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
			sumar(A, B, &resultadoSumar);
			printf("Resultado de la suma es: %f\n",resultadoSumar);
			break;
		case 4:
			system("cls");
			restar(A, B, &resultadoRestar);
			printf("Resultado de la resta es: %f\n",resultadoRestar);
			break;
		case 5:
			system("cls");
			multiplicar(A, B, &resultadoMultiplicar);
			printf("Resultado de la multiplicacion es: %f\n",resultadoMultiplicar);
			break;
		case 6:
			system("cls");
			dividir(A, B, &resultadoDividir);
			printf("Resultado de la division es: %.2f\n",resultadoDividir);
			break;
		case 7:
			system("cls");
			printf("E factorial de A es %d", factorial(A));
			break;
		case 8:
			system("cls");
			printf("A=%d\nB=%d\n", A, B);
			printf("Resultado de la suma es: %f\n", resultadoSumar);
			printf("Resultado de la resta es: %f\n", resultadoRestar);
			printf("Resultado de la multiplicacion es: %f\n",resultadoMultiplicar);
			printf("Resultado de la division es: %.2f\n", resultadoMultiplicar);
			printf("El factorial de A es %d", factorial(A));
			printf("El factorial de B es %d", factorial(B));
			break;
		case 9:
			system("cls");
			seguir = 'n';
			break;
		}
	} while (seguir == 's');


	return 0;
}
