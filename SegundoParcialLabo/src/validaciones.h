/*
 * validaciones.h
 *
 *  Created on: 13 oct. 2021
 *      Author: Ludo
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/// @brief Se imprimen opciones al usuario, este ingresa un numero correspondiente a la opcion y valida que el numero
/// ingresado corresponda a una opcion
///
/// @return retorna la opcion elegida por el usuario
int MenuPrincipal (void);
int utn_getEntero(int* pEntero, int retry, char* msg, char*msgError, int min, int max);


/// @brief Esta funcion le pide al usuario que ingrese un determinado dato como cadena, mide su longitud y donde hay un enter pone
/// un /0
///
/// @param cadena: Recibe una cadena como puntero que es lo ingresado por el usuario
/// @param mensaje: mensaje donde le pido al usuario el dato a ingresar
/// @param longitud: longitud de la cadena
/// @return
int myGets (char* cadena,char mensaje[], int longitud);

/// @brief Pide un texto al usuario y se encarga de que no quede un enter en el buffer
///
/// @param cadena Puntero donde se almacenará el texto ingresado
/// @param limite Limite o tamaño de la cadena
/// @return Retorna 0 (EXITO) si se obtiene el texto o -1 (ERROR)
int getString(char* cadena, int limite);

/// @brief Valida que la cadena recibida contenga solamente números enteros
///
/// @param cadena Cadena de caracteres a ser analizada
/// @param limite El limite o tamaño de la cadena
/// @return Retorna 1 (verdadero) si la cadena es numérica, 0 (falso) si no o -1 si hubo algún error con los argumentos
int validarEntero(char* cadena, int limite);

/// @brief Transforma una cadena de caractéres a números del tipo int
///
/// @param pResultado Puntero donde se almacenará el número ingresado
/// @return Retorna 0 (EXITO) si puede transformar la cadena o -1 (ERROR)
int getInt(int* pResultado);

/// @brief  Le pide al usuario un número entero entre un rango con reintentos
///
/// @param pResultado Puntero donde se almacenará el número ingresado
/// @param mensaje Texto para que el usuario sepa que ingresar
/// @param mensajeError Texto que nos informa de un error
/// @param minimo El rango mínimo para ingresar un número
/// @param maximo El rango máximo para ingresar un número
/// @param reintentos Los reintentos que tiene el usuario para poner números correctos
/// @return Retorna 0 (EXITO) si se obtiene un número entre el rango o -1 (ERROR)
int utn_getNumero( int * pResultado,char * mensaje,char * mensajeError,int minimo,int maximo,int reintentos);

/// @brief Valida que la cadena recibida contenga solamente números decimales positivos o negativos
///
/// @param cadena Cadena de caracteres a ser analizada
/// @param limite El limite o tamaño de la cadena
/// @return Retorna 1 (verdadero) si la cadena es decimal, 0 (falso) si no o -1 si hubo algún error con los argumentos
int validarDecimal(char* cadena, int limite);

/// @brief Transforma una cadena de caractéres a números del tipo float
///
/// @param pflotante Puntero donde se almacenará el número ingresado
/// @return Retorna 0 (EXITO) si puede transformar la cadena o -1 (ERROR)
int getFloat(float *pflotante);

/// @brief Le pide al usuario un número decimal entre un rango con reintentos
///
/// @param pResultado Puntero donde se almacenará el número ingresado
/// @param mensaje Texto para que el usuario sepa que ingresar
/// @param mensajeError Texto que nos informa de un erro
/// @param minimo El rango mínimo para ingresar un número
/// @param maximo El rango máximo para ingresar un número
/// @param reintentos Los reintentos que tiene el usuario para poner números correctos
/// @return  Retorna 0 (EXITO) si se obtiene un número decimal entre el rango o -1 (ERROR)
int utn_getNumeroFlotante( float * pResultado,char * mensaje,char * mensajeError,float minimo,float maximo,int reintentos);

int esSoloLetras (char* cadena, int longitud);
int VerificarNombre(char cadena[]) ;
int utn_getEntero(int* pEntero, int retry, char* msg, char*msgError, int min, int max);

//void SumarNumeros(int[],int);
//int IngresarEntero(char[]);
//float PedirFlotante(char mensaje[]);

#endif /* VALIDACIONES_H_ */
