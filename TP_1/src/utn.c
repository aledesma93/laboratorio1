/*
 * utn.c
 *
 *  Created on: 24 sep. 2021
 *      Author: ledes
 */


#include <stdio.h>
#include <stdlib.h>
/*
 * \brief realiza una division de dos numeros .
 * \param numeroA con el preimer numero.
 * \param numeroA con el segundo nmumero.
 * *\param pResultado con el puntero del resultado.
 * \return -1 (falso) si no se puede realizar. 0  si se puede.
 */
float dividir(float numeroA, float numeroB, float *pResultado) {

	int retorno = -1;

		if (numeroB != 0 && pResultado != NULL)
		{
			*pResultado = numeroA / numeroB;
			retorno = 0;
		}

		return retorno;
}
/*
 * \brief realiza una suma de dos numeros .
 * \param numeroA con el preimer numero.
 * \param numeroA con el segundo nmumero.
 * *\param pResultado con el puntero del resultado.
 * \return -1 (falso) si no se puede realizar. retorno  si se puede.
 */
int sumar(int numeroA, int numeroB, float *pResultado) {

	int retorno = -1;
		if(pResultado != NULL)
		{
			*pResultado = numeroA+numeroB;
			retorno = 0;
		}

		return retorno;

}
/*
 * \brief realiza una resta de dos numeros .
 * \param numeroA con el preimer numero.
 * \param numeroA con el segundo nmumero.
 * *\param pResultado con el puntero del resultado.
 * \return -1 (falso) si no se puede realizar. retorno si se puede.
 */
int restar(int numeroA, int numeroB, float *pResultado) {

	int retorno = -1;
		if(pResultado != NULL)
		{
			*pResultado = numeroA-numeroB;
			retorno = 0;

		}
		return retorno;
}
/*
 * \brief realiza una multiplicacion de dos numeros .
 * \param numeroA con el preimer numero.
 * \param numeroA con el segundo nmumero.
 * *\param pResultado con el puntero del resultado.
 * \return -1 (falso) si no se puede realizar. retorno  si se puede.
 */
int multiplicar(int numeroA, int numeroB, float *pResultado) {

	int retorno = -1;
		if(numeroA != 0 && numeroB != 0 && pResultado != NULL)
		{
			*pResultado = numeroA*numeroB;
			retorno = 0;
		}

		return retorno;

}
/*
 * \brief realiza una factorizacion .
 * \param numero con el preimer numero.
 * \return resultado si s epuede realizar , retorna 1 si no es correcto.
 */
int factorial(int numero) {
	int resultado;

	if (numero >= 1) {
		resultado = (numero * factorial(numero - 1));
		return resultado;
	} else {
		return 1;
	}
}
/*
 * \brief comprueba datos ingresados.
 * \param pDatoIngresado con el dato.
 * \param pTexto con el texto que imprime al usuario.
 * \param min con la menor cantidad de opciones.
 * \param max  con la mayor cantidad de opciones.
 * \param reintentos asigna reintentos del usuario.
 * \return retorno si se puede realizar , retorna -1 si no es correcto.
 */
int utn_getInt(int *pDatoIngresado, char *pTexto, char *pTextoError, int min,
		int max, int reintentos) {
	int retorno = -1;

	for (int i = 0; reintentos >= i; reintentos--) {
		printf("%s\n", pTexto);
		fflush(stdin);
		if (scanf("%d", pDatoIngresado) == 1) {
			if (min <= max && (*pDatoIngresado) >= min
					&& (*pDatoIngresado) <= max) {
				retorno = 0;
				break;
			} else {
				printf("%s\n", pTextoError);
			}
		} else {
			printf("%s\n", pTextoError);
		}
	}
	return retorno;
}

