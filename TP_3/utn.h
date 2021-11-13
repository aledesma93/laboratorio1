/*
 * utn.h
 *
 *  Created on: Apr 6, 2020
 *      Author: aledesma
 */

#ifndef UTN_H_
#define UTN_H_

//------------F I R M A S   D E   B I B L I O T E C A    U T N -------------------------------------------------
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int utn_getDescripcion(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int utn_getDni(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);

int esDescripcion(char* cadena,int longitud);
int esNombre(char* cadena,int longitud);
int esFlotante(char* cadena);
int esNumerica(char* cadena, int limite);
//------------------------------------------------------------------------------------------------------------


//------------VALIDACIONES ESPECIFICAS DE LOS CAMPOS DE EMPLOYEE. (VALIDACIONES DE CADENA Y DE INT)----------

//================ C A D E N A S =====================
int esIdValido (char* arrayId, int longitudArrayId);
int esNombreValido (char* pCadenaAVerificar, int longitudCadenaAVerificar);
int esSueldoValido (char* arraySueldoValido, int longitudArraySueldoValido);
int esHoraTrabajadaValida (char* arrayHorasTrabajadas, int longitudArrayHorasTrabajadas);
//================== I N T S ==========================
int esIdValidoInt (int id);
int esSueldoValidoInt (int sueldo);
int esHoraTrabajadaValidaInt (int horasTrabajadas);
//-------------------------------------------------------------------------------------------------------------


//---------------FUNCIONES EXTRAS-------------
int utn_obtener_orden_si_no (char* mensajePedido, char* mensajeError, int reintentos);
void printMenuPrincipal (void);
void printDespedida (void);
//-------------------------------------------


#endif /* UTN_H_ */
