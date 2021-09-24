/*
 * utn.h
 *
 *  Created on: 24 sep. 2021
 *      Author: ledes
 */

#ifndef UTN_H_
#define UTN_H_
float dividir(float numeroA, float numeroB, float *pResultado);
int sumar(int numeroA, int numeroB, float *pResultado);
int restar(int numeroA, int numeroB, float *pResultado);
int multiplicar(int numeroA, int numeroB, float *pResultado);
int factorial(int numero);
int utn_getInt(int *pDatoIngresado, char *pTexto, char *pTextoError, int min,
		int max, int reintentos);
int getMenu(int *pResultado, char *mensaje, char *mensajeError, int minimo,
		int maximo, int intentos);



#endif /* UTN_H_ */
