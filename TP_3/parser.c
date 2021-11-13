
	#include <stdio.h>
	#include <stdlib.h>
	#include "LinkedList.h"
	#include "Employee.h"


	/*
	 * \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
	 * \param pfile FILE* Puntero al archivo que se hace open.
	 * \param pArrayListEmployee LinkedList* Lista de empleados.
	 * \return int Retorna la cantidad de empledos cargados a la lista de empleados.
	 */
	int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
	{
		int retorno = -1;

		if (pFile != NULL && pArrayListEmployee != NULL)
		{
			retorno = -2;

			char auxNombre[CHARACTERS_LEN];
			char auxHorasTrabajadas[CHARACTERS_LEN];
			char auxSueldo[CHARACTERS_LEN];
			char auxId[CHARACTERS_LEN];

			int contadorEmpleadosReconocidos = 0;
			int resultadoFscanf;
			int resultadoDeLosSetters;

			Employee* pNewEmpleado;

			do
			{
				resultadoFscanf = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n,",auxId,auxNombre,auxHorasTrabajadas,auxSueldo);

				if(resultadoFscanf == 4)
				{
					//Obtengo nuevo empleado.
					pNewEmpleado = employee_new();

					resultadoDeLosSetters = employee_setAllTxt(pNewEmpleado,auxId,auxNombre,auxHorasTrabajadas,auxSueldo);

					//Valido si todos los setters salieron bien.
					if (resultadoDeLosSetters == 0)
					{
						//Si salen bien todos los setters creo un nuevo employee en la linkedList ya con la direccion de memoria donde estan los datos guardados
						ll_add(pArrayListEmployee, pNewEmpleado);
						contadorEmpleadosReconocidos++;
					}
					else //Si algun setter sale mal
					{
						//Borro la memoria pedida para ese empleado.
						employee_delete(pNewEmpleado);
						pNewEmpleado = NULL;
					}
				}

			}while (feof(pFile) == 0);

			if (contadorEmpleadosReconocidos > 0)
			{
				printf ("\nSe cargaron %d empleados.\n",contadorEmpleadosReconocidos);
				retorno = 0;
			}
			else
			{
				printf ("\nNo se pudo cargar ningun empleado.\n");
				retorno = -3;
			}

		}

		return retorno;
	}


	/*
	 * \brief Parsea los datos los datos de los empleados desde el archivo data.bin (modo binario).
	 * \param pfile FILE* Puntero al archivo que se hace open.
	 * \param pArrayListEmployee LinkedList* Lista de empleados.
	 * \return int Retorna 0 si la cantidad de empleados cargados es 1 o mas.
	 */
	int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
	{
		int retorno = -1;

		if (pFile != NULL && pArrayListEmployee != NULL)
		{
			retorno = -2;


			int contadorEmpleadosReconocidos = 0;
			int resultadoFread;
			int resultadoDeLosSetters;

			Employee* pNewEmpleado;
			Employee auxEmpleado;

			do
			{
				resultadoFread = fread (&auxEmpleado,sizeof(Employee),1,pFile);

				if(resultadoFread == 1)
				{
					//Obtengo nuevo empleado.
					pNewEmpleado = employee_new();

					resultadoDeLosSetters = employee_setAll(pNewEmpleado,auxEmpleado.id,auxEmpleado.nombre,auxEmpleado.horasTrabajadas,auxEmpleado.sueldo);
					//resultadoDeLosSetters = employee_setAllTxt(pNewEmpleado,auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
					//resultadoDeLosSetters = employee_setAll(pNewEmpleado,auxId,auxNombre,auxHorasTrabajadas,auxSueldo);

					//Valido si todos los setters salieron bien.
					if (resultadoDeLosSetters == 0)
					{
						//Si salen bien todos los setters creo un nuevo employee en la linkedList ya con la direccion de memoria donde estan los datos guardados
						ll_add(pArrayListEmployee, pNewEmpleado);
						contadorEmpleadosReconocidos++;
					}
					else //Si algun setter sale mal
					{
						//Borro la memoria pedida para ese empleado.
						employee_delete(pNewEmpleado);
						pNewEmpleado = NULL;
					}
				}

			}while (feof(pFile) == 0);

			if (contadorEmpleadosReconocidos > 0)
			{
				printf ("\nSe cargaron %d empleados.\n",contadorEmpleadosReconocidos);
				retorno = 0;
			}
			else
			{
				printf ("\nNo se pudo cargar ningun empleado.\n");
				retorno = -3;
			}

		}

		return retorno;
	}
