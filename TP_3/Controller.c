
	#include <stdio.h>
	#include <stdlib.h>
	#include "LinkedList.h"
	#include "Employee.h"
	#include "parser.h"
	#include "utn.h"



	int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
	{
		int retorno = -1;

		if (path != NULL && pArrayListEmployee != NULL)
		{
			FILE* filePuntero;

			filePuntero = fopen (path,"r");

			if (filePuntero != NULL)
			{
				int resultadoParser;
				printf("\nArchivo abierto correctamente.\n");

				resultadoParser = parser_EmployeeFromText(filePuntero,pArrayListEmployee);

				//Salga como salga el load en el parser, cierro el archivo.
				fclose(filePuntero);

				if (resultadoParser == 0)
				{
					retorno = 0;
				}

			}
			else
			{
				retorno = -2;
				printf ("\nError en la apertura del archivo.\n");
			}
		}

		return retorno;
	}



	int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
	{
		int retorno = -1;

		if (path != NULL && pArrayListEmployee)
		{
			FILE* filePuntero;
			int resultadoParser;

			filePuntero = fopen (path,"rb");

			if (filePuntero != NULL)
			{
				printf("\nArchivo abierto correctamente.\n");

				resultadoParser = parser_EmployeeFromBinary(filePuntero,pArrayListEmployee);

				//Salga como salga el load en el parser, cierro el archivo.
				fclose(filePuntero);

				if (resultadoParser == 0)
				{
					retorno = 0;
				}

			}
			else
			{
				retorno = -2;
				printf ("\nError en la apertura del archivo.\n");
			}
		}

		return retorno;
	}



	int controller_addEmployee(LinkedList* pArrayListEmployee, int valorMaximoExistenteID)
	{
		int retorno = -1;

		if (pArrayListEmployee != NULL && valorMaximoExistenteID > 0 && valorMaximoExistenteID < 999999)
		{
			retorno = -2;

			//Pido memoria para un nuevo empleado.
			Employee* pNewEmpleado;
			pNewEmpleado = employee_new();

			//Si hubo lugar y se obtuvo un puntero, sigo.
			if (pNewEmpleado != NULL)
			{
				char nombreEmpleado[CHARACTERS_LEN];
				int horasTrabajadasEmpleado;
				int sueldoEmpleado;

				int resultadoObtencionDeDatos;
				resultadoObtencionDeDatos =	getAllFieldsFromConsoleValidated (nombreEmpleado, &horasTrabajadasEmpleado, &sueldoEmpleado);

				//Si la obtencion salio bien y fueron todos los campos validos. Ya fueron cargados a los que pase por parametros.
				if (resultadoObtencionDeDatos == 0)
				{
					//Incremento el valor que obtuve del maximo id para la creacion de uno irrepetible.
					int valorNuevoId = valorMaximoExistenteID;
					valorNuevoId++;

					//Queda traspasar los datos al puntero pedido.
					employee_setNombre(pNewEmpleado,nombreEmpleado);
					employee_setHorasTrabajadas(pNewEmpleado,horasTrabajadasEmpleado);
					employee_setSueldo(pNewEmpleado,sueldoEmpleado);
					employee_setId (pNewEmpleado,valorNuevoId);

					//Añado a la ll el nuevo puntero a empleado.
					ll_add(pArrayListEmployee, pNewEmpleado);

					retorno = 0;
				}
				else
				{
					//Borro la memoria pedida si salio mal el pedido de datos.
					retorno = -4;
					employee_delete (pNewEmpleado);
					printf ("\nEl cliente no ha sido de alta debido a errores en la obtencion de datos.\n");
				}
			}
			else
			{
				retorno = -3;
				printf ("\nNo hay mas lugar en memoria para dar de alta un nuevo empleado.\n");
			}
		}

		return retorno;
	}



	int controller_editEmployee(LinkedList* pArrayListEmployee)
	{
		int retorno = -1;

		if (pArrayListEmployee != NULL)
		{
			retorno = -2;

			//Obtengo una id razonable que se desea modificar.
			int idIngresada;
			int obtencionId;
			int verificacionExistenciaId = -1;

			obtencionId = utn_getNumero (&idIngresada,"Ingrese el id que desea modificar.\n","Error en el ingreso de la id.\n",0,9999999,3);

			if (obtencionId == 0)
			{
				//La valido dentro de la lista de empleados.
				//Recorro ll. Obteniendo el puntero al elemento e ingresando al elemento.id y verificando si existe.

				Employee* pElementoObtenido;

				for (int i = 0 ; i < ll_len(pArrayListEmployee) ; i++)
				{
					pElementoObtenido = ll_get(pArrayListEmployee,i);

					if (pElementoObtenido->id == idIngresada && pElementoObtenido != NULL)
					{
						//Encontre que el id existe.
						verificacionExistenciaId = i;
						break;
					}
				}

				if (verificacionExistenciaId >= 0)
				{
					//El cliente existe, le mostramos al usuario a quien va a modificar a continuacion.
					printf ("\nUsted va a modificar a continuacion el siguiente cliente:\n");
					printEmployee (pElementoObtenido);

					Employee empleadoAux;

					//Pido los nuevos datos.
					int resultadoObtencionDeDatos;
					resultadoObtencionDeDatos =	getAllFieldsFromConsoleValidated (empleadoAux.nombre,&empleadoAux.horasTrabajadas,&empleadoAux.sueldo);
					empleadoAux.id = idIngresada;

					//Si son validos y su obtencion fue exitosa los reemplazo.
					if (resultadoObtencionDeDatos == 0)
					{
						//Reemplazo los datos viejos por los nuevos datos.
						*pElementoObtenido = empleadoAux;
						printf ("\nLa modificacion del cliente ha sido exitosa.\n");
						retorno = 0;
					}
					else
					{
						printf ("\nError en la modificacion del empleado. El ingreso de datos no ha salido bien.\n");
						retorno = -4;
					}
				}
				else
				{
					printf ("\nNo se pudo encontrar a un cliente con esa Id.\n");
					retorno = -3;
				}
			}

		}

		return retorno;
	}



	int controller_removeEmployee(LinkedList* pArrayListEmployee)
	{
		int retorno = -1;

		if (pArrayListEmployee != NULL)
		{
			retorno = -2;

			//Obtengo una id razonable que se desea eliminar.
			int idIngresada;
			int obtencionId;
			int verificacionExistenciaId = -1;

			obtencionId = utn_getNumero (&idIngresada,"Ingrese el id que desea eliminar.\n","Error en el ingreso de la id.\n",0,9999999,3);

			if (obtencionId == 0)
			{
				//La valido dentro de la lista de empleados.
				//Recorro ll. Obteniendo el puntero al elemento e ingresando al elemento.id y verificando si existe.

				Employee* pElementoObtenido;

				for (int i = 0 ; i < ll_len(pArrayListEmployee) ; i++)
				{
					pElementoObtenido = ll_get(pArrayListEmployee,i);

					if (pElementoObtenido->id == idIngresada && pElementoObtenido != NULL)
					{
						//Encontre que el id existe en el indice i.
						verificacionExistenciaId = i;
						break;
					}
				}

				if (verificacionExistenciaId >= 0)
				{
					//El cliente existe, le mostramos al usuario a quien va a eliminar a continuacion.
					printf ("\nUsted va a eliminar a continuacion el siguiente cliente:\n");
					printEmployee (pElementoObtenido);

					//Obtengo una confirmacion del borrado.
					int resultadoOrden;
					resultadoOrden = utn_obtener_orden_si_no ("Ingrese 'SI' o 'NO' para confirmar si es el cliente que desea eliminar\n","Error en el ingreso de su confirmacion. Ingrese SI o NO.\n",3);

					if (resultadoOrden == 1)
					{
						//Lo borro
						employee_delete(pElementoObtenido);
						ll_remove (pArrayListEmployee,verificacionExistenciaId);

						printf ("\nEl cliente ha sido eliminado satisfactoriamente.\n");
						retorno = 0;
					}
					else if (resultadoOrden == 0)
					{
						//Cancelo la eliminacion
						printf ("\nLa eliminacion del cliente ha sido cancelada.\n");
						retorno = -4;
					}
					else
					{
						//Cancelo la eliminacion
						printf ("\nNo se ha podido obtener una orden valida. Vuelva a ingresar a la opcion de eliminar y recuerde ingresar SI o NO\n");
						retorno = -3;
					}
				}
				else
				{
					printf ("\nNo se pudo encontrar a un cliente con esa Id.\n");
					retorno = -5;
				}
			}
		}

		return retorno;
	}



	int controller_ListEmployee(LinkedList* pArrayListEmployee)
	{
		int retorno = -1;

		if (pArrayListEmployee != NULL)
		{
			retorno = -2;

			Node* nodo;
			nodo = pArrayListEmployee->pFirstNode;

			for (int i = 0 ; i < pArrayListEmployee->size ; i++)
			{
				if (nodo->pElement != NULL)
				{
					printEmployee (nodo->pElement);
				}

				nodo = nodo->pNextNode;
			}
		}

		return retorno;
	}


	int controller_sortEmployee(LinkedList* pArrayListEmployee)
	{
		int retorno = -1;

		if (pArrayListEmployee != NULL)
		{
			//Ordeno la lista clonada
			ll_sort(pArrayListEmployee, employeeFuncionCriterio, 0);

			printf ("\nEl ordenamiento de su lista ha sido satisfactorio.\n");

			//Imprimo a ver que onda
			//controller_ListEmployee(pArrayListEmployee);

			retorno = 0;
		}

		return retorno;
	}



	int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
	{
		int retorno = -1;

		if (path != NULL && pArrayListEmployee)
		{
			retorno = -3;
			FILE* filePuntero;

			filePuntero = fopen (path,"w");

			if (filePuntero != NULL)
			{
				int cantEmpleadosEscritos = 0;
				printf("\nArchivo abierto correctamente.\n");

				//ACA EMPIEZA P
				Employee* pEmployee;

				int auxId;
				char auxNombre[CHARACTERS_LEN];
				int auxHorasTrabajadas;
				int auxSueldo;

				int resultadoObtencionValidacion;

				for (int i = 0 ; i < ll_len(pArrayListEmployee) ; i++)
				{

					pEmployee = ll_get(pArrayListEmployee, i);

					if (pEmployee != NULL)
					{

						resultadoObtencionValidacion = employee_getAll(pEmployee,&auxId,auxNombre,&auxHorasTrabajadas,&auxSueldo);

						if (resultadoObtencionValidacion == 0)
						{
							fprintf (filePuntero,"%d,%s,%d,%d\n",auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
							cantEmpleadosEscritos++;
						}
					}
				}
				//ACA TERMINA P

				//Salga como salga el save en el parser, cierro el archivo.
				fclose(filePuntero);


				if (cantEmpleadosEscritos > 0)
				{
					printf ("\nSe guardaron %d empleados.\n",cantEmpleadosEscritos);
					retorno = 0;
				}
				else
				{
					printf ("\nSe guardo una cantidad nula de empleados.\n");
					retorno = -4;
				}

			}
			else
			{
				retorno = -2;
				printf ("\nError en la apertura del archivo.\n");
			}
		}

		return retorno;
	}



	int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
	{
		int retorno = -1;

		if (path != NULL && pArrayListEmployee)
		{
			retorno = -3;
			FILE* filePuntero;

			filePuntero = fopen (path,"wb");

			if (filePuntero != NULL)
			{
				int cantEmpleadosEscritos = 0;
				printf("\nArchivo abierto correctamente.\n");

				//ACA EMPIEZA P
				Employee* pEmployee;

				int auxId;
				char auxNombre[CHARACTERS_LEN];
				int auxHorasTrabajadas;
				int auxSueldo;

				int resultadoObtencionValidacion;

				for (int i = 0 ; i < ll_len(pArrayListEmployee) ; i++)
				{

					pEmployee = ll_get(pArrayListEmployee, i);

					if (pEmployee != NULL)
					{
						resultadoObtencionValidacion = employee_getAll(pEmployee,&auxId,auxNombre,&auxHorasTrabajadas,&auxSueldo);

						if (resultadoObtencionValidacion == 0)
						{

							fwrite (pEmployee,sizeof(Employee),1,filePuntero);
							//Muevo el indicador al final del archivo para simular un \n
							fseek (filePuntero,0L,SEEK_END);
							cantEmpleadosEscritos++;
						}
					}
				}
				//ACA TERMINA P

				//Salga como salga el save en el parser, cierro el archivo.
				fclose(filePuntero);


				if (cantEmpleadosEscritos > 0)
				{
					printf ("\nSe guardaron %d empleados.\n",cantEmpleadosEscritos);
					retorno = 0;
				}
				else
				{
					printf ("\nSe guardo una cantidad nula de empleados.\n");
					retorno = -4;
				}


			}
			else
			{
				retorno = -2;
				printf ("\nError en la apertura del archivo.\n");
			}
		}

		return retorno;
	}


	int controller_findReplaceMaxId (LinkedList* pArrayListEmployee, int* idValorMinimoRecibido)
	{
		int retorno = -1;

		if (pArrayListEmployee != NULL && idValorMinimoRecibido != NULL)
		{
			retorno = -2;

			Employee* pEmpleado;
			Node* nodo;
			nodo = pArrayListEmployee->pFirstNode;

			int idMaximo = *idValorMinimoRecibido;

			for (int i = 0 ; i < pArrayListEmployee->size ; i++)
			{
				if (nodo->pElement != NULL)
				{
					pEmpleado = nodo->pElement;

					if (pEmpleado->id > idMaximo)
					{
						idMaximo = pEmpleado->id;
					}
				}

				nodo = nodo->pNextNode;
			}

			*idValorMinimoRecibido = idMaximo;
			retorno = 0;
		}

		return retorno;
	}



	int controller_finalActions (LinkedList* pArrayListEmployee)
	{
		int retorno = -1;

		if (pArrayListEmployee != NULL)
		{
			retorno = 0;

			//Despido.
			printDespedida ();

			//Limpio elementos y borro ll.
			ll_clear (pArrayListEmployee);
			ll_deleteLinkedList(pArrayListEmployee);
		}

		return retorno;
	}
