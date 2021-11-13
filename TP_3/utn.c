
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "utn.h"

	//----------FIRMAS ESTATICAS DEL UTN.C---------------------
	static int getInt(int* pResultado);
	static int getFloat(float* pResultado);
	static int getString(char* cadena, int longitud);
	static int getNombre(char* pResultado,int longitud);
	static int getDescripcion(char* pResultado, int longitud);
	//---------------------------------------------------------



	void printMenuPrincipal (void)
	{
		printf("\n"
				"1) Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n" //SE HACER
				"2) Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n"
				"3) Alta de empleado.\n" //SE HACER
				"4) Modificar datos de empleado.\n"
				"5) Baja de empleado.\n"
				"6) Listar empleados.\n"
				"7) Ordenar empleados.\n"
				"8) Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
				"9) Guardar los datos de los empleados en el archivo data.bin (modo binario).\n"
				"10) Salir.\n\n");
	}


	/*
	 * \brief Imprime despedida.
	 * \return Retorna vacio/void.
	 */
	void printDespedida (void)
	{
		printf("\n Aplicacion finalizada. :) \n");
	}


	/**
	 * \brief 	Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena un maximo de 'longitud - 1' caracteres.
	 * \param cadena char* Puntero al espacio de memoria donde se copiara la cadena obtenida
	 * \param longitud int Define el tamaño de cadena
	 * \return int Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
	 */
	static int getString(char* cadena, int longitud)
	{
		int retorno=-1;
		char bufferString[4096]; // *****************************

		if(cadena != NULL && longitud > 0)
		{
			fflush(stdin);
			if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
			{
				if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
				{
					bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
				}
				if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
				{
					strncpy(cadena,bufferString,longitud);
					retorno=0;
				}
			}
		}
		return retorno;
	}


	/**
	 * \brief Obtiene un numero entero.
	 * \param pResultado int* Puntero al espacio de memoria donde se dejara el resultado de la funcion
	 * \return int Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
	 */
	static int getInt(int* pResultado)
	{
		int retorno=-1;
		char bufferString[50];
		if(	pResultado != NULL &&
			getString(bufferString,sizeof(bufferString)) == 0 &&
			esNumerica(bufferString,sizeof(bufferString)))
		{
			retorno=0;
			*pResultado = atoi(bufferString) ;

		}
		return retorno;
	}


	/**
	 * \brief Verifica si la cadena ingresada es numerica.
	 * \param cadena char* Cadena de caracteres a ser analizada.
	 * \return int Retorna 1 (verdadero) si la cadena es numerica, 0 (falso) si no lo es y -1 en caso de error.
	 */
	int esNumerica(char* cadena, int limite)
	{
		int retorno = -1; // ERROR
		int i;
		if(cadena != NULL && limite > 0)
		{
			retorno = 1; // VERDADERO
			for(i=0;i<limite && cadena[i] != '\0';i++)
			{
				if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
				{
					continue;
				}
				if(cadena[i] < '0'||cadena[i] > '9')
				{
					retorno = 0;
					break;
				}
				//CONTINUE
			}
			//BREAK
		}
		return retorno;
	}


	/**
	 * \brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado.
	 * \param pResultado int* Puntero al espacio de memoria donde se dejara el resultado de la funcion.
	 * \param mensaje char* Es el mensaje a ser mostrado.
	 * \param mensajeError char* Es el mensaje de Error a ser mostrado.
	 * \param minimo int Es el numero maximo a ser aceptado.
	 * \param maximo int Es el minimo minimo a ser aceptado.
	 * \return int Retorna 0 si se obtuvo el numero y -1 si no.
	 */
	int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
	{
		int retorno = -1;
		int bufferInt;
		do
		{
			printf("%s",mensaje);
			if(	getInt(&bufferInt) == 0 &&
				bufferInt >= minimo &&
				bufferInt <= maximo)
			{
				retorno = 0;
				*pResultado = bufferInt;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;
		}while(reintentos>=0);

		return retorno;
	}


	/**
	 * \brief Verifica si la cadena ingresada es flotante.
	 * \param pResultado float* Puntero al espacio de memoria donde se dejara el resultado de la funcion.
	 * \return int Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no.
	 */
	static int getFloat(float* pResultado)
	{
		int retorno=-1;
		char buffer[64];

		if(pResultado != NULL)
		{
			if(getString(buffer,sizeof(buffer))==0 && esFlotante(buffer))
			{
				*pResultado = atof(buffer);
				retorno = 0;
			}
		}
		return retorno;
	}


	/**
	 * \brief Verifica si la cadena ingresada es flotante.
	 * \param cadena char* Cadena de caracteres a ser analizada.
	 * \return int Retorna 1 (vardadero) si la cadena es flotante y 0 (falso) si no lo es.
	 */
	int esFlotante(char* cadena)
	{
		int i=0;
		int retorno = 1;
		int contadorPuntos=0;

		if(cadena != NULL && strlen(cadena) > 0)
		{
			for(i=0 ; cadena[i] != '\0'; i++)
			{
				if(i==0 && (cadena[i] == '-' || cadena[i] == '+'))
				{
					continue;
				}
				if(cadena[i] < '0' || cadena[i] > '9' )
				{
					if(cadena[i] == '.' && contadorPuntos == 0)
					{
						contadorPuntos++;
					}
					else
					{
						retorno = 0;
						break;
					}
				}
			}
		}
		return retorno;
	}


	/**
	 * \brief Solicita un numero flotante al usuario, luego de verificarlo devuelve el resultado.
	 * \param pResultado float* Puntero al espacio de memoria donde se dejara el resultado de la funcion.
	 * \param mensaje char* Es el mensaje a ser mostrado.
	 * \param mensajeError char* Es el mensaje de Error a ser mostrado.
	 * \param minimo float Es el numero maximo a ser aceptado.
	 * \param maximo float Es el minimo minimo a ser aceptado.
	 * \param reintentos int Es la cantidad de reintentos de ingreso que tiene el usuario.
	 * \return int Retorna 0 si se obtuvo el numero flotante y -1 si no.
	 */
	int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
	{
		float bufferFloat;
		int retorno = -1;
		while(reintentos>=0)
		{
			reintentos--;
			printf("%s",mensaje);
			if(getFloat(&bufferFloat) == 0)
			{
				if(bufferFloat >= minimo && bufferFloat <= maximo)
				{
					*pResultado = bufferFloat;
					retorno = 0;
					break;
				}
			}
			printf("%s",mensajeError);
		}
		return retorno;
	}


	/**
	 * \brief Obtiene un string valido como nombre.
	 * \param pResultado char* Puntero al espacio de memoria donde se dejara el resultado de la funcion.
	 * \return int Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no.
	 */
	static int getNombre(char* pResultado, int longitud)
	{
		int retorno=-1;
		char buffer[4096];

		if(pResultado != NULL)
		{
			if(	getString(buffer,sizeof(buffer))==0 &&
				esNombre(buffer,sizeof(buffer)) &&
				strnlen(buffer,sizeof(buffer))<longitud)
			{
				strncpy(pResultado,buffer,longitud);
				retorno = 0;
			}
		}
		return retorno;
	}


	/**
	 * \brief Verifica si la cadena ingresada es un nombre valido.
	 * \param cadena char* Cadena de caracteres a ser analizada.
	 * \param longitud int Longitud de la cadena de caracteres a ser analizada.
	 * \return int Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es.
	 */
	int esNombre(char* cadena,int longitud)
	{
		int i=0;
		int retorno = 1;

		if(cadena != NULL && longitud > 0)
		{
			for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
			{
				if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
				{
					retorno = 0;
					break;
				}
			}
		}
		return retorno;
	}


	/**
	 * \brief Solicita un nombre al usuario, luego de verificarlo devuelve el resultado.
	 * \param pResultado char* Puntero al espacio de memoria donde se dejara el resultado de la funcion.
	 * \param longitud int Es la longitud del array resultado.
	 * \param mensaje char* Es el mensaje a ser mostrado.
	 * \param mensajeError char* Es el mensaje de Error a ser mostrado.
	 * \param reintentos int Cantidad de reintentos.
	 * \return int Retorna 0 si se obtuvo el numero flotante y -1 si no.
	 */
	int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
	{
		char bufferString[4096];
		int retorno = -1;
		while(reintentos>=0)
		{
			reintentos--;
			printf("%s",mensaje);
			if(getNombre(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
			{
				strncpy(pResultado,bufferString,longitud);
				retorno = 0;
				break;
			}
			printf("%s",mensajeError);
		}
		return retorno;
	}


	/**
	 * \brief Obtiene un string valido como descripcion.
	 * \param pResultado char* Puntero al espacio de memoria donde se dejara el resultado de la funcion.
	 * \param longitud int Es la longitud del array resultado.
	 * \return int Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no.
	 */
	static int getDescripcion(char* pResultado, int longitud)
	{
		int retorno=-1;
		char buffer[4096];

		if(pResultado != NULL)
		{
			if(	getString(buffer,sizeof(buffer))==0 &&
				esDescripcion(buffer,sizeof(buffer)) &&
				strnlen(buffer,sizeof(buffer))<longitud)
			{
				strncpy(pResultado,buffer,longitud);
				retorno = 0;
			}
		}
		return retorno;
	}


	/**
	 * \brief Verifica si la cadena ingresada es una descripcion valida.
	 * \param cadena Cadena de caracteres a ser analizada.
	 * \param longitud int Es la longitud de la cadena a ser analizada.
	 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es.
	 */
	int esDescripcion(char* cadena,int longitud)
	{
		int i=0;
		int retorno = 1;

		if(cadena != NULL && longitud > 0)
		{
			for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
			{
				if(cadena[i] != '.' && cadena[i] != ' ' && (cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ) && (cadena[i] < '0' || cadena[i] > '9' ) )
				{
					retorno = 0;
					break;
				}
			}
		}
		return retorno;
	}


	/**
	 * \brief Solicita una descripcion al usuario, luego de verificarlo devuelve el resultado.
	 * \param pResultado char* Puntero al espacio de memoria donde se dejara el resultado de la funcion.
	 * \param longitud int Es la longitud del array resultado.
	 * \param mensaje char* Es el mensaje a ser mostrado.
	 * \param mensajeError char* Es el mensaje de Error a ser mostrado.
	 * \param reintentos int Cantidad de reintentos.
	 * \return int Retorna 0 si se obtuvo el numero flotante y -1 si no.
	 */
	int utn_getDescripcion(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
	{
		char bufferString[4096];
		int retorno = -1;
		while(reintentos>=0)
		{
			reintentos--;
			printf("%s",mensaje);
			if(getDescripcion(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
			{
				strncpy(pResultado,bufferString,longitud);
				retorno = 0;
				break;
			}
			printf("%s",mensajeError);
		}
		return retorno;
	}


	/**
	 * \brief Obtiene un string valido como DNI.
	 * \param pResultado char* Puntero al espacio de memoria donde se dejara el resultado de la funcion.
	 * \return int Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no.
	 */
	static int getDni(char* pResultado, int longitud)
	{
		int retorno=-1;
		char buffer[4096];

		if(pResultado != NULL)
		{
			if(	getString(buffer,sizeof(buffer))==0 &&
				esNumerica(buffer,sizeof(buffer)) &&
				strnlen(buffer,sizeof(buffer))<longitud)
			{
				strncpy(pResultado,buffer,longitud);
				retorno = 0;
			}
		}
		return retorno;
	}


	/**
	 * \brief Solicita un DNI al usuario, luego de verificarlo devuelve el resultado.
	 * \param pResultado char* Puntero al espacio de memoria donde se dejara el resultado de la funcion.
	 * \param longitud int Es la longitud del array resultado.
	 * \param mensaje char* Es el mensaje a ser mostrado.
	 * \param mensajeError char* Es el mensaje de Error a ser mostrado.
	 * \param reintentos int Cantidad de reintentos.
	 * \return int Retorna 0 si se obtuvo el numero flotante y -1 si no.
	 */
	int utn_getDni(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
	{
		char bufferString[4096];
		int retorno = -1;
		while(reintentos>=0)
		{
			reintentos--;
			printf("%s",mensaje);
			if(getDni(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
			{
				strncpy(pResultado,bufferString,longitud);
				retorno = 0;
				break;
			}
			printf("%s",mensajeError);
		}
		return retorno;
	}

	//------------------------------------ VALIDACIONES ESPECIFICAS DEL STRUCT ----------------------------------//

	/**
	 * \brief Recibe un nombre como cadena y verifica si es o no un nombre valido.
	 * \param pCadenaAVerificar char* Es el nombre recibido.
	 * \param longitudCadenaAVerificar int Es la longitud del nombre.
	 * \return int Retorna 0 si el nombre es valido, si no un numero menor a 0.
	 */
	int esNombreValido (char* pCadenaAVerificar, int longitudCadenaAVerificar)
		{
			int retorno = -1;

			/*
			----CONDICIONES--------
			NO PUEDE EMPEZAR SIN UNA MAYUS.
			NO PUEDE NO HABER UNA MAYUS DESP DE UN ESPACIO EN EL NOMBRE. (COMENTADA ESTA CONDICION)
			NO PUEDE SER UN NOMBRE DE 1 LETRA (MINIMO 2).
			NO PUEDE SER UN NOMBRE DE 30 LETRAS (MAXIMO 29).
			NO PUEDE HABER OTRA COSA QUE LETRAS (MAYUS Y MINS) Y ESPACIOS.
			NO PUEDE HABER MAS DE 4 ESPACIOS EN EL NOMBRE.
			------------------------
			 */

			if (pCadenaAVerificar != NULL && longitudCadenaAVerificar > 0)
			{
				retorno = -2;

				int resultadoLongitudCadena;
				int flagErrorEnNombre = 0;
				int contadorEspacios = 0;

				resultadoLongitudCadena = strnlen(pCadenaAVerificar,longitudCadenaAVerificar);

				if (resultadoLongitudCadena < 1)
				{
					flagErrorEnNombre++;
				}

				if (resultadoLongitudCadena > 30)
				{
					flagErrorEnNombre++;
				}

				if (flagErrorEnNombre == 0)
				{
					retorno = -3;

					for (int j = 0 ; j < resultadoLongitudCadena ; j++)
					{
						if (pCadenaAVerificar[j] == '\n')
						{
							pCadenaAVerificar[j] = '\0';
							break;
						}
					}

					for (int i = 0 ; pCadenaAVerificar[i] != '\0' ; i++ )
						{
							if (flagErrorEnNombre > 0)
							{
								break;
							}

							if ( pCadenaAVerificar[i] == ' ')
							{
								contadorEspacios++;

								/*  //CONDICION DEL MAYUS OBLIGATORIO DESPUES DEL ESPACIO

									if (pCadenaAVerificar[i+1] < 'A' || pCadenaAVerificar[i+1] > 'Z')
									{
										flagErrorEnNombre++;
									}
								*/
							}


							if ( pCadenaAVerificar[i] < 'A' || pCadenaAVerificar[i] > 'z' || pCadenaAVerificar[i] == '[' || pCadenaAVerificar[i] == ']' || pCadenaAVerificar[i] == 92 || pCadenaAVerificar[i] == '^' || pCadenaAVerificar[i] == '_' || pCadenaAVerificar[i] == '`')
							{
								if (pCadenaAVerificar[i] == ' ')
								{
									//Si es un guion, esta mal.
								}
								else
								{
									flagErrorEnNombre++;
								}
							}

						}


					if ( pCadenaAVerificar[0] < 'A' || pCadenaAVerificar[0] > 'Z')
					{
						flagErrorEnNombre++;
					}


					if (contadorEspacios > 4)
					{
						flagErrorEnNombre++;
					}

				}

				if (flagErrorEnNombre != 0)
				{
					retorno = -4;
				}
				else
				{
					retorno = 0;
				}

			}

			return retorno;
		}


	/**
	 * \brief Recibe una cadena de caracteres que representa horas trabajadas.
	 * \param arrayHorasTrabajdas char* La cadena de horas trabajadas recibida.
	 * \param longitudArrayHorasTrabajadas La longitud de la cadena.
	 * \return int Retorna 0 si la cadena contiene realmente horas trabajadas validas, si no retorna un numero menor a 0.
	 */
	int esHoraTrabajadaValida (char* arrayHorasTrabajadas, int longitudArrayHorasTrabajadas)
	{
		int retorno = -1;

		/*
		----CONDICIONES----
		SOLO NUMEROS
		MINIMO 0 horas
		MAXIMO 9999 horas
		------------------
		*/

		if (arrayHorasTrabajadas != NULL && longitudArrayHorasTrabajadas > 0)
		{
			retorno = -2;
			int resultadoLongitudCadena;
			int flagErrorHorasTrabajadas = 0;

			resultadoLongitudCadena = strnlen(arrayHorasTrabajadas, longitudArrayHorasTrabajadas);

			if (resultadoLongitudCadena < 1)
			{
				flagErrorHorasTrabajadas++;
			}

			if (resultadoLongitudCadena > 7)
			{
				flagErrorHorasTrabajadas++;
			}

			if (flagErrorHorasTrabajadas == 0)
			{
				retorno = -3;

				for (int j = 0 ; j < resultadoLongitudCadena ; j++)
				{
					if (arrayHorasTrabajadas[j] == '\n')
					{
						arrayHorasTrabajadas[j] = '\0';
						break;
					}
				}

				for (int i = 0 ; arrayHorasTrabajadas[i] != '\0' ; i++ )
				{
					if (arrayHorasTrabajadas[i] < '0' || arrayHorasTrabajadas[i] > '9')
					{
						flagErrorHorasTrabajadas++;
					}
				}

				if (flagErrorHorasTrabajadas == 0)
				{
					int numeroIntDeHoras;
					numeroIntDeHoras = atoi (arrayHorasTrabajadas);

					if (numeroIntDeHoras < 0 || numeroIntDeHoras > 9999)
					{
						flagErrorHorasTrabajadas++;
					}
				}
			}

			if (flagErrorHorasTrabajadas != 0)
			{
				retorno = -4;
			}
			else
			{
				retorno = 0;
			}
		}

		return retorno;
	}


	/**
	 * \brief Recibe una cadena de caracteres que representa un sueldo.
	 * \param arraySueldoValido char* La cadena de sueldo recibida.
	 * \param longitudArraySueldoValido La longitud de la cadena.
	 * \return int Retorna 0 si la cadena contiene realmente un sueldo valido, si no retorna un numero menor a 0.
	 */
	int esSueldoValido (char* arraySueldoValido, int longitudArraySueldoValido)
	{
		int retorno = -1;

		/*
		----CONDICIONES----
		SOLO NUMEROS
		MINIMO 0 pesos de sueldo.
		MAXIMO 9.999.999 de sueldo
		------------------
		*/

		if (arraySueldoValido != NULL && longitudArraySueldoValido > 0)
		{
			retorno = -2;
			int resultadoLongitudCadena;
			int flagErrorSueldoValido = 0;

			resultadoLongitudCadena = strnlen(arraySueldoValido, longitudArraySueldoValido);

			if (resultadoLongitudCadena < 1)
			{
				flagErrorSueldoValido++;
			}

			if (resultadoLongitudCadena > 8)
			{
				flagErrorSueldoValido++;
			}

			if (flagErrorSueldoValido == 0)
			{
				retorno = -3;

				for (int j = 0 ; j < resultadoLongitudCadena ; j++)
				{
					if (arraySueldoValido[j] == '\n')
					{
						arraySueldoValido[j] = '\0';
						break;
					}
				}

				for (int i = 0 ; arraySueldoValido[i] != '\0' ; i++ )
				{
					if (arraySueldoValido[i] < '0' || arraySueldoValido[i] > '9')
					{
						flagErrorSueldoValido++;
					}
				}

				if (flagErrorSueldoValido == 0)
				{
					int numeroIntDeSueldo;
					numeroIntDeSueldo = atoi (arraySueldoValido);

					if (numeroIntDeSueldo < 0 || numeroIntDeSueldo > 9999999)
					{
						flagErrorSueldoValido++;
					}
				}
			}

			if (flagErrorSueldoValido != 0)
			{
				retorno = -4;
			}
			else
			{
				retorno = 0;
			}
		}

		return retorno;
	}


	/**
	 * \brief Recibe una cadena de caracteres que representa un id.
	 * \param arrayId char* La cadena de Id recibida.
	 * \param longitudArrayId La longitud de la cadena.
	 * \return int Retorna 0 si la cadena contiene realmente un id valido, si no retorna un numero menor a 0.
	 */
	int esIdValido (char* arrayId, int longitudArrayId)
	{
		int retorno = -1;

		/*
		----CONDICIONES----
		SOLO NUMEROS
		NO EXISTE UN ID MENOR A 1 NI MAYOR A 999.999
		------------------
		*/

		if (arrayId != NULL && longitudArrayId > 0)
		{
			retorno = -2;
			int resultadoLongitudCadena;
			int flagErrorId = 0;

			resultadoLongitudCadena = strnlen(arrayId, longitudArrayId);

			if (resultadoLongitudCadena < 1)
			{
				flagErrorId++;
			}

			if (resultadoLongitudCadena > 7)
			{
				flagErrorId++;
			}

			if (flagErrorId == 0)
			{
				retorno = -3;

				for (int j = 0 ; j < resultadoLongitudCadena ; j++)
				{
					if (arrayId[j] == '\n')
					{
						arrayId[j] = '\0';
						break;
					}
				}

				for (int i = 0 ; arrayId[i] != '\0' ; i++ )
				{
					if (arrayId[i] < '0' || arrayId[i] > '9')
					{
						flagErrorId++;
					}
				}

				if (flagErrorId == 0)
				{
					int numeroIntDeId;
					numeroIntDeId = atoi (arrayId);

					if (numeroIntDeId <= 0 || numeroIntDeId > 999999)
					{
						flagErrorId++;
					}
				}
			}

			if (flagErrorId != 0)
			{
				retorno = -4;
			}
			else
			{
				retorno = 0;
			}
		}

		return retorno;
	}


	/**
	 * \brief Recibe un valor int representativo a un id, verifica si es valido o no.
	 * \param id int El valor id recibido.
	 * \return int Retorna 0 si es un valor de id valido, si no retorna un numero menor a 0.
	 */
	int esIdValidoInt (int id)
	{
		int retorno = -1;

		if (id > 0 && id < 999999)
		{
			retorno = 0;
		}

		return retorno;
	}


	/**
	 * \brief Recibe un valor int representativo a un sueldo, verifica si es valido o no.
	 * \param sueldo int El valor del sueldo recibido.
	 * \return int Retorna 0 si es un valor de sueldo valido, si no retorna un numero menor a 0.
	 */
	int esSueldoValidoInt (int sueldo)
	{
		int retorno = -1;

		if (sueldo > 3)
		{
			retorno = 0;
		}

		return retorno;
	}


	/**
	 * \brief Recibe un valor int representativo a horas trabajadas, verifica si es valido o no.
	 * \param horasTrabajdas int El valor de horas trabajdas recibido.
	 * \return int Retorna 0 si es un valor de horas trabajadas valido, si no retorna un numero menor a 0.
	 */
	int esHoraTrabajadaValidaInt (int horasTrabajadas)
	{
		int retorno = -1;

		if (horasTrabajadas >= 0 && horasTrabajadas < 9000)
		{
			retorno = 0;
		}

		return retorno;
	}


	/**
	 * \brief Obtiene una orden de SI - NO.
	 * \param mensajePedido char* Recibe un mensaje para mostrar antes del pedido de la orden.
	 * \param mensajeError char* Recibe un mensaje para mostrar si hubo un error en el ingreso del pedido de la orden.
	 * \param reintentos int El valor reintentos de ingreso de la orden recibido.
	 * \return int Retorna 1 si la orden es SI, Retorna 0 si la orden es NO, si sale mal el pedido retorna un numero menor a 0.
	 */
	int utn_obtener_orden_si_no (char* mensajePedido, char* mensajeError, int reintentos)
	 {
		int retorno = -1;

		if ( mensajePedido != NULL && mensajeError != NULL && reintentos >= 0)
		{
			char buffer[70];
			retorno = -2;
			int resultadoDelBuffer;
			int flagErrorEnOrden;

			do
			{
				flagErrorEnOrden = 0;
				printf ("%s",mensajePedido);
				fflush(stdin);
				fgets (buffer,70,stdin);

				resultadoDelBuffer = strnlen(buffer,70);

				if (resultadoDelBuffer < 3)
				{
					flagErrorEnOrden++;
				}

				if (resultadoDelBuffer > 4)
				{
					flagErrorEnOrden++;
				}

				for (int j = 0 ; j < resultadoDelBuffer ; j++)
				{
					if (buffer[j] == '\n')
					{
						buffer[j] = '\0';
						break;
					}
				}

				for (int i = 0 ; buffer[i] != '\0' ; i++ )
					{
						if (flagErrorEnOrden > 0)
						{
							break;
						}

						if (buffer[i] != 'S' && buffer[i] != 'I' && buffer[i] != 'N' && buffer[i] != 'O')
						{
							flagErrorEnOrden++;
						}

					}

				if (buffer[0] == 'N' && buffer[1] != 'O')
				{
					flagErrorEnOrden++;
				}

				if (buffer[0] == 'S' && buffer[1] != 'I')
				{
					flagErrorEnOrden++;
				}

				if ( flagErrorEnOrden > 0)
				{
					printf ("%s \n",mensajeError);
					//printf ("La cantidad de errores en el flagNombre es de : %i \n", flagErrorEnNombre);
					reintentos--;
					retorno = -3;
				}
				else
				{
					if (buffer[0] == 'N')
					{
						retorno = 0;
					}
					else if (buffer[0] == 'S')
					{
						retorno = 1;
					}

					reintentos = -1;
				}

			}while (reintentos >= 0);
		}

		return retorno;
	}
